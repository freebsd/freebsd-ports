--- lib/loop_unicode.h.orig	Mon May  6 06:17:43 2002
+++ lib/loop_unicode.h	Sat Jun 15 14:07:14 2002
@@ -52,8 +52,7 @@
       cd->ostate = backup_state;
       outptr = backup_outptr;
       outleft = backup_outleft;
-      if (sub_outcount < 0)
-        return RET_TOOSMALL;
+      return sub_outcount;
     }
   }
   {
@@ -96,8 +95,7 @@
           cd->ostate = backup_state;
           outptr = backup_outptr;
           outleft = backup_outleft;
-          if (sub_outcount < 0)
-            return RET_TOOSMALL;
+	  return sub_outcount;
         }
         if (last)
           break;
@@ -144,8 +142,7 @@
       cd->ostate = backup_state;
       outptr = backup_outptr;
       outleft = backup_outleft;
-      if (sub_outcount != RET_ILUNI)
-        return RET_TOOSMALL;
+      return sub_outcount;
     }
   }
   return RET_ILUNI;
