--- lib/sshv2.c.orig	Thu Jul 24 18:44:59 2003
+++ lib/sshv2.c	Thu Jul 24 18:47:03 2003
@@ -291,7 +291,8 @@
       diff += rd;
       tempstr[diff] = '\0'; 
 
-      if (diff >= 10 && strcmp (tempstr + diff - 9, "assword: ") == 0)
+      if ( (strcmp (tempstr, "Password:") == 0) || 
+           (diff >= 10 && strcmp (tempstr + diff - 9, "assword: ") == 0))
         {
           if (wrotepw)
             {
