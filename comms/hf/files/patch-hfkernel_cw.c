--- hfkernel/cw/cw.c.orig	2007-12-24 08:38:46.000000000 -0500
+++ hfkernel/cw/cw.c	2007-12-24 08:45:35.000000000 -0500
@@ -39,11 +39,21 @@
 #ifdef __linux__
 #include <sys/io.h>
 #define IOPERM ioperm
+#define TTY0    "/dev/ttyS0"
+#define TTY1    "/dev/ttyS1"
+#define TTY2    "/dev/ttyS2"
+#define TTY3    "/dev/ttyS3"
 #endif
 #ifdef __FreeBSD__ 
 #include <machine/cpufunc.h>
 #include <machine/sysarch.h>
-#define IOPERM i386_set_ioperm
+#define TTY0	"/dev/ttyd0"
+#define TTY1	"/dev/ttyd1"
+#define TTY2	"/dev/ttyd2"
+#define TTY3	"/dev/ttyd3"
+	#ifdef __i386__
+	#define IOPERM i386_set_ioperm
+	#endif
 #endif
 #include <sys/time.h>
 #include <time.h>
@@ -408,6 +418,7 @@
 
 void *mode_cw_tx(void *dummy)
 {
+#ifdef IOPERM
 	/* duration of 1 dot, i suppose a word has 50 dots */
 	/* ---> so i think 1 baud in cw is 50 * wpm / 60   */
 	int i = 0, err = 0, pausecount = 0, idlewait, status, cts, dcd;
@@ -416,16 +427,16 @@
 	printf("%s", cable);
 	
 	if (name_ptt) {
-	    if (! strcmp (name_ptt, "/dev/ttyS0")) {
+	    if (! strcmp (name_ptt, TTY0)) {
 		    port = 0x3F8;
 	    }
-	    if (! strcmp (name_ptt, "/dev/ttyS1")) {
+	    if (! strcmp (name_ptt, TTY1)) {
 		    port = 0x2F8;
 	    }
-	    if (! strcmp (name_ptt, "/dev/ttyS2")) {
+	    if (! strcmp (name_ptt, TTY2)) {
 		    port = 0x3E8;
 	    }
-	    if (! strcmp (name_ptt, "/dev/ttyS3")) {
+	    if (! strcmp (name_ptt, TTY3)) {
 		    port = 0x2E8;
 	    }
 	}
@@ -514,5 +525,8 @@
 			decode(PAUSE);
 		}
     	}
+#else
+	printf("Not on i386, elbug disabled\n");
+#endif
 }
 
