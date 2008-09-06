--- plugins/org.eclipse.core.filesystem/natives/unix/freebsd/include/os_custom.h.orig	Sun Aug 19 23:58:06 2007
+++ plugins/org.eclipse.core.filesystem/natives/unix/freebsd/include/os_custom.h	Sun Aug 19 23:58:15 2007
@@ -11,8 +11,8 @@
 ***********************************************************************/
 
 /* Use this directive when introducing platform-specific code in localfile.c */
-#ifndef LINUX
-#define LINUX
+#ifndef FREEBSD
+#define FREEBSD
 #endif
 
 /* Linux supports reading symbolic links */
