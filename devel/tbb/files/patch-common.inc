Accept absolute paths for $compiler variable (and so for $CC)

--- build/common.inc.orig	2016-09-22 10:28:03.000000000 +0000
+++ build/common.inc	2017-01-05 21:44:56.121147000 +0000
@@ -106,17 +106,17 @@
   target:=$(tbb_os)
  endif
  # process host/target compiler-dependent build configuration
- ifeq (,$(wildcard $(tbb_root)/build/$(target).$(compiler).inc))
-  $(error "$(compiler)" is not supported on $(target). Add build/$(target).$(compiler).inc file with compiler-specific settings. )
+ ifeq (,$(wildcard $(tbb_root)/build/$(target).$(notdir $(compiler)).inc))
+  $(error "$(notdir $(compiler))" is not supported on $(target). Add build/$(target).$(notdir $(compiler)).inc file with compiler-specific settings. )
  endif
- include $(tbb_root)/build/$(target).$(compiler).inc
+ include $(tbb_root)/build/$(target).$(notdir $(compiler)).inc
 endif
 
 ifneq ($(BUILDING_PHASE),1)
  # definitions for top-level Makefiles
  origin_build_dir:=$(origin tbb_build_dir)
  tbb_build_dir?=$(tbb_root)$(SLASH)build
- export tbb_build_prefix?=$(tbb_os)_$(arch)_$(compiler)_$(runtime)$(CPF_SUFFIX)
+ export tbb_build_prefix?=$(tbb_os)_$(arch)_$(notdir $(compiler))_$(runtime)$(CPF_SUFFIX)
  work_dir=$(tbb_build_dir)$(SLASH)$(tbb_build_prefix)
 endif  # BUILDING_PHASE != 1
 
