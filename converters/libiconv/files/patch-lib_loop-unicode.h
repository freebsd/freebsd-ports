--- lib/loop_unicode.h.orig     Fri Jun  8 22:04:33 2001
+++ lib/loop_unicode.h  Mon Apr 29 05:12:08 2002
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
+         return sub_outcount;
         }
         if (last)
           break;
@@ -144,8 +142,7 @@
       cd->ostate = backup_state;
       outptr = backup_outptr;
       outleft = backup_outleft;
-      if (sub_outcount < 0)
-        return RET_TOOSMALL;
+      return sub_outcount;
     }
   }
   return RET_ILUNI;
