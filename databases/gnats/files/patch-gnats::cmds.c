--- gnats/cmds.c.orig	Sun Feb  4 22:56:10 2001
+++ gnats/cmds.c	Mon Aug  5 17:25:48 2002
@@ -476,9 +476,9 @@
 
   if (user_access <= ACCESS_NONE)
     {
-      syslog (LOG_ERR, "user not allowed access: %s/%s", av[0], av[1]);
-      printf ("%d You are not on the user access list: %s/%s.\r\n",
-              CODE_NO_ACCESS, av[0], av[1]);
+      syslog (LOG_ERR, "user %s not allowed access", av[0]);
+      printf ("%d You are not on the user access list.\r\n",
+              CODE_NO_ACCESS, av[0]);
       exit (1);
     }
   
