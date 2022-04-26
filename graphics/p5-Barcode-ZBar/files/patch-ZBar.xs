--- ZBar.xs.orig	2022-02-07 23:58:06 UTC
+++ ZBar.xs
@@ -209,9 +209,10 @@ zbar_version()
     PREINIT:
 	unsigned major;
         unsigned minor;
+        unsigned patch;
     CODE:
-        zbar_version(&major, &minor, NULL);
-        RETVAL = newSVpvf("%u.%u", major, minor);
+        zbar_version(&major, &minor, &patch);
+        RETVAL = newSVpvf("%u.%u.%u", major, minor, patch);
     OUTPUT:
         RETVAL
 
