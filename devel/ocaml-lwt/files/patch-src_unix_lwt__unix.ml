$NetBSD: patch-src_unix_lwt_unix.ml,v 1.1 2013/11/01 10:50:03 jaapb Exp $

Patch (from upstream git) to compile with ocaml 4.01
--- src/unix/lwt_unix.ml.orig	2012-12-27 12:29:57.000000000 +0000
+++ src/unix/lwt_unix.ml
@@ -596,6 +596,9 @@ type open_flag =
 #if ocaml_version >= (3, 13)
   | O_SHARE_DELETE
 #endif
+#if ocaml_version >= (4, 01)
+  | O_CLOEXEC
+#endif
 
 #if windows
 
