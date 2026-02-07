--- vmware-user-suid-wrapper/wrapper.h.orig	2025-06-19 04:05:18 UTC
+++ vmware-user-suid-wrapper/wrapper.h
@@ -43,7 +43,7 @@
  * in the latter.
  */
 #ifdef USES_LOCATIONS_DB
-#   define LOCATIONS_PATH       "/etc/vmware-tools/locations"
+#   define LOCATIONS_PATH       "%%PREFIX%%/etc/vmware-tools/locations"
 
 /*
  * Locations DB query selector.  Values in this enum are used as array
