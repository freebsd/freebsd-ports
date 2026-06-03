--- autosetup/sqlite-config.tcl.orig	2026-01-19 17:01:34 UTC
+++ autosetup/sqlite-config.tcl
@@ -884,12 +884,11 @@ proc sqlite-handle-soname {} {
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
