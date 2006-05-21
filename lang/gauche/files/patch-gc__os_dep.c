--- ./gc/os_dep.c.orig	Sat Mar  4 12:55:44 2006
+++ ./gc/os_dep.c	Tue May  9 14:38:56 2006
@@ -694,7 +694,7 @@
     || defined(HURD) || defined(NETBSD)
 	static struct sigaction old_segv_act;
 #	if defined(IRIX5) || defined(HPUX) \
-	|| defined(HURD) || defined(NETBSD)
+	|| defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	    static struct sigaction old_bus_act;
 #	endif
 #   else
@@ -709,7 +709,7 @@
 #   endif
     {
 #	if defined(SUNOS5SIGS) || defined(IRIX5)  \
-        || defined(OSF1) || defined(HURD) || defined(NETBSD)
+        || defined(OSF1) || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 	  struct sigaction	act;
 
 	  act.sa_handler	= h;
@@ -731,7 +731,7 @@
 #	  else
 	        (void) sigaction(SIGSEGV, &act, &old_segv_act);
 #		if defined(IRIX5) \
-		   || defined(HPUX) || defined(HURD) || defined(NETBSD)
+		   || defined(HPUX) || defined(HURD) || defined(NETBSD) || defined(FREEBSD)
 		    /* Under Irix 5.x or HP/UX, we may get SIGBUS.	*/
 		    /* Pthreads doesn't exist under Irix 5.x, so we	*/
 		    /* don't have to worry in the threads case.		*/
