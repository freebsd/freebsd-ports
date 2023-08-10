--- ncbi-vdb/libs/kfs/unix/sysdir.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/kfs/unix/sysdir.c
@@ -2291,6 +2291,8 @@ rc_t KSysDirOpenDirRead_v1 ( const KSysDir_v1 * self,
     rc_t rc;
 
     rc = KSysDirMakePath_v1 ( self, rcOpening, true, full, sizeof full, path, args );
+    // FIXME: Remove this debug statement
+    // fprintf(stderr, "path = %s  full = %s\n", path, full);
     if ( rc == 0 )
     {
         int t;
