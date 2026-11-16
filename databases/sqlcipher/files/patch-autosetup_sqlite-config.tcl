--- autosetup/sqlite-config.tcl.orig	2026-10-26 13:57:49 UTC
+++ autosetup/sqlite-config.tcl
@@ -908,12 +908,11 @@ proc sqlite-handle-soname {} {
     none - "" { return 0 }
     legacy    { set soname libsqlite3.so.0 }
     default {
-      if {[string match libsqlite3.* $soname]} {
-        # use it as-is
-      } else {
+      if {[string match {[0-9]*} $soname]} {
         # Assume it's a suffix
         set soname "libsqlite3.so.${soname}"
       }
+      # else use it as-is
     }
   }
   proc-debug "soname=$soname"
