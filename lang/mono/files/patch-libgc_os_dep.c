--- libgc/os_dep.c.orig	Sat Jun 12 17:10:31 2004
+++ libgc/os_dep.c	Sat Jun 12 17:12:42 2004
@@ -700,10 +700,10 @@
 #   endif
 
 #   if defined(SUNOS5SIGS) || defined(IRIX5) || defined(OSF1) \
-    || defined(HURD) || defined(NETBSD)
+    || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	static struct sigaction old_segv_act;
 #	if defined(_sigargs) /* !Irix6.x */ || defined(HPUX) \
-	|| defined(HURD) || defined(NETBSD)
+	|| defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	    static struct sigaction old_bus_act;
 #	endif
 #   else
@@ -718,7 +718,7 @@
 #   endif
     {
 #	if defined(SUNOS5SIGS) || defined(IRIX5)  \
-        || defined(OSF1) || defined(HURD) || defined(NETBSD)
+        || defined(OSF1) || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	  struct sigaction	act;
 
 	  act.sa_handler	= h;
@@ -738,7 +738,7 @@
 #	  else
 	        (void) sigaction(SIGSEGV, &act, &old_segv_act);
 #		if defined(IRIX5) && defined(_sigargs) /* Irix 5.x, not 6.x */ \
-		   || defined(HPUX) || defined(HURD) || defined(NETBSD)
+		   || defined(HPUX) || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 		    /* Under Irix 5.x or HP/UX, we may get SIGBUS.	*/
 		    /* Pthreads doesn't exist under Irix 5.x, so we	*/
 		    /* don't have to worry in the threads case.		*/
@@ -774,10 +774,10 @@
     void GC_reset_fault_handler()
     {
 #       if defined(SUNOS5SIGS) || defined(IRIX5) \
-	   || defined(OSF1) || defined(HURD) || defined(NETBSD)
+	   || defined(OSF1) || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	  (void) sigaction(SIGSEGV, &old_segv_act, 0);
 #	  if defined(IRIX5) && defined(_sigargs) /* Irix 5.x, not 6.x */ \
-	     || defined(HPUX) || defined(HURD) || defined(NETBSD)
+	     || defined(HPUX) || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	      (void) sigaction(SIGBUS, &old_bus_act, 0);
 #	  endif
 #       else
