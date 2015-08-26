--- module/owfs/src/c/owfs.c.orig	2015-02-23 03:46:11 UTC
+++ module/owfs/src/c/owfs.c
@@ -128,7 +128,7 @@ int main(int argc, char *argv[])
 
 	// Unmount just in case
 	// No checks -- can fail without consequences
-	umount( Outbound_Control.head->name ) ;
+	unmount( Outbound_Control.head->name, 0) ;
 
 	Fuse_parse(fuse_mnt_opt, &fuse_options);
 	LEVEL_DEBUG("fuse_mnt_opt=[%s]", fuse_mnt_opt);
