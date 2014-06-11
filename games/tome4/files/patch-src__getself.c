--- ./src/getself.c.orig	2014-05-19 04:42:14.000000000 -0400
+++ ./src/getself.c	2014-06-04 12:40:26.923307598 -0400
@@ -42,6 +42,8 @@
 #elif defined(SELFEXE_BSD)
 #include <limits.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 const char *get_self_executable(int argc, char **argv)
 {
 	static char res[PATH_MAX];
@@ -51,14 +53,12 @@
 	return res;
 }
 
-#import <sys/sysctl.h>
-
 int get_number_cpus()
 {
 	int count;
 	size_t size=sizeof(count);
 	
-	if (sysctlbyname("hw.ncpu",&count,&size,NULL,0)) return 1;
+	sysctlbyname("hw.ncpu",&count,&size,NULL,0);
 	return count;
 }
 
