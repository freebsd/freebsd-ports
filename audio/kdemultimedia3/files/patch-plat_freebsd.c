--- kscd/libwm/plat_freebsd.c	Tue Apr 10 13:34:52 2001
+++ kscd/libwm/plat_freebsd.c.new	Thu Nov 29 22:20:56 2001
@@ -159,6 +159,8 @@
     wm_lib_message(WM_MSG_LEVEL_DEBUG|WM_MSG_CLASS, "calling wmcd_open()\n");
     status = wmcd_open( d ); /* open it as usual */
     wm_susleep( 1000 );
+    if(status == -EACCES || status == 1)
+        return status;
   } while ( status != 0 );
   return status;
 } /* wmcd_reopen() */
