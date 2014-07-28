--- src/keyboard/keyboard.c.orig	Sun Jul 18 09:41:15 1999
+++ src/keyboard/keyboard.c	Fri Sep  1 11:01:20 2000
@@ -28,12 +28,12 @@
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <termios.h>
-#include <linux/kd.h>
+#include <sys/kbio.h>
 /* linux/keyboard.h defines NR_KEYS and some scancode-like constants, so it */
 /* should also be useful for svgalib programs using the keyboard. It misses */
 /* a few KERNEL ifdefs around kernel data structures though. */
 #include <linux/keyboard.h>
-#include <sys/vt.h>
+#include <sys/consio.h>
 /* Needed to check uid of keymap files */
 #include <sys/stat.h>
 #include <unistd.h>
@@ -69,10 +69,11 @@
     "KP_4", "KP_5", "KP_6", "KP_Add",
     "KP_1", "KP_2", "KP_3",
     "KP_0", "KP_Period",
-    "Last_Console", "", "less", "F11", "F12", "", "", "", "", "", "", "",
-    "KP_Enter", "Control", "KP_Divide", "Control_backslash", "AltGr", "Break",
+    "Last_Console", "", "less", "F11", "F12",
+    "KP_Enter", "Control", "KP_Divide", "Control_backslash", "AltGr",
     "Find", "Up", "Prior", "Left", "Right", "Select", "Down", "Next", "Insert",
-    "Remove", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""
+    "Remove", "Break", "", "", "", "", "", "",
+    "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""
 };
 static void default_handler(int, int);
 static char *kbd_load_keymap(char *ptr);
@@ -333,14 +334,19 @@
     tcgetattr(__svgalib_kbd_fd, &oldkbdtermios);
     newkbdtermios = oldkbdtermios;
 
+    cfmakeraw(&newkbdtermios);
     newkbdtermios.c_lflag &= ~(ICANON | ECHO | ISIG);
-    newkbdtermios.c_iflag &= ~(ISTRIP | IGNCR | ICRNL | INLCR | IXOFF | IXON);
+    newkbdtermios.c_oflag = OPOST | ONLCR;
+    newkbdtermios.c_iflag = IGNPAR | IGNBRK;
+    newkbdtermios.c_cflag = CREAD | CS8;
     newkbdtermios.c_cc[VMIN] = 0;	/* Making these 0 seems to have the */
     newkbdtermios.c_cc[VTIME] = 0;	/* desired effect. */
+    cfsetispeed(&newkbdtermios, 9600);
+    cfsetospeed(&newkbdtermios, 9600);
 
-    tcsetattr(__svgalib_kbd_fd, TCSAFLUSH, &newkbdtermios);
+    tcsetattr(__svgalib_kbd_fd, TCSANOW, &newkbdtermios);
 
-    ioctl(__svgalib_kbd_fd, KDSKBMODE, K_MEDIUMRAW);
+    ioctl(__svgalib_kbd_fd, KDSKBMODE, K_CODE);
 
     keyboard_clearstate();
 
@@ -578,7 +584,7 @@
 	    /* VT switch. */
 	    /* *** what about F11 & F12? */
 	    int j, vt = 0;
-	    struct vt_stat vts;
+	    int vts;
 	    for (j = 0; j < 12; j++)
 		if (functionkey_state & (1 << j)) {
 		    vt = j + 1;
@@ -587,9 +593,9 @@
 		}
 
 	    /* Do not switch vt's if need not to */
-	    ioctl(__svgalib_tty_fd, VT_GETSTATE, &vts);
+	    ioctl(__svgalib_tty_fd, VT_GETACTIVE, &vts);
 
-	    if(vt != vts.v_active) { 
+	    if(vt != vts) { 
 	        /* if switching vt's, need to clear keystates */
 	        keyboard_clearstate();
 	        /*
