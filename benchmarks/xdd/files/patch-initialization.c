--- initialization.c.orig	Fri Mar 16 06:54:36 2007
+++ initialization.c	Fri Mar 16 06:56:05 2007
@@ -628,7 +628,7 @@
 	 * NOTE: This is not supported by all operating systems. 
 	 */
 	if (p->target_options & RX_SHARED_MEMORY) {
-#if (AIX || LINUX || SOLARIS || OSX)
+#if (AIX || LINUX || SOLARIS || OSX || FreeBSD)
 		/* In AIX we need to get memory in a shared memory segment to avoid
 	     * the system continually trying to pin each page on every I/O operation */
 #if (AIX)
@@ -656,14 +656,14 @@
 		fprintf(xgp->errout,"%s: Shared Memory not supported on this OS - using valloc\n",
 			xgp->progname);
 		p->target_options &= ~RX_SHARED_MEMORY;
-#if (IRIX || SOLARIS || HPUX || LINUX || AIX || ALTIX || OSX)
+#if (IRIX || SOLARIS || HPUX || LINUX || AIX || ALTIX || OSX || FreeBSD)
 		rwbuf = valloc(p->iosize);
 #else
 		rwbuf = malloc(p->iosize);
 #endif
 #endif 
 	} else { /* Allocate memory the normal way */
-#if (IRIX || SOLARIS || HPUX || LINUX || AIX || ALTIX || OSX)
+#if (IRIX || SOLARIS || HPUX || LINUX || AIX || ALTIX || OSX || FreeBSD)
 		rwbuf = valloc(p->iosize);
 #else
 		rwbuf = malloc(p->iosize);
@@ -740,7 +740,7 @@
 	newlim = liret - (PAGESIZE*8);
 	return;
 #else
-#if  (LINUX || SOLARIS || HPUX || OSX || AIX)
+#if  (LINUX || SOLARIS || HPUX || OSX || AIX || FreeBSD)
 	if (getuid() != 0) {
 		fprintf(xgp->errout,"(PID %d) %s: You must run as superuser to lock memory for %s\n",
 			getpid(),xgp->progname, sp);
@@ -889,7 +889,7 @@
 #endif
 	return;
 #else
-#if (IRIX || SOLARIS || HPUX || LINUX || ALTIX || OSX)
+#if (IRIX || SOLARIS || HPUX || LINUX || ALTIX || OSX || FreeBSD)
 	if (getuid() != 0) {
 		return;
 	}
@@ -974,7 +974,7 @@
 	if (xgp->global_options & RX_NOPROCLOCK) 
                 return;
 #if !(OSX)
-#if (IRIX || SOLARIS || HPUX || AIX || LINUX || ALTIX || OSX)
+#if (IRIX || SOLARIS || HPUX || AIX || LINUX || ALTIX || OSX || FreeBSD)
 	if (getuid() != 0)
 		fprintf(xgp->errout,"%s: xdd_schedule_options: You must be super user to lock processes\n",xgp->progname);
 #endif 
@@ -985,7 +985,7 @@
 		perror("Reason");
 	}
 	if (xgp->global_options & RX_MAXPRI) {
-#if (IRIX || SOLARIS || HPUX || AIX || LINUX || ALTIX || OSX)
+#if (IRIX || SOLARIS || HPUX || AIX || LINUX || ALTIX || OSX || FreeBSD)
 		if (getuid() != 0) 
 			fprintf(xgp->errout,"%s: xdd_schedule_options: You must be super user to max priority\n",xgp->progname);
 #endif
@@ -1127,7 +1127,7 @@
 #endif
 #if (IRIX || SOLARIS || HPUX || AIX || ALTIX)
 	struct stat64 statbuf; /* buffer for file statistics */
-#elif ( LINUX || OSX )
+#elif ( LINUX || OSX || FreeBSD )
 	struct stat statbuf; /* buffer for file statistics */
 #endif
 	int32_t  i; /* working variable */
