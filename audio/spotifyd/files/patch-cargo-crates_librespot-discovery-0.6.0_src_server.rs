--- cargo-crates/librespot-discovery-0.6.0/src/server.rs.orig	2025-03-14 17:41:29 UTC
+++ cargo-crates/librespot-discovery-0.6.0/src/server.rs
@@ -271,7 +271,7 @@
             SocketAddr::new(Ipv4Addr::UNSPECIFIED.into(), *port)
         } else {
             // this creates a dual stack socket on non-windows systems
-            SocketAddr::new(Ipv6Addr::UNSPECIFIED.into(), *port)
+            SocketAddr::new(Ipv4Addr::UNSPECIFIED.into(), *port)
         };
 
         let (close_tx, close_rx) = oneshot::channel();
