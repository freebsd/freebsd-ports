--- src/irc_server.c.orig	2007-10-02 13:27:29.000000000 +0200
+++ src/irc_server.c	2007-10-02 13:28:07.000000000 +0200
@@ -700,7 +700,7 @@
               free(s);
 
               /* Was in the squelch list, so remove it and stop looking */
-              s = (l ? l->next : p->squelch_modes) = n;
+              s = *(l ? &(l->next) : &(p->squelch_modes)) = n;
               squelch = 1;
               break;
             } else {
@@ -741,7 +741,7 @@
               free(s);
 
               /* Was in the squelch list, so remove it and stop looking */
-              s = (l ? l->next : p->squelch_modes) = n;
+              s = *(l ? &(l->next) : &(p->squelch_modes)) = n;
               squelch = 1;
               break;
             } else {
