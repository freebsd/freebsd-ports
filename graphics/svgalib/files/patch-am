--- src/vga.c.orig	Thu Jul  6 19:10:32 2000
+++ src/vga.c	Fri Sep  1 18:30:27 2000
@@ -22,10 +22,10 @@
 #include <unistd.h>
 #include <stdarg.h>
 #include <sys/mman.h>
-#include <sys/kd.h>
+#include <sys/kbio.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
-#include <sys/vt.h>
+#include <sys/consio.h>
 #include <sys/wait.h>
 #include <errno.h>
 #include <ctype.h>
@@ -37,6 +37,22 @@
 #include "keyboard/vgakeyboard.h"
 #include "vgaregs.h"
 
+int permfd = -1;
+int ioperm(unsigned long from, unsigned long num, int on)
+{
+	if (permfd == -1)
+		permfd = open("/dev/io", O_RDONLY);
+	if (permfd != -1)
+		return 0;
+	else
+		return 1;
+}
+
+int iopl(int level)
+{
+	return ioperm(0, 0, 0);
+}
+
 #ifdef BACKGROUND
 #include "vgabg.h"
 
@@ -745,7 +761,7 @@
     /* Leave keyboard alone when rawkeyboard is enabled! */
     if (__svgalib_kbd_fd < 0) {
 	/* set graphics mode termio parameters */
-	ioctl(0, TCSETSW, &graph_termio);
+	ioctl(0, TIOCSETAW, &graph_termio);
     }
 }
 
@@ -755,7 +771,7 @@
     /* Leave keyboard alone when rawkeyboard is enabled! */
     if (__svgalib_kbd_fd < 0) {
 	/* restore text mode termio parameters */
-	ioctl(0, TCSETSW, &text_termio);
+	ioctl(0, TIOCSETAW, &text_termio);
     }
 }
 
@@ -766,9 +782,9 @@
 
     /* Well, one could argue that sigint is not enabled at all when in __svgalib_nosigint
        but sometimes they *still* are enabled b4 graph_termio is set.. */
-    ioctl(0, TCGETS, &cur_termio);
+    ioctl(0, TIOCGETA, &cur_termio);
     cur_termio.c_lflag &= ~ISIG;
-    ioctl(0, TCSETSW, &cur_termio);
+    ioctl(0, TIOCSETAW, &cur_termio);
 }
 
 
@@ -778,9 +794,9 @@
 
     if (__svgalib_nosigint) /* do not reenable, they are often reenabled by text_termio */
 	return; 
-    ioctl(0, TCGETS, &cur_termio);
+    ioctl(0, TIOCGETA, &cur_termio);
     cur_termio.c_lflag |= ISIG;
-    ioctl(0, TCSETSW, &cur_termio);
+    ioctl(0, TIOCSETAW, &cur_termio);
 }
 
 /* The following is rather messy and inelegant. The only solution I can */
@@ -851,7 +867,7 @@
     if (!getuid())
         return 1;               /* root can do it always */
 #endif
-    sprintf(fname, "/dev/tty%d", vc);
+    sprintf(fname, "/dev/ttyv%x", vc - 1);
     if ((stat(fname, &sbuf) >= 0) && (getuid() == sbuf.st_uid)) {
         return 1;
     }
@@ -862,7 +878,7 @@
 void __svgalib_open_devconsole(void)
 {
     struct vt_mode vtm;
-    struct vt_stat vts;
+    int vts;
     struct stat sbuf;
     char fname[30];
 
@@ -903,15 +919,15 @@
         goto error;
     if (svgalib_vc <= 0)
         goto error;
-    sprintf(fname, "/dev/tty%d", svgalib_vc);
+    sprintf(fname, "/dev/ttyv%x", svgalib_vc - 1);
     close(__svgalib_tty_fd);
     /* change our control terminal: */
     setpgid(0,getppid());
     setsid();
     /* We must use RDWR to allow for output... */
     if (((__svgalib_tty_fd = open(fname, O_RDWR)) >= 0) &&
-        (ioctl(__svgalib_tty_fd, VT_GETSTATE, &vts) >= 0)) {
-        if (!check_owner(vts.v_active))
+        (ioctl(__svgalib_tty_fd, VT_GETACTIVE, &vts) >= 0)) {
+        if (!check_owner(vts))
             goto error;
         /* success, redirect all stdios */
         if (DREP)
@@ -928,8 +944,8 @@
         /* clear screen and switch to it */
         fwrite("\e[H\e[J", 6, 1, stderr);
         fflush(stderr);
-        if (svgalib_vc != vts.v_active) {
-            startup_vc = vts.v_active;
+        if (svgalib_vc != vts) {
+            startup_vc = vts;
 	    ioctl(__svgalib_tty_fd, VT_ACTIVATE, svgalib_vc);
             __svgalib_waitvtactive();
 	}
@@ -1240,7 +1256,7 @@
  SIGTRAP, SIGIOT, SIGBUS, SIGFPE,
  SIGSEGV, SIGPIPE, SIGALRM, SIGTERM,
  SIGXCPU, SIGXFSZ, SIGVTALRM,
-/* SIGPROF ,*/ SIGPWR};
+/* SIGPROF ,*/ SIGUSR1};
 static struct sigaction old_signal_handler[sizeof(sig2catch)];
 
 struct vt_mode __svgalib_oldvtmode;
@@ -1822,15 +1838,15 @@
 #endif
 
     /* save text mode termio parameters */
-    ioctl(0, TCGETS, &text_termio);
+    ioctl(0, TIOCGETA, &text_termio);
 
     graph_termio = text_termio;
 
     /* change termio parameters to allow our own I/O processing */
-    graph_termio.c_iflag &= ~(BRKINT | PARMRK | INPCK | IUCLC | IXON | IXOFF);
+    graph_termio.c_iflag &= ~(BRKINT | PARMRK | INPCK | IXON | IXOFF);
     graph_termio.c_iflag |= (IGNBRK | IGNPAR);
 
-    graph_termio.c_oflag &= ~(ONOCR);
+/*    graph_termio.c_oflag &= ~(ONOCR);*/
 
     graph_termio.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | NOFLSH);
     if (__svgalib_nosigint)
@@ -3830,7 +3846,7 @@
 
 #define ML_GETINT(x) \
 	ptr = strtok(NULL, " "); if(!ptr) break; \
-	mmt.##x = atoi(ptr);
+	mmt.x = atoi(ptr);
 
 	    ML_GETINT(HDisplay);
 	    ML_GETINT(HSyncStart);
