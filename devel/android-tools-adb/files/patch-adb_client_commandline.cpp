--- adb/client/commandline.cpp.orig	2019-07-17 19:54:09 UTC
+++ adb/client/commandline.cpp
@@ -1016,7 +1016,11 @@ static int ppp(int argc, const char** argv) {
 
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
@@ -1028,8 +1032,13 @@ static int ppp(int argc, const char** argv) {
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
