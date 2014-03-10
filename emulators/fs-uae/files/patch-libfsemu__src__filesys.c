--- ./libfsemu/src/filesys.c.orig	2014-03-10 19:32:45.000000000 -0300
+++ ./libfsemu/src/filesys.c	2014-03-10 19:33:00.000000000 -0300
@@ -128,7 +128,7 @@
 
 #if defined(WINDOWS)
 
-#elif defined(MACOSX)
+#elif defined(MACOSX) || defined(FreeBSD8)
 #define HAVE_STAT_TV_NSEC2
 #else
 #define HAVE_STAT_TV_NSEC
