--- vm_dump.c.orig	2015-01-17 16:31:44.000000000 +0000
+++ vm_dump.c	2015-01-17 16:50:13.000000000 +0000
@@ -712,6 +712,7 @@
 }
 
 #ifdef __FreeBSD__
+#ifdef HAVE_LIBPROCSTAT
 #include <sys/user.h>
 #include <sys/sysctl.h>
 #include <sys/param.h>
@@ -794,6 +795,7 @@
 	free(freep);
 }
 #endif
+#endif
 
 #if defined __linux__
 # if defined __x86_64__ || defined __i386__
@@ -1034,6 +1036,7 @@
 	}
 #endif /* __linux__ */
 #ifdef __FreeBSD__
+#ifdef HAVE_LIBPROCSTAT
 # define MIB_KERN_PROC_PID_LEN 4
 	int mib[MIB_KERN_PROC_PID_LEN];
 	struct kinfo_proc kp;
@@ -1052,6 +1055,7 @@
 	    procstat_close(prstat);
 	    fprintf(stderr, "\n");
 	}
+#endif
 #endif /* __FreeBSD__ */
     }
 }
