Index: osunixt.c
@@ -960,7 +960,7 @@
         t.c_cc[VMIN] = 1;
         t.c_cc[VTIME] = 0;
 #if !defined(SGI_IRIX)
-        t.c_oflag &= (~XTABS);
+        t.c_oflag &= (~OXTABS);
 #else
         t.c_oflag &= (~TAB3);
 #endif
@@ -984,7 +984,7 @@
 #ifdef  USE_SGTTY
     ospeed = t.sg_ospeed;
 #else   
-    ospeed = t.c_cflag & CBAUD;
+	ospeed = cfgetospeed(&t);
 #endif
     if (ospeed == 0)
         ospeed = 11;
