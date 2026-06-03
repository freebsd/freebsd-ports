https://lists.gnu.org/archive/html/libtool-patches/2025-07/msg00000.html

--- m4/libtool.m4.orig	2024-11-20 19:01:08 UTC
+++ m4/libtool.m4
@@ -4825,7 +4825,7 @@ m4_if([$1], [CXX], [
       _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
       ;;
 
-    linux* | k*bsd*-gnu | kopensolaris*-gnu | gnu*)
+    linux* | k*bsd*-gnu | kopensolaris*-gnu | gnu* | *freebsd*)
       case $cc_basename in
       # old Intel for x86_64, which still supported -KPIC.
       ecc*)
