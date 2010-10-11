--- vm/environment.cpp.orig	2010-10-11 01:11:37.000000000 -0700
+++ vm/environment.cpp	2010-10-11 01:11:51.000000000 -0700
@@ -108,13 +108,12 @@
 
   static void null_func(int sig) {}
 
+#ifdef USE_EXECINFO
   static void safe_write(int fd, const char* str, int len=0) {
     if(!len) len = strlen(str);
     if(write(fd, str, len) == 0) exit(101);
   }
 
-#ifdef USE_EXECINFO
-
   static void write_sig(int fd, int sig) {
     switch(sig) {
     case SIGSEGV:
