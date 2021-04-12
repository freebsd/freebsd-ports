--- build/ld.bsd.exe.sh.orig	2017-10-27 07:23:08 UTC
+++ build/ld.bsd.exe.sh
@@ -51,8 +51,8 @@ case "$LD" in
 g*)
     source "${0%exe.sh}gcc.sh"
     ;;
-i*)
-    source "${0%exe.sh}icc.sh"
+c*)
+    source "${0%exe.sh}clang.sh"
     ;;
 *)
     echo "$SELF_NAME: unrecognized ld tool - '$LD'"
@@ -108,7 +108,7 @@ then
             # always load libdl as shared library
             load-ref-symbols
             load-dynamic
-            CMD="$CMD -ldl"
+#            CMD="$CMD -ldl"
             ;;
 
         -l*)
