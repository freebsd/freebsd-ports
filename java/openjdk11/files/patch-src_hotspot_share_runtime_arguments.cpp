--- src/hotspot/share/runtime/arguments.cpp.orig	2020-01-15 18:29:57 UTC
+++ src/hotspot/share/runtime/arguments.cpp
@@ -1458,7 +1458,7 @@ bool Arguments::add_property(const char* prop, Propert
       // save it in _java_vendor_url_bug, so JVM fatal error handler can access
       // its value without going through the property list or making a Java call.
       _java_vendor_url_bug = os::strdup_check_oom(value, mtArguments);
-      if (old_java_vendor_url_bug != DEFAULT_VENDOR_URL_BUG) {
+      if (strcmp(old_java_vendor_url_bug, DEFAULT_VENDOR_URL_BUG) != 0) {
         assert(old_java_vendor_url_bug != NULL, "_java_vendor_url_bug is NULL");
         os::free((void *)old_java_vendor_url_bug);
       }
