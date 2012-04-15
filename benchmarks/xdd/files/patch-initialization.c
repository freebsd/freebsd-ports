--- initialization.c.orig	2012-02-09 19:46:52.785072682 -0800
+++ initialization.c	2012-02-15 21:58:34.759136156 -0800
@@ -181,11 +181,7 @@
 	fprintf(out, "Computer Name, %s, User Name, %s\n",name.nodename, getlogin());
 	fprintf(out, "OS release and version, %s %s %s\n",name.sysname, name.release, name.version);
 	fprintf(out, "Machine hardware type, %s\n",name.machine);
-#if (SOLARIS)
-	xgp->number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);
-	physical_pages = sysconf(_SC_PHYS_PAGES);
-	page_size = sysconf(_SC_PAGE_SIZE);
-#elif (AIX)
+#if (SOLARIS || AIX || FreeBSD)
 	xgp->number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);
 	physical_pages = sysconf(_SC_PHYS_PAGES);
 	page_size = sysconf(_SC_PAGE_SIZE);
@@ -628,7 +624,7 @@
 	 * NOTE: This is not supported by all operating systems. 
 	 */
 	if (p->target_options & RX_SHARED_MEMORY) {
-#if (AIX || LINUX || SOLARIS || OSX)
+#if (AIX || LINUX || SOLARIS || OSX || FreeBSD)
 		/* In AIX we need to get memory in a shared memory segment to avoid
 	     * the system continually trying to pin each page on every I/O operation */
 #if (AIX)
@@ -656,14 +652,14 @@
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
@@ -740,7 +736,7 @@
 	newlim = liret - (PAGESIZE*8);
 	return;
 #else
-#if  (LINUX || SOLARIS || HPUX || OSX || AIX)
+#if  (LINUX || SOLARIS || HPUX || OSX || AIX || FreeBSD)
 	if (getuid() != 0) {
 		fprintf(xgp->errout,"(PID %d) %s: You must run as superuser to lock memory for %s\n",
 			getpid(),xgp->progname, sp);
@@ -889,7 +885,7 @@
 #endif
 	return;
 #else
-#if (IRIX || SOLARIS || HPUX || LINUX || ALTIX || OSX)
+#if (IRIX || SOLARIS || HPUX || LINUX || ALTIX || OSX || FreeBSD)
 	if (getuid() != 0) {
 		return;
 	}
@@ -974,7 +970,7 @@
 	if (xgp->global_options & RX_NOPROCLOCK) 
                 return;
 #if !(OSX)
-#if (IRIX || SOLARIS || HPUX || AIX || LINUX || ALTIX || OSX)
+#if (IRIX || SOLARIS || HPUX || AIX || LINUX || ALTIX || OSX || FreeBSD)
 	if (getuid() != 0)
 		fprintf(xgp->errout,"%s: xdd_schedule_options: You must be super user to lock processes\n",xgp->progname);
 #endif 
@@ -985,7 +981,7 @@
 		perror("Reason");
 	}
 	if (xgp->global_options & RX_MAXPRI) {
-#if (IRIX || SOLARIS || HPUX || AIX || LINUX || ALTIX || OSX)
+#if (IRIX || SOLARIS || HPUX || AIX || LINUX || ALTIX || OSX || FreeBSD)
 		if (getuid() != 0) 
 			fprintf(xgp->errout,"%s: xdd_schedule_options: You must be super user to max priority\n",xgp->progname);
 #endif
@@ -1127,7 +1123,7 @@
 #endif
 #if (IRIX || SOLARIS || HPUX || AIX || ALTIX)
 	struct stat64 statbuf; /* buffer for file statistics */
-#elif ( LINUX || OSX )
+#elif ( LINUX || OSX || FreeBSD )
 	struct stat statbuf; /* buffer for file statistics */
 #endif
 	int32_t  i; /* working variable */
