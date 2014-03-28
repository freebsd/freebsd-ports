$NetBSD: patch-ai,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/cutil/lm_channel.c.orig	2006-07-15 17:23:37.000000000 +0000
+++ src/libmojave-external/cutil/lm_channel.c
@@ -57,7 +57,7 @@ value omake_shell_peek_pipe(value v_fd)
                            &total,              // Total number of bytes available
                            NULL);               // Number of bytes in the next message
     if(status == 0)
-        failwith("Not a pipe");
+        caml_failwith("Not a pipe");
     return total ? Val_int(1) : Val_int(0);
 }
 
@@ -83,7 +83,7 @@ value omake_shell_pipe_kind(value v_fd)
 
 value omake_shell_peek_pipe(value v_fd)
 {
-    failwith("omake_shell_peek_pipe: not available on Unix systems");
+    caml_failwith("omake_shell_peek_pipe: not available on Unix systems");
     return Val_unit;
 }
 
