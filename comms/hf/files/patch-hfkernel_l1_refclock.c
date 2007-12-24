--- hfkernel/l1/refclock.c.orig	2007-12-23 22:40:50.000000000 -0500
+++ hfkernel/l1/refclock.c	2007-12-23 22:41:42.000000000 -0500
@@ -225,7 +225,9 @@
 		    "So I use gettimeofday() as timing source, which has lowest accuracy.\n"
 		    "Let's hope you entered a good gettimeofday correction with -t %10.9f.\n", 
 		    tv_corr);
+#ifdef __i386__
 		rdtsc_ok=0;
+#endif
 	    }
 	}
 	return (lasttime = curtime);
