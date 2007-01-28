--- libstdc++-v3/crossconfig.m4.orig	Wed Jan 11 23:59:07 2006
+++ libstdc++-v3/crossconfig.m4	Sat Jan 27 19:40:59 2007
@@ -60,7 +60,7 @@
     GLIBCXX_CHECK_ICONV_SUPPORT
     GLIBCXX_CHECK_STDLIB_SUPPORT
     GLIBCXX_CHECK_S_ISREG_OR_S_IFREG
-    AC_DEFINE(HAVE_WRITEV)
+    #AC_DEFINE(HAVE_WRITEV)
     ;;
 
   *-freebsd*)
