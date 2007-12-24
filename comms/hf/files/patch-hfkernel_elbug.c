--- hfkernel/cw/elbug.c.orig	2007-12-24 09:30:07.000000000 -0500
+++ hfkernel/cw/elbug.c	2007-12-24 09:31:45.000000000 -0500
@@ -37,7 +37,9 @@
 #include <machine/cpufunc.h>
 #include <machine/sysarch.h>
 #include <sys/kbio.h>
+#ifdef __i386__
 #define IOPERM i386_set_ioperm
+#endif
 #else
 #include <sys/kd.h>		/* Linux, UnixWare */
 #endif
@@ -328,10 +330,15 @@
 	exit (0);
 	}
     }
+#ifdef IOPERM
     if ((err = IOPERM(port, 8, 1))) {
 	printf("permission problem for serial port %04x: ioperm = %d\n", port, err);
 	printf("This program has to be called with root permissions.\n");
     }
+#else
+	printf("No IOPERM non i386?\n");
+	exit(-1);
+#endif
     if ((fd_ptt = open(name_ptt, O_RDWR, 0)) < 0) {
 	printf("error in opening ptt device %s - maybe try another one?\n", 
 	    name_ptt);
