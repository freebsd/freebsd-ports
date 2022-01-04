--- bindings/c/generate_asm.py.orig	2021-11-06 16:01:37 UTC
+++ bindings/c/generate_asm.py
@@ -59,7 +59,7 @@ def write_windows_asm(asmfile, functions):
 
 
 def write_unix_asm(asmfile, functions, prefix):
-    if platform != "linux-aarch64":
+    if platform != "freebsd-aarch64" and platform != "linux-aarch64":
         asmfile.write(".intel_syntax noprefix\n")
 
     if platform.startswith('linux') or platform == "freebsd":
@@ -104,7 +104,7 @@ def write_unix_asm(asmfile, functions, prefix):
         # .sizeg, .-g
         # .ident"GCC: (GNU) 8.3.1 20190311 (Red Hat 8.3.1-3)"
 
-        if platform == "linux-aarch64":
+        if platform == "freebsd-aarch64" or platform == "linux-aarch64":
             asmfile.write("\tadrp x8, :got:fdb_api_ptr_%s\n" % (f))
             asmfile.write("\tldr x8, [x8, #:got_lo12:fdb_api_ptr_%s]\n" % (f))
             asmfile.write("\tldr x8, [x8]\n")
@@ -123,7 +123,7 @@ with open(asm, 'w') as asmfile:
         hfile.write(
             "void fdb_api_ptr_removed() { fprintf(stderr, \"REMOVED FDB API FUNCTION\\n\"); abort(); }\n\n")
 
-        if platform.startswith('linux'):
+        if platform.startswith('freebsd') or platform.startswith('linux'):
             write_unix_asm(asmfile, functions, '')
         elif platform == "osx":
             write_unix_asm(asmfile, functions, '_')
