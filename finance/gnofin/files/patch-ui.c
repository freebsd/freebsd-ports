--- src/ui.c.orig	Tue Aug 17 16:04:15 2004
+++ src/ui.c	Tue Aug 17 16:04:31 2004
@@ -1133,6 +1133,7 @@
       if_account_delete (account);
       break;
     case DIALOG_NO:
+      break;
     }
   }
 }
