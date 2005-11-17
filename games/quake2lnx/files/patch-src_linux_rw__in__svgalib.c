--- src/linux/rw_in_svgalib.c.orig	Wed Oct  9 03:54:25 2002
+++ src/linux/rw_in_svgalib.c	Mon Jun 16 23:00:10 2003
@@ -20,7 +20,9 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
@@ -145,26 +147,22 @@
 	// 84 to 86 not used
 	scantokey[ 87] = K_F11;
 	scantokey[ 88] = K_F12;
-	// 89 to 95 not used
-	scantokey[ 96] = K_KP_ENTER; //keypad enter
-	scantokey[ 97] = K_CTRL; //right
-	scantokey[ 98] = K_KP_SLASH;
-	scantokey[ 99] = K_F12; // print screen, bind to screenshot by default
-	scantokey[100] = K_ALT; // right
-
-	scantokey[101] = K_PAUSE; // break
-	scantokey[102] = K_HOME;
-	scantokey[103] = K_UPARROW;
-	scantokey[104] = K_PGUP;
-	scantokey[105] = K_LEFTARROW;
-	scantokey[106] = K_RIGHTARROW;
-	scantokey[107] = K_END;
-	scantokey[108] = K_DOWNARROW;
-	scantokey[109] = K_PGDN;
-	scantokey[110] = K_INS;
-	scantokey[111] = K_DEL;
-
-	scantokey[119] = K_PAUSE;
+	scantokey[ 89] = K_KP_ENTER; //keypad enter
+	scantokey[ 90] = K_CTRL; //right
+	scantokey[ 91] = K_KP_SLASH;
+	scantokey[ 92] = K_F12; // print screen, bind to screenshot by default
+	scantokey[ 93] = K_ALT; // right
+	scantokey[ 94] = K_HOME;
+	scantokey[ 95] = K_UPARROW;
+	scantokey[ 96] = K_PGUP;
+	scantokey[ 97] = K_LEFTARROW;
+	scantokey[ 98] = K_RIGHTARROW;
+	scantokey[ 99] = K_END;
+	scantokey[100] = K_DOWNARROW;
+	scantokey[101] = K_PGDN;
+	scantokey[102] = K_INS;
+	scantokey[103] = K_DEL;
+	scantokey[104] = K_PAUSE;
 
 	if (keyboard_init())
 		Sys_Error("keyboard_init() failed");
