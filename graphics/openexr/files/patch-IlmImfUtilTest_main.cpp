--- IlmImfUtilTest/main.cpp.orig	2014-08-10 04:24:00 UTC
+++ IlmImfUtilTest/main.cpp
@@ -46,7 +46,7 @@
 #include <cstring>
 #include <time.h>
 
-#if defined(OPENEXR_IMF_HAVE_LINUX_PROCFS) || defined(OPENEXR_IMF_HAVE_DARWIN)
+#if defined(OPENEXR_IMF_HAVE_LINUX_PROCFS) || defined(OPENEXR_IMF_HAVE_DARWIN) || defined(__FreeBSD__)
     #include <unistd.h>
 #endif
 
