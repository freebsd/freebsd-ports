--- src/main.c.orig	Fri Feb  7 14:25:46 2003
+++ src/main.c	Fri Feb  7 14:34:14 2003
@@ -49,12 +49,21 @@
 	#include <mntent.h>
 #elif defined(__FreeBSD__) || defined(__bsd__) || defined (__NetBSD__)
 	#include <fstab.h>
+	#include <pthread.h>
 #elif defined(__sun__)
 	#include <sys/file.h>
 #endif
 
 #ifdef HAVE_DLOPEN
 # include <dlfcn.h>
+#endif
+
+/* This should probably go into configure
+ * BSDs and Linux have SIGIO, Solaris needs SIGPOLL
+ * This should probably be changed the other way round
+ * SIGIO as default and SIGPOLL only for Solrais */
+#ifndef SIGPOLL
+#define SIGPOLL SIGIO
 #endif
 
 #include "qcommon.h"
@@ -518,7 +527,7 @@
     ret = fread(ptr, size, nitems, fp);
     err = errno;
     if (ret != nitems) {
-	printf("verify_fread(...,%d,%d,...): return value: %d\n", size, nitems, ret);
+	printf("verify_fread(...,%lu,%lu,...): return value: %lu\n", (unsigned long)size, (unsigned long)nitems, (unsigned long)ret);
 	if (ret == 0 && ferror(fp)) {
 	    printf("   error: %s\n", strerror(err));
 	    printf("   fileno=%d\n", fileno(fp));
@@ -536,7 +545,7 @@
     ret = fwrite(ptr, size, nitems, fp);
     err = errno;
     if (ret != nitems) {
-	printf("verify_fwrite(...,%d,%d,...) = %d\n", size, nitems, ret);
+	printf("verify_fwrite(...,%lu,%lu,...) = %lu\n", (unsigned long)size, (unsigned long)nitems, (unsigned long)ret);
 	if (ret == 0 && ferror(fp)) {
 	    printf("   error: %s\n", strerror(err));
 	    printf("   fileno=%d\n", fileno(fp));
