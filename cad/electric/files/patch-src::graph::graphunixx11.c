--- src/graph/graphunixx11.c.orig	Fri Jun 14 20:01:11 2002
+++ src/graph/graphunixx11.c	Thu Sep 19 23:30:14 2002
@@ -149,6 +149,8 @@
   INTBIG gra_initializetcl(void);
 #endif
 
+#include <sys/sysctl.h>
+
 /****** windows ******/
 
 #define WMLEFTBORDER    8						/* size of left border for windows */
@@ -2889,8 +2891,13 @@
 INTBIG enumprocessors(void)
 {
 	INTBIG numproc;
+	size_t proclen;
+ 
+	proclen = sizeof(numproc);
+	if ((sysctlbyname("hw.ncpu", &numproc, &proclen, NULL, 0) < 0) ||
+	   (proclen != sizeof(numproc)))
+		numproc = 1;
 
-	numproc = sysconf(_SC_NPROCESSORS_ONLN);
 	return(numproc);
 }
 
