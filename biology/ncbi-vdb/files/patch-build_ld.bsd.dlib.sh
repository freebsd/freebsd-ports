--- build/ld.bsd.dlib.sh.orig	2017-10-27 07:23:08 UTC
+++ build/ld.bsd.dlib.sh
@@ -51,8 +51,8 @@ case "$LD" in
 g*)
     source "${0%dlib.sh}gcc.sh"
     ;;
-i*)
-    source "${0%dlib.sh}icc.sh"
+c*)
+    source "${0%dlib.sh}clang.sh"
     ;;
  *)
     echo "$SELF_NAME: unrecognized ld tool - '$LD'"
@@ -100,7 +100,7 @@ then
             # always load libdl as shared library
             load-ref-symbols
             load-dynamic
-            CMD="$CMD -ldl"
+#            CMD="$CMD -ldl"
             ;;
 
         -l*)
