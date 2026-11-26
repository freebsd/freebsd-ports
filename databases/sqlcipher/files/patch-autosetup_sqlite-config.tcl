--- autosetup/sqlite-config.tcl.orig	2026-10-26 13:57:49 UTC
+++ autosetup/sqlite-config.tcl
@@ -906,7 +906,7 @@ proc sqlite-handle-soname {} {
   }
   switch -exact -- $soname {
     none - "" { return 0 }
-    legacy    { set soname libsqlite3.so.0 }
+    legacy    { set soname libsqlcipher.so.0 }
     default {
       if {[string match libsqlite3.* $soname]} {
         # use it as-is
