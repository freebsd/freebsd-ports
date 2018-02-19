--- src/lib_c/x86_64-portbld-freebsd/c/sys/types.cr.orig	2017-10-27 14:50:57 UTC
+++ src/lib_c/x86_64-portbld-freebsd/c/sys/types.cr
@@ -9,9 +9,17 @@ lib LibC
   alias DevT = UInt
   alias GidT = UInt
   alias IdT = Long
-  alias InoT = UInt
+  {% if flag?(:"freebsd12.0") %}
+    alias InoT = ULong
+  {% else %}
+    alias InoT = UInt
+  {% end %}
   alias ModeT = UShort
-  alias NlinkT = UShort
+  {% if flag?(:"freebsd12.0") %}
+    alias NlinkT = ULong
+  {% else %}
+    alias NlinkT = UShort
+  {% end %}
   alias OffT = Long
   alias PidT = Int
   type PthreadAttrT = Void*
