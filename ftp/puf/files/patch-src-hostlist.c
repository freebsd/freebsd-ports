Index: src/hostlist.c
===================================================================
RCS file: /cvsroot/puf/puf/src/hostlist.c,v
retrieving revision 1.15
retrieving revision 1.16
diff -u -r1.15 -r1.16
--- src/hostlist.c	22 Jun 2004 09:26:55 -0000	1.15
+++ src/hostlist.c	5 Jul 2004 07:41:29 -0000	1.16
@@ -103,7 +103,7 @@
 {
     int l = strlen(proc->whost->host->name) + 1;
     dbg(DNS, ("starting dns lookup, helper %d\n", proc->pid));
-    if (send(proc->fd, proc->whost->host->name, l, MSG_NOSIGNAL) != l) {
+    if (send(proc->fd, proc->whost->host->name, l, 0) != l) {
 	prx(ERR, "cannot talk to DNS helper!\n");
 	return 0;
     }
@@ -121,7 +121,7 @@
     u_char buf[1024];
 
     dbg(DNS, ("finishing dns lookup, helper %d\n", proc->pid));
-    if (recv(proc->fd, buf, sizeof(buf), MSG_NOSIGNAL) < (int)sizeof(int)) {
+    if (recv(proc->fd, buf, sizeof(buf), 0) < (int)sizeof(int)) {
 	prx(ERR, "cannot talk to DNS helper!\n");
 	return 0;
     }
