--- libselinux/src/init.c.orig	2015-06-15 21:40:06 UTC
+++ libselinux/src/init.c
@@ -7,10 +7,7 @@
 #include <stdio.h>
 #include <dlfcn.h>
 
-#ifdef DARWIN
-#include <sys/param.h>
-#include <sys/mount.h>
-#else
+#if defined(__linux__)
 #include <sys/vfs.h>
 #endif
 
@@ -26,6 +23,7 @@ int selinux_page_size = 0;
 
 static void init_selinuxmnt(void)
 {
+#if defined(__linux__)
 	char buf[BUFSIZ], *p;
 	FILE *fp=NULL;
 	struct statfs sfbuf;
@@ -94,6 +92,7 @@ static void init_selinuxmnt(void)
 	if (fp)
 		fclose(fp);
 	return;
+#endif
 }
 
 void fini_selinuxmnt(void)
