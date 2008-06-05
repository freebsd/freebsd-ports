--- src/proto-p10.c.orig	2008-05-29 03:46:01.000000000 +0900
+++ src/proto-p10.c	2008-05-29 03:48:41.000000000 +0900
@@ -369,10 +369,10 @@
     if (srv == self) {
         /* The +s, ignored by Run's ircu, means "service" to Undernet's ircu */
         putsock(P10_SERVER " %s %d %li %li J10 %s%s +s6 :%s",
-                srv->name, srv->hops+1, srv->boot, srv->link, srv->numeric, extranum, srv->description);
+                srv->name, srv->hops+1, (long)srv->boot, (long)srv->link, srv->numeric, extranum, srv->description);
     } else {
         putsock("%s " P10_SERVER " %s %d %li %li %c10 %s%s +s6 :%s",
-                self->numeric, srv->name, srv->hops+1, srv->boot, srv->link, (srv->self_burst ? 'J' : 'P'), srv->numeric, extranum, srv->description);
+                self->numeric, srv->name, srv->hops+1, (long)srv->boot, (long)srv->link, (srv->self_burst ? 'J' : 'P'), srv->numeric, extranum, srv->description);
     }
 }
 
@@ -485,10 +485,10 @@
 
         /* we don't need to put the + in modes because it's in the format string. */
         putsock("%s " P10_NICK " %s %d %li %s %s +%s %s %s :%s",
-                user->uplink->numeric, user->nick, user->uplink->hops+1, user->timestamp, user->ident, user->hostname, modes, b64ip, user->numeric, user->info);
+                user->uplink->numeric, user->nick, user->uplink->hops+1, (long)user->timestamp, user->ident, user->hostname, modes, b64ip, user->numeric, user->info);
     } else {
         putsock("%s " P10_NICK " %s %d %li %s %s %s %s :%s",
-                user->uplink->numeric, user->nick, user->uplink->hops+1, user->timestamp, user->ident, user->hostname, b64ip, user->numeric, user->info);
+                user->uplink->numeric, user->nick, user->uplink->hops+1, (long)user->timestamp, user->ident, user->hostname, b64ip, user->numeric, user->info);
     }
 }
 
@@ -637,7 +637,7 @@
 irc_gline(struct server *srv, struct gline *gline)
 {
     putsock("%s " P10_GLINE " %s +%s %ld :%s",
-            self->numeric, (srv ? srv->numeric : "*"), gline->target, gline->expires-now, gline->reason);
+            self->numeric, (srv ? srv->numeric : "*"), gline->target, (long)gline->expires-now, gline->reason);
 }
 
 void
@@ -772,9 +772,9 @@
 {
     if (what->members.used == 1) {
         putsock("%s " P10_CREATE " %s %lu",
-                who->numeric, what->name, what->timestamp);
+                who->numeric, what->name, (long)what->timestamp);
     } else {
-        putsock("%s " P10_JOIN " %s %lu", who->numeric, what->name, what->timestamp);
+        putsock("%s " P10_JOIN " %s %lu", who->numeric, what->name, (long)what->timestamp);
     }
 }
 
