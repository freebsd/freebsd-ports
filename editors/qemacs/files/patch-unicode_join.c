--- unicode_join.c.orig	Sat Aug 21 20:08:14 2004
+++ unicode_join.c	Sat Aug 21 20:08:27 2004
@@ -182,6 +182,7 @@
             *q++ = l1;
             i++;
         found:
+	    break;
         }
     }
     return q - buf_out;
