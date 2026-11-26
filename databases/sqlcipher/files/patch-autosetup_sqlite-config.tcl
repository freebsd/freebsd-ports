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
@@ -1226,7 +1226,6 @@ proc sqlite-check-line-editing {} {
     # end up finding <editline/readline.h> below, we will use
     # -DHAVE_EDITLINE=1, else we will use -DHAVE_READLINE=1. In either
     # case, we will link against libedit.
-    set failIfNotFound 1
     set libsForReadline {edit}
     set editLibName editline
     set editLibDef HAVE_EDITLINE
