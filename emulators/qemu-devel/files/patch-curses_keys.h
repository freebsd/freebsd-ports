Index: qemu/curses_keys.h
===================================================================
RCS file: /sources/qemu/qemu/curses_keys.h,v
retrieving revision 1.1
retrieving revision 1.2
diff -u -p -r1.1 -r1.2
--- curses_keys.h	10 Feb 2008 16:33:13 -0000	1.1
+++ curses_keys.h	18 Mar 2008 06:55:27 -0000	1.2
@@ -198,7 +198,7 @@ int curses2keycode[CURSES_KEYS] = {
 
     [0x001] = 30 | CNTRL, /* Control + a */
     [0x013] = 31 | CNTRL, /* Control + s */
-    [0x014] = 32 | CNTRL, /* Control + d */
+    [0x004] = 32 | CNTRL, /* Control + d */
     [0x006] = 33 | CNTRL, /* Control + f */
     [0x007] = 34 | CNTRL, /* Control + g */
     [0x008] = 35 | CNTRL, /* Control + h */
