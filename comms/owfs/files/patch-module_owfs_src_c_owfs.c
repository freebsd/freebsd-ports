--- module/owfs/src/c/owfs.c.orig	2014-10-11 03:23:18.000000000 +0400
+++ module/owfs/src/c/owfs.c	2014-12-30 19:53:53.000000000 +0300
@@ -129,7 +129,7 @@
 
 	// Unmount just in case
 	// No checks -- can fail without consequences
-	umount( Outbound_Control.head->name ) ;
+	unmount( Outbound_Control.head->name, 0) ;
 
 	Fuse_parse(fuse_mnt_opt, &fuse_options);
 	LEVEL_DEBUG("fuse_mnt_opt=[%s]", fuse_mnt_opt);
