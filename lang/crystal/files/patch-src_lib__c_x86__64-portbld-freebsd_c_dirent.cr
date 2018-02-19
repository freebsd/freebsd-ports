--- src/lib_c/x86_64-portbld-freebsd/c/dirent.cr.orig	2017-10-27 14:50:57 UTC
+++ src/lib_c/x86_64-portbld-freebsd/c/dirent.cr
@@ -4,10 +4,21 @@ lib LibC
   type DIR = Void
 
   struct Dirent
-    d_fileno : UInt
+    {% if flag?(:"freebsd12.0") %}
+      d_fileno : ULong
+      d_off : ULong
+    {% else %}
+      d_fileno : UInt
+    {% end %}
     d_reclen : UShort
     d_type : UChar
-    d_namlen : UChar
+    {% if flag?(:"freebsd12.0") %}
+      d_pad0 : UChar
+      d_namlen : UShort
+      d_pad1 : UShort
+    {% else %}
+      d_namlen : UChar
+    {% end %}
     d_name : StaticArray(Char, 256)
   end
 
