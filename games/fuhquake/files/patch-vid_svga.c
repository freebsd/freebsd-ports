--- vid_svgalib.c.orig	Thu Feb  5 00:41:00 2004
+++ vid_svgalib.c	Thu Feb  5 00:51:44 2004
@@ -20,12 +20,18 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
 
+#if defined(__linux__)
 #include <asm/io.h>
+#elif defined(__FreeBSD__)
+#include <machine/cpufunc.h>
+#endif
 
 #include "vga.h"
 #include "vgakeyboard.h"
@@ -92,7 +98,6 @@
 float	old_mouse_x, old_mouse_y;
 int		mx, my;
 
-cvar_t _windowed_mouse = {"_windowed_mouse", "1", CVAR_ARCHIVE};	//dummy for menu.c
 cvar_t	m_filter = {"m_filter","0"};
 cvar_t cl_keypad = {"cl_keypad", "1"};
 
@@ -307,45 +312,41 @@
 }
 
 static byte scantokey_kp[128] = {
-//  0       1        2       3       4       5       6       7
-//  8       9        A       B       C       D       E       F
-	0  ,   K_ESCAPE,'1',    '2',    '3',    '4',    '5',    '6',
-	'7',    '8',    '9',    '0',    '-',    '=',    K_BACKSPACE, 9,					// 0
-	'q',    'w',    'e',    'r',    't',    'y',    'u',    'i',
-	'o',    'p',    '[',    ']',    K_ENTER,K_LCTRL, 'a',    's',					// 1
-	'd',    'f',    'g',    'h',    'j',    'k',    'l',    ';',
-	'\'',   '`',    K_LSHIFT,'\\',   'z',    'x',    'c',    'v',					// 2
-	'b',    'n',    'm',    ',',    '.',    '/',    K_RSHIFT,KP_STAR,
-	K_LALT,  ' ',  K_CAPSLOCK,K_F1,  K_F2,   K_F3,   K_F4,   K_F5,					// 3
-	K_F6,   K_F7,   K_F8,   K_F9,   K_F10,  KP_NUMLOCK,K_SCRLCK,KP_HOME,
-	KP_UPARROW,KP_PGUP,KP_MINUS,KP_LEFTARROW,KP_5,KP_RIGHTARROW,KP_PLUS,KP_END,		// 4
-	KP_DOWNARROW,KP_PGDN,KP_INS,KP_DEL, 0,  0,      0,      K_F11,
-	K_F12,  0,      0,      0,      0,      0,      0,      0,						// 5
-	KP_ENTER,K_RCTRL,KP_SLASH,0, K_RALT,  K_PAUSE,K_HOME, K_UPARROW,
-	K_PGUP, K_LEFTARROW,K_RIGHTARROW,K_END, K_DOWNARROW,K_PGDN,K_INS,K_DEL,        // 6
-	0,      0,      0,      0,      0,      0,      0,      K_PAUSE,
-	0,      0,      0,      0,      0,      K_LWIN, K_RWIN, K_MENU					// 7
+	0,            K_ESCAPE,   '1',          '2',           '3',         '4',           '5',         '6',
+	'7',          '8',        '9',          '0',           '-',         '=',           K_BACKSPACE, 9,
+	'q',          'w',        'e',          'r',           't',         'y',           'u',         'i',
+	'o',          'p',        '[',          ']',           K_ENTER,     K_LCTRL,       'a',         's',
+	'd',          'f',        'g',          'h',           'j',         'k',           'l',         ';',
+	'\'',         '`',         K_LSHIFT,    '\\',          'z',         'x',           'c',         'v',
+	'b',          'n',         'm',         ',',           '.',         '/',           K_RSHIFT,    KP_STAR,
+	K_LALT,       ' ',         K_CAPSLOCK,   K_F1,         K_F2,        K_F3,          K_F4,        K_F5,
+	K_F6,         K_F7,        K_F8,         K_F9,         K_F10,       KP_NUMLOCK,    K_SCRLCK,    KP_HOME,
+	KP_UPARROW,   KP_PGUP,     KP_MINUS,     KP_LEFTARROW, KP_5,        KP_RIGHTARROW, KP_PLUS,     KP_END,
+	KP_DOWNARROW, KP_PGDN,     KP_INS,       KP_DEL,       0,           0,             0,           K_F11,
+	K_F12,        KP_ENTER,    K_RCTRL,      KP_SLASH,     K_PRINTSCR,  K_RALT,        K_HOME,      K_UPARROW,
+	K_PGUP,       K_LEFTARROW, K_RIGHTARROW, K_END,        K_DOWNARROW, K_PGDN,        K_INS,       K_DEL,
+	K_PAUSE,      K_LWIN,      K_RWIN,       K_MENU,       0,           0,             0,           0,
+	0,            0,           0,            0,            0,           0,             0,           0,
+	0,            0,           0,            0,            0,           0,             0,           0
 };
 
 static byte scantokey[128] = {
-//  0       1        2       3       4       5       6       7
-//  8       9        A       B       C       D       E       F
-	0  ,   K_ESCAPE,'1',    '2',    '3',    '4',    '5',    '6',
-	'7',    '8',    '9',    '0',    '-',    '=',    K_BACKSPACE, 9,   // 0
-	'q',    'w',    'e',    'r',    't',    'y',    'u',    'i',
-	'o',    'p',    '[',    ']',    K_ENTER,K_LCTRL, 'a',    's',      // 1
-	'd',    'f',    'g',    'h',    'j',    'k',    'l',    ';',
-	'\'',   '`',    K_LSHIFT,'\\',   'z',    'x',    'c',    'v',      // 2
-	'b',    'n',    'm',    ',',    '.',    '/',    K_RSHIFT,KP_STAR,
-	K_LALT,  ' ',  K_CAPSLOCK,K_F1,  K_F2,   K_F3,   K_F4,   K_F5,     // 3
-	K_F6,   K_F7,   K_F8,   K_F9,   K_F10,  KP_NUMLOCK,K_SCRLCK,K_HOME,
-	K_UPARROW,K_PGUP,'-',K_LEFTARROW,'5',K_RIGHTARROW,'+',    K_END, // 4
-	K_DOWNARROW,K_PGDN,K_INS,K_DEL, 0,      0,      0,      K_F11,
-	K_F12,  0,      0,      0,      0,      0,      0,      0,        // 5
-	K_ENTER,K_RCTRL,'/',     0, K_RALT,  K_PAUSE,K_HOME, K_UPARROW,
-	K_PGUP, K_LEFTARROW,K_RIGHTARROW,K_END, K_DOWNARROW,K_PGDN,K_INS,K_DEL,        // 6
-	0,      0,      0,      0,      0,      0,      0,      K_PAUSE,
-	0,      0,      0,      0,      0,      K_LWIN, K_RWIN, K_MENU			// 7
+	0,           K_ESCAPE,   '1',          '2',          '3',         '4',          '5',         '6',
+	'7',         '8',        '9',          '0',          '-',         '=',          K_BACKSPACE, 9,
+	'q',         'w',        'e',          'r',          't',         'y',          'u',         'i',
+	'o',         'p',        '[',          ']',          K_ENTER,     K_LCTRL,      'a',         's',
+	'd',         'f',        'g',          'h',          'j',         'k',          'l',         ';',
+	'\'',        '`',         K_LSHIFT,    '\\',         'z',         'x',          'c',         'v',
+	'b',         'n',         'm',         ',',          '.',         '/',          K_RSHIFT,    KP_STAR,
+	K_LALT,      ' ',         K_CAPSLOCK,   K_F1,        K_F2,        K_F3,         K_F4,        K_F5,
+	K_F6,        K_F7,        K_F8,         K_F9,        K_F10,       KP_NUMLOCK,   K_SCRLCK,    K_HOME,
+	K_UPARROW,   K_PGUP,      '-',          K_LEFTARROW, '5',         K_RIGHTARROW, '+',         K_END,
+	K_DOWNARROW, K_PGDN,      K_INS,        K_DEL,       0,           0,            0,           K_F11,
+	K_F12,       K_ENTER,     K_RCTRL,      '/',         K_PRINTSCR,  K_RALT,       K_HOME,      K_UPARROW,
+	K_PGUP,      K_LEFTARROW, K_RIGHTARROW, K_END,       K_DOWNARROW, K_PGDN,       K_INS,       K_DEL,
+	K_PAUSE,     K_LWIN,      K_RWIN,       K_MENU,      0,           0,            0,           0,
+	0,           0,           0,            0,           0,           0,            0,           0,
+	0,           0,           0,            0,           0,           0,            0,           0
 };
 
 void keyhandler(int scancode, int state) {	
