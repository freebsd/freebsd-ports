--- ./src/getself.c.orig	2014-01-05 19:42:37.000000000 -0500
+++ ./src/getself.c	2014-02-06 13:23:22.555164880 -0500
@@ -42,6 +42,8 @@
 #elif defined(SELFEXE_BSD)
 #include <limits.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 const char *get_self_executable(int argc, char **argv)
 {
 	static char res[PATH_MAX];
@@ -51,14 +53,13 @@
 	return res;
 }
 
-#import <sys/sysctl.h>
 
 int get_number_cpus()
 {
 	int count;
 	size_t size=sizeof(count);
 	
-	if (sysctlbyname("hw.ncpu",&count,&size,NULL,0)) return 1;
+	sysctlbyname("hw.ncpu",&count,&size,NULL,0);
 	return count;
 }
 
