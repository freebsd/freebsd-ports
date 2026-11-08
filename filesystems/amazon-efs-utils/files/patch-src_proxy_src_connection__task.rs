--- src/proxy/src/connection_task.rs.orig
+++ src/proxy/src/connection_task.rs
@@ -1,7 +1,10 @@
+use std::time::Duration;
+
 use log::{debug, trace};
 use tokio::{
     io::{split, AsyncWriteExt, ReadHalf, WriteHalf},
     sync::mpsc::{self},
+    time::timeout,
 };
 use tokio_util::sync::CancellationToken;
 
@@ -12,6 +15,8 @@ use crate::{
     shutdown::{ShutdownHandle, ShutdownReason},
 };
 
+const WRITE_SHUTDOWN_TIMEOUT: Duration = Duration::from_secs(5);
+
 pub struct ConnectionTask<S> {
     stream: S,
     proxy_receiver: mpsc::Receiver<RpcBatch>,
@@ -32,8 +37,6 @@ impl<S: ProxyStream> ConnectionTask<S> {
     ) {
         let (r, w) = split(self.stream);
 
-        let shutdown = shutdown_handle.clone();
-
         // This CancellationToken facilitates graceful TLS connection closures by ensuring that
         // that the ReadHalf is dropped only after the WriteHalf.shutdown() has returned
         let connection_cancellation_token = CancellationToken::new();
@@ -45,12 +48,7 @@ impl<S: ProxyStream> ConnectionTask<S> {
             shutdown_handle.clone(),
             connection_cancellation_token.clone(),
         );
-        tokio::spawn(async move {
-            tokio::select! {
-                _ = shutdown.cancellation_token.cancelled() => trace!("Cancelled"),
-                _ = writer => {},
-            }
-        });
+        tokio::spawn(writer);
 
         // ConnectionTask Reader reads messages from NFSServer's socket and sends to NFSClient Writer (ProxyTask writer)
         let reader = Self::run_reader(r, socket_reader, shutdown_handle.clone());
@@ -85,7 +83,17 @@ impl<S: ProxyStream> ConnectionTask<S> {
     ) {
         let mut reason = Option::None;
         loop {
-            let Some(batch) = receiver.recv().await else {
+            // Watch for cancellation here, not around this future: dropping it on
+            // cancellation would skip the cleanup below, and the reader task would
+            // keep the connection open until EFS closes it.
+            let batch = tokio::select! {
+                _ = shutdown.cancellation_token.cancelled() => {
+                    trace!("Cancelled");
+                    break;
+                }
+                batch = receiver.recv() => batch,
+            };
+            let Some(batch) = batch else {
                 debug!("sender dropped");
                 break;
             };
@@ -103,12 +111,78 @@ impl<S: ProxyStream> ConnectionTask<S> {
         }
 
         tokio::spawn(async move {
-            match server_write_half.shutdown().await {
-                Ok(_) => (),
-                Err(e) => debug!("Failed to gracefully shutdown connection: {}", e),
+            // Bounded: an unresponsive peer must not keep the reader alive.
+            match timeout(WRITE_SHUTDOWN_TIMEOUT, server_write_half.shutdown()).await {
+                Ok(Ok(_)) => (),
+                Ok(Err(e)) => debug!("Failed to gracefully shutdown connection: {}", e),
+                Err(_) => debug!("Timed out gracefully shutting down connection"),
             };
             connection_cancellation_token.cancel();
         });
         shutdown.exit(reason).await;
     }
 }
+
+#[cfg(test)]
+mod tests {
+    use std::time::Duration;
+
+    use async_trait::async_trait;
+    use tokio::{
+        io::{AsyncReadExt, AsyncWriteExt, DuplexStream, ReadHalf},
+        sync::mpsc,
+    };
+    use tokio_util::sync::CancellationToken;
+
+    use super::ConnectionTask;
+    use crate::{domain::ServerSocketReader, shutdown::ShutdownHandle};
+
+    // Server reader that only waits for EOF, like an idle EFS connection.
+    #[derive(Clone)]
+    struct IdleReader;
+
+    #[async_trait]
+    impl ServerSocketReader<DuplexStream> for IdleReader {
+        async fn run(&mut self, mut read_half: ReadHalf<DuplexStream>, _: ShutdownHandle) {
+            let mut buf = [0u8; 64];
+            while let Ok(n) = read_half.read(&mut buf).await {
+                if n == 0 {
+                    break;
+                }
+            }
+        }
+
+        fn get_domain(&self) -> &'static str {
+            "idle"
+        }
+    }
+
+    // A cancelled proxy incarnation must release its server connection even
+    // while the RPC sender is still alive and the server sends nothing.
+    #[tokio::test]
+    async fn cancellation_closes_server_connection() {
+        let (proxy_side, mut server_side) = tokio::io::duplex(64);
+        let (_sender, receiver) = mpsc::channel(1);
+        let (shutdown, _reasons) = ShutdownHandle::new(CancellationToken::new());
+
+        ConnectionTask::new(proxy_side, receiver)
+            .run(Box::new(IdleReader), shutdown.clone())
+            .await;
+        shutdown.cancellation_token.cancel();
+
+        // Writes fail only once both halves of the proxy side are dropped.
+        let closed = tokio::time::timeout(Duration::from_secs(10), async {
+            loop {
+                if server_side.write_all(b"x").await.is_err() {
+                    break;
+                }
+                tokio::time::sleep(Duration::from_millis(50)).await;
+            }
+        })
+        .await;
+        assert!(
+            closed.is_ok(),
+            "server connection still open after cancellation"
+        );
+    }
+}
