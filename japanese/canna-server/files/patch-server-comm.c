--- server/comm.c.orig	2025-06-05 14:35:46 UTC
+++ server/comm.c
@@ -555,10 +555,11 @@ struct sockaddr_un *unaddr;
   unaddr->sun_family = AF_UNIX;
   oldUmask = umask (0);
   
-  if ( mkdir( IR_UNIX_DIR, 0777 ) == -1 &&
+  if ( mkdir( IR_UNIX_DIR, 0755 ) == -1 &&
       errno != EEXIST ) {
     ir_debug( Dmsg(5, "Can't open %s error No. %d\n",IR_UNIX_DIR, errno));
   }
+
   if (RkiStrlcpy(unaddr->sun_path, IR_UNIX_PATH, sockpathmax) >= sockpathmax) {
     ir_debug( Dmsg(5, "Path to socket is too long\n"));
     goto last;
