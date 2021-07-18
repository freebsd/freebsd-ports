--- gdb/inflow.c.orig	2021-07-03 10:52:57.144161000 +0200
+++ gdb/inflow.c	2021-07-03 10:55:06.776399000 +0200
@@ -881,7 +881,10 @@
 pass_signal (int signo)
 {
 #ifndef _WIN32
-  kill (inferior_ptid.pid (), SIGINT);
+  if (inferior_ptid.pid () )
+    kill (inferior_ptid.pid (), SIGINT);
+  else
+    kill (current_inferior ()->pid, SIGINT);
 #endif
 }
 
