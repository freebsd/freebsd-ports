clang fails to build parts of BRL-CAD because of http://llvm.org/bugs/show_bug.cgi?id=17788.
--- misc/CMake/BRLCAD_CompilerFlags.cmake~	2013-10-27 17:26:22.000000000 +0200
+++ misc/CMake/BRLCAD_CompilerFlags.cmake	2013-10-27 17:26:27.000000000 +0200
@@ -83,7 +83,7 @@
   # also of interest:
   # -Wunreachable-code -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -ansi
   # -Wformat=2 (after bu_fopen_uniq() is obsolete)
-  BRLCAD_CHECK_C_FLAG(pedantic)
+  # BRLCAD_CHECK_C_FLAG(pedantic)
   BRLCAD_CHECK_CXX_FLAG(pedantic)
 
   # The Wall warnings are too verbose with Visual C++
