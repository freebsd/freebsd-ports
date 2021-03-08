--- ZBar.xs.orig
+++ ZBar.xs
@@ -198,9 +198,10 @@
     PREINIT:
 	unsigned major;
         unsigned minor;
+        unsigned patch;
     CODE:
-        zbar_version(&major, &minor);
-        RETVAL = newSVpvf("%u.%u", major, minor);
+        zbar_version(&major, &minor, &patch);
+        RETVAL = newSVpvf("%u.%u.%u", major, minor, patch);
     OUTPUT:
         RETVAL
 
