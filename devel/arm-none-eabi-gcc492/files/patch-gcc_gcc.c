--- gcc/gcc.c.orig	2014-10-22 21:42:48 UTC
+++ gcc/gcc.c
@@ -710,12 +710,12 @@ proper position among the other output f
 #define PLUGIN_COND_CLOSE ""
 #endif
 #define LINK_PLUGIN_SPEC \
-    "%{"PLUGIN_COND": \
+    "%{" PLUGIN_COND ": \
     -plugin %(linker_plugin_file) \
     -plugin-opt=%(lto_wrapper) \
     -plugin-opt=-fresolution=%u.res \
     %{!nostdlib:%{!nodefaultlibs:%:pass-through-libs(%(link_gcc_c_sequence))}} \
-    }"PLUGIN_COND_CLOSE
+    }" PLUGIN_COND_CLOSE
 #else
 /* The linker used doesn't support -plugin, reject -fuse-linker-plugin.  */
 #define LINK_PLUGIN_SPEC "%{fuse-linker-plugin:\
