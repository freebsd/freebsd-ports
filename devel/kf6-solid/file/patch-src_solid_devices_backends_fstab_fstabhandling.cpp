--- src/solid/devices/backends/fstab/fstabhandling.cpp.orig	2025-06-13 09:40:36 UTC
+++ src/solid/devices/backends/fstab/fstabhandling.cpp
@@ -70,11 +70,7 @@ bool _k_isFstabSupportedLocalFileSystem(const QString 
     if (fstype == QLatin1String("fuse.encfs") //
         || fstype == QLatin1String("fuse.cryfs") //
         || fstype == QLatin1String("fuse.gocryptfs") //
-        || fstype == QLatin1String("overlay")
-
-        // handle ZFS here as udisk2 doesn't support that yet
-        // see https://github.com/storaged-project/udisks/issues/42
-        || fstype == QLatin1String("zfs")) {
+        || fstype == QLatin1String("overlay")) {
         return true;
     }
     return false;
