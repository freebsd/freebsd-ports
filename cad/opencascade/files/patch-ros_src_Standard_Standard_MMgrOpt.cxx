--- ./ros/src/Standard/Standard_MMgrOpt.cxx.orig	Wed Mar 21 22:13:14 2007
+++ ./ros/src/Standard/Standard_MMgrOpt.cxx	Wed Mar 21 23:45:29 2007
@@ -258,7 +258,7 @@
       perror("ERR_MEMRY_FAIL");
 #endif
     
-#if defined(IRIX) || defined(__sgi) || defined(SOLARIS) || defined(__sun) || defined(LIN) || defined(linux)
+#if defined(IRIX) || defined(__sgi) || defined(SOLARIS) || defined(__sun) || defined(LIN) || defined(linux) || defined(__FreeBSD__)
     if ((myMMap = open ("/dev/zero", O_RDWR)) < 0) {
       if ((myMMap = open ("/dev/null", O_RDWR)) < 0){
         myMMap = 0;
