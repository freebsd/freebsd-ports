--- src/s3.c.orig	Wed May  3 19:23:57 2000
+++ src/s3.c	Fri Jul 30 13:21:55 2004
@@ -474,7 +474,6 @@
 	    dac_used->restoreState(regs);
 	    return old_values;
 	}
-    default:
     }
     return 0;
 }
