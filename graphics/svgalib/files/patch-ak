diff -druN svgalib-1.4.2.orig/src/mouse/ms.c src/mouse/ms.c
--- svgalib-1.4.2.orig/src/mouse/ms.c	Fri Aug 25 04:39:39 2000
+++ src/mouse/ms.c	Fri Aug 25 04:39:57 2000
@@ -116,7 +116,7 @@
     tty.c_iflag = IGNBRK | IGNPAR;
     tty.c_oflag = 0;
     tty.c_lflag = 0;
-    tty.c_line  = 0;
+/*    tty.c_line  = 0;*/
     tty.c_cc[VTIME] = 0;
     tty.c_cc[VMIN]  = 1;
 
@@ -509,7 +509,7 @@
 	tty.c_iflag = IGNBRK | IGNPAR;
 	tty.c_oflag = 0;
 	tty.c_lflag = 0;
-	tty.c_line = 0;
+/*	tty.c_line = 0;*/
 	tty.c_cc[VTIME] = 0;
 	tty.c_cc[VMIN] = 1;
 	tty.c_cflag = cflag[m_type] | B1200;
