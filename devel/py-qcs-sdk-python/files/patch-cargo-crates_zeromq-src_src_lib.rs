--- cargo-crates/zeromq-src-0.2.6+4.3.4/src/lib.rs.orig	2006-07-24 03:21:28.000000000 +0200
+++ cargo-crates/zeromq-src-0.2.6+4.3.4/src/lib.rs	2023-11-22 10:53:08.374443000 +0100
@@ -415,6 +415,15 @@ impl Build {
             if target.contains("musl") {
                 has_strlcpy = true;
             }
+        } else if target.contains("freebsd") {
+            create_platform_hpp_shim(&mut build);
+            build.define("ZMQ_IOTHREAD_POLLER_USE_KQUEUE", "1");
+            build.define("ZMQ_POLL_BASED_ON_POLL", "1");
+            build.define("ZMQ_HAVE_IPC", "1");
+            build.define("HAVE_STRNLEN", "1");
+            build.define("ZMQ_HAVE_UIO", "1");
+            build.define("ZMQ_HAVE_IPC", "1");
+            has_strlcpy = true;
         } else if target.contains("apple") {
             create_platform_hpp_shim(&mut build);
             build.define("ZMQ_IOTHREAD_POLLER_USE_KQUEUE", "1");
