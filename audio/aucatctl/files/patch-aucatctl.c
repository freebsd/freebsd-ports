--- aucatctl.c.orig	2016-12-22 19:50:06 UTC
+++ aucatctl.c
@@ -69,6 +69,7 @@ setmaster(unsigned vol)
 
 	msg.start = SYSEX_START;
 	msg.type = SYSEX_TYPE_RT;
+	msg.dev = 0;
 	msg.id0 = SYSEX_CONTROL;
 	msg.id1 = SYSEX_MASTER;
 	msg.u.master.fine = 0;
