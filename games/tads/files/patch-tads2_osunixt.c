--- osunixt.c.orig	2004-12-15 02:06:26 UTC
+++ osunixt.c
@@ -960,7 +960,7 @@ t_tty(int action)
         t.c_cc[VMIN] = 1;
         t.c_cc[VTIME] = 0;
 #if !defined(SGI_IRIX)
-        t.c_oflag &= (~XTABS);
+        t.c_oflag &= (~OXTABS);
 #else
         t.c_oflag &= (~TAB3);
 #endif
@@ -984,7 +984,7 @@ t_tty(int action)
 #ifdef  USE_SGTTY
     ospeed = t.sg_ospeed;
 #else   
-    ospeed = t.c_cflag & CBAUD;
+	ospeed = cfgetospeed(&t);
 #endif
     if (ospeed == 0)
         ospeed = 11;
