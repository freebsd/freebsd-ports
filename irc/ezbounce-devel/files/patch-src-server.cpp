--- src/server.cpp	Sun May  5 17:53:00 2002
+++ src/server.cpp	Mon Jul 22 04:27:26 2002
@@ -204,7 +204,7 @@
     if (now)
     {
         strcpy(buff, "Server terminating: ");
-        strncat(buff, reason, (sizeof buff) - strlen(buff) + 1);
+        strncat(buff, reason, (sizeof buff) - (strlen(buff) + 1));
         conn::broadcast(&conns,buff);
         ircproxy_save_prefs(users, pcfg.userfile);
         kill_conns();
@@ -213,7 +213,7 @@
     }
     terminate_request = 1;
     strcpy(buff, "Terminate request: ");
-    strncat(buff, reason, (sizeof buff) - strlen(buff) + 1);
+    strncat(buff, reason, (sizeof buff) - (strlen(buff) + 1));
     conn::broadcast(&conns,buff);
     ircproxy_save_prefs(users, pcfg.userfile);
     return 1;
