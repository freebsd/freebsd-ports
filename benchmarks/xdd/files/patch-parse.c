--- parse.c.orig	2012-02-15 22:02:57.832134671 -0800
+++ parse.c	2012-02-15 22:02:57.878141191 -0800
@@ -810,7 +810,7 @@
 xddfunc_delay(int32_t argc, char *argv[])
 { 
 	xgp->passdelay = atoi(argv[1]);
-    return(1);
+    return(2);
 }
 /*----------------------------------------------------------------------------*/
 // Delete the target file when complete
@@ -1218,7 +1218,7 @@
 xddfunc_maxerrors(int32_t argc, char *argv[])
 {
 	xgp->max_errors = atoll(argv[1]);
-    return(1);
+    return(2);
 }
 /*----------------------------------------------------------------------------*/
 // Set the maximum runtime priority
@@ -1448,7 +1448,7 @@
 #if (LINUXUP || HPUX || OSX)
 	cpus = 1;
 	fprintf(xgp->errout,"%s: WARNING: Multiple processors not supported in this release\n",xgp->progname);
-#elif (SOLARIS || AIX)
+#elif (SOLARIS || AIX || FreeBSD)
 	/* SOLARIS or AIX */ 
 	cpus = sysconf(_SC_NPROCESSORS_ONLN);
 #elif (IRIX || WIN32)
@@ -1764,7 +1764,7 @@
 #if (LINUXUP || HPUX || OSX)
 	cpus = 1;
 	fprintf(xgp->errout,"%s: WARNING: Multiple processors not supported in this release\n",xgp->progname);
-#elif (SOLARIS || AIX)
+#elif (SOLARIS || AIX || FreeBSD)
 	/* SOLARIS or AIX */ 
 	cpus = sysconf(_SC_NPROCESSORS_ONLN);
 #elif (IRIX || WIN32)
@@ -2057,7 +2057,7 @@
 #if (LINUXUP || HPUX || OSX)
 	cpus = 1;
 	fprintf(xgp->errout,"%s: WARNING: Multiple processors not supported in this release\n",xgp->progname);
-#elif (SOLARIS || AIX)
+#elif (SOLARIS || AIX || FreeBSD)
 	/* SOLARIS or AIX */ 
 	cpus = sysconf(_SC_NPROCESSORS_ONLN);
 #elif (IRIX || WIN32)
