--- iozone.c.orig       2010-12-21 14:15:01.000000000 +0800
+++ iozone.c    2010-12-21 14:15:16.000000000 +0800
@@ -70,7 +70,7 @@
 #include <Windows.h>
 int errno;
 #else
-#if defined(linux) || defined(solaris) || defined(macosx)
+#if defined(linux) || defined(solaris) || defined(macosx) || defined(FreeBSD)
 #include <errno.h>
 #else
 extern  int errno;   /* imported for errors */
