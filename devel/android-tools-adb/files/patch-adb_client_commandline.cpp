--- adb/client/commandline.cpp.orig	2019-10-18 00:22:21 UTC
+++ adb/client/commandline.cpp
@@ -59,7 +59,9 @@
 #include "bugreport.h"
 #include "client/file_sync_client.h"
 #include "commandline.h"
+#if defined(ENABLE_FASTDEPLOY)
 #include "fastdeploy.h"
+#endif
 #include "services.h"
 #include "shell_protocol.h"
 #include "sysdeps/chrono.h"
@@ -1012,7 +1014,11 @@ static int ppp(int argc, const char** argv) {
 
         // copy args
         const char** ppp_args = (const char**)alloca(sizeof(char*) * argc + 1);
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+        ppp_args[0] = "ppp";
+#else
         ppp_args[0] = "pppd";
+#endif
         for (i = 2 ; i < argc ; i++) {
             //argv[2] and beyond become ppp_args[1] and beyond
             ppp_args[i - 1] = argv[i];
@@ -1024,8 +1030,13 @@ static int ppp(int argc, const char** argv) {
         adb_close(STDERR_FILENO);
         adb_close(fd);
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+        execvp("ppp", (char* const*)ppp_args);
+        perror_exit("exec ppp failed");
+#else
         execvp("pppd", (char* const*)ppp_args);
         perror_exit("exec pppd failed");
+#endif
     }
 
     // parent side
