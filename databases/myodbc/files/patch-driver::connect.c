--- driver/connect.c.orig	Thu Jan 13 17:53:25 2005
+++ driver/connect.c	Thu Jan 13 17:54:18 2005
@@ -834,8 +834,8 @@
       if (!KEY_STMT)
         KEY_STMT= (char*) my_strdup("", MYF(MY_WME));
 
-      if (fDriverCompletion == SQL_DRIVER_PROMPT ||
-      ((fDriverCompletion == SQL_DRIVER_COMPLETE ||
+      if (
+      ((fDriverCompletion == SQL_DRIVER_PROMPT ||fDriverCompletion == SQL_DRIVER_COMPLETE ||
         fDriverCompletion == SQL_DRIVER_COMPLETE_REQUIRED) &&
        (!KEY_DSN && !fDriver)))
         fPrompt= TRUE;
