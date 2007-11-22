--- common/cvsgui_process.cpp.orig	2007-11-22 20:25:42.000000000 +0100
+++ common/cvsgui_process.cpp	2007-11-22 20:26:39.000000000 +0100
@@ -899,7 +899,7 @@
     CvsProcessCallbacks *callbacks = sigtt_cvs_process->callbacks;
     // killing the cvs process avoids getting stuck in a SIGSTOP
     cvs_process_destroy (sigtt_cvs_process);
-    callbacks->consoleerr(SIGTT_ERR, strlen(SIGTT_ERR));
+    callbacks->consoleerr((char *)SIGTT_ERR, strlen(SIGTT_ERR));
   }
   sigtt_cvs_process = NULL;
 }
