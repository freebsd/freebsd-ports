--- source/dcc.c.orig	Wed Nov 14 04:49:45 2001
+++ source/dcc.c	Fri Apr 25 04:07:12 2003
@@ -1057,7 +1057,7 @@
 
   if (ircncmp(msg, "PING", 4) == 0)
   {
-    notice(target, nick, msg - 1);
+    notice(target, nick, "%s", msg - 1);
     SendUmode(OPERUMODE_Y,
       "%s: CTCP PING received from %s!%s@%s",
       target,
