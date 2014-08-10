--- ./rules/distdir-way-opts.mk.orig	2014-07-10 06:27:16.000000000 +0200
+++ ./rules/distdir-way-opts.mk	2014-07-27 23:38:27.738949283 +0200
@@ -167,15 +167,9 @@
 
 ifeq "$3" "dyn"
 ifneq "$4" "0"
-ifeq "$$(TargetElf)" "YES"
-$1_$2_$3_GHC_LD_OPTS += \
-    -fno-use-rpaths \
-    $$(foreach d,$$($1_$2_TRANSITIVE_DEPS),-optl-Wl$$(comma)-rpath -optl-Wl$$(comma)'$$$$ORIGIN/../$$d') -optl-Wl,-zorigin
-else ifeq "$$(TargetOS_CPP)" "darwin"
 $1_$2_$3_GHC_LD_OPTS += \
     -fno-use-rpaths \
-    $$(foreach d,$$($1_$2_TRANSITIVE_DEPS),-optl-Wl$$(comma)-rpath -optl-Wl$$(comma)'@loader_path/../$$d')
-endif
+    $$(foreach d,$$($1_$2_TRANSITIVE_DEPS),-optl-Wl$$(comma)-rpath -optl-Wl$$(comma)'%%GHC_LIBDIR%%/$$d')
 endif
 endif
 
