--- xxl.c.orig	2004-12-22 03:42:52.000000000 -0600
+++ xxl.c	2008-01-17 13:25:18.000000000 -0600
@@ -380,6 +380,8 @@
             if (!tsd->contexts)
                 die("XXL: Exception thrown with no handler to catch it!\n");
             tsd->contexts->exception = *exception;
+			how=XXL_SETJMP_TRY;
+			tsd->contexts->state |= XXL_STATE_THROWN;
             xxl_leave_handler(how);
             return;
     }
