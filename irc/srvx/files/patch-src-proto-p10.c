--- src/proto-p10.c.old	Tue Feb 22 05:11:21 2005
+++ src/proto-p10.c	Mon Mar 14 22:21:12 2005
@@ -367,10 +367,10 @@
     if (srv == self) {
         /* The +s, ignored by Run's ircu, means "service" to Undernet's ircu */
         putsock(P10_SERVER " %s %d %li %li J10 %s%s +s :%s",
-                srv->name, srv->hops+1, srv->boot, srv->link, srv->numeric, extranum, srv->description);
+                srv->name, srv->hops+1, (long)srv->boot, (long)srv->link, srv->numeric, extranum, srv->description);
     } else {
         putsock("%s " P10_SERVER " %s %d %li %li %c10 %s%s +s :%s",
-                self->numeric, srv->name, srv->hops+1, srv->boot, srv->link, (srv->self_burst ? 'J' : 'P'), srv->numeric, extranum, srv->description);
+                self->numeric, srv->name, srv->hops+1, (long)srv->boot, (long)srv->link, (srv->self_burst ? 'J' : 'P'), srv->numeric, extranum, srv->description);
     }
 }
 
@@ -408,10 +408,10 @@
 
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
 
@@ -545,7 +545,7 @@
 irc_gline(struct server *srv, struct gline *gline)
 {
     putsock("%s " P10_GLINE " %s +%s %ld :%s",
-            self->numeric, (srv ? srv->numeric : "*"), gline->target, gline->expires-now, gline->reason);
+            self->numeric, (srv ? srv->numeric : "*"), gline->target, (long)gline->expires-now, gline->reason);
 }
 
 void
@@ -680,9 +680,9 @@
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
 
