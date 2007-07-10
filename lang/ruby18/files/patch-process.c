--- process.c.orig	Tue Feb 13 02:01:19 2007
+++ process.c	Wed May 23 02:32:16 2007
@@ -981,6 +981,7 @@
     }
 #endif /* MSDOS or __human68k__ or __EMX__ */
     before_exec();
+    rb_thread_cancel_timer();
     execv(prog, argv);
     after_exec();
     return -1;
