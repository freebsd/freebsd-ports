--- ucon64_misc.c.orig	2019-05-30 17:27:48 UTC
+++ ucon64_misc.c
@@ -576,7 +576,7 @@ ucon64_load_discmage (void)
 {
   uint32_t version;
 #ifdef  DLOPEN
-  const char *p = get_property (ucon64.configfile, "discmage_path", PROPERTY_MODE_FILENAME);
+  const char *p = "%%PREFIX%%/lib/libdiscmage.so";
   if (p)
     strcpy (ucon64.discmage_path, p);
   else
@@ -1235,7 +1235,7 @@ ucon64_set_property_array (const char *org_configfile)
 #elif   defined __APPLE__                       // Mac OS X actually
                        PROPERTY_MODE_DIR ("ucon64") "discmage.dylib",
 #elif   defined __unix__ || defined __BEOS__
-                       PROPERTY_MODE_DIR ("ucon64") "discmage.so",
+                       "%%PREFIX%%/lib/libdiscmage.so",
 #else
                        "",
 #endif
