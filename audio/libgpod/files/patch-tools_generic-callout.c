Call mount() only on Linux -- it has different call signature elsewhere.

Index: tools/generic-callout.c
--- tools/generic-callout.c.orig	2013-07-10 13:43:42 UTC
+++ tools/generic-callout.c
@@ -588,6 +588,7 @@ static char *mount_ipod (const char *dev_path, const c
 
 static char *mount_ipod (const char *dev_path, const char *fstype)
 {
+#ifdef __linux__
         char *filename;
         char *tmpname;
         int result;
@@ -616,6 +617,9 @@ static char *mount_ipod (const char *dev_path, const c
         g_debug("device successfully mounted at %s", tmpname);
 
         return tmpname;
+#else
+        return NULL;
+#endif
 }
 
 static gboolean write_sysinfo_extended (const char *mountpoint,
@@ -745,7 +749,9 @@ int itdb_callout_set_ipod_properties (ItdbBackend *bac
          */
         mounted_ipod_set_properties (backend, ipod_mountpoint);
 
+#ifdef __linux__
         umount (ipod_mountpoint);
+#endif
         g_rmdir (ipod_mountpoint);
         g_free (ipod_mountpoint);
 
