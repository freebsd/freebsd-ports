http://pkgs.fedoraproject.org/cgit/rpms/openjfx.git/tree/0001-Fix-wait-call-in-PosixPlatform.patch

--- modules/fxpackager/src/main/native/library/common/PosixPlatform.cpp.orig	2017-09-08 16:56:55 UTC
+++ modules/fxpackager/src/main/native/library/common/PosixPlatform.cpp
@@ -230,13 +230,7 @@ bool PosixProcess::Wait() {
     int status = 0;
     pid_t wpid = 0;
 
-    //TODO Use waitpid instead of wait
-#ifdef LINUX
-    wait();
-#endif
-#ifdef MAC
     wpid = wait(&status);
-#endif
 
     if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
         if (errno != EINTR){
