--- build/FreeBSD.inc.orig	2017-03-06 12:36:15.780368000 +0000
+++ build/FreeBSD.inc	2017-03-06 12:37:56.563219000 +0000
@@ -29,14 +29,14 @@
 endif
 
 ifndef runtime
-        clang_version:=$(shell clang -v 2>&1 | grep version | sed "s/.*version \([0-9]*\.[0-9]*\).*/\1/")
+        clang_version:=$(shell $(CC) -dumpversion)
         os_version:=$(shell uname -r)
         os_kernel_version:=$(shell uname -r | sed -e 's/-.*$$//')
         export runtime:=cc$(clang_version)_kernel$(os_kernel_version)
 endif
 
-native_compiler := clang
-export compiler ?= clang
+native_compiler := $(CC)
+export compiler ?= $(CC)
 debugger ?= gdb
 
 CMD=$(SHELL) -c
@@ -46,7 +46,7 @@
 MD?=mkdir -p
 NUL= /dev/null
 SLASH=/
-MAKE_VERSIONS=sh $(tbb_root)/build/version_info_linux.sh $(VERSION_FLAGS) >version_string.ver
+MAKE_VERSIONS=sh $(tbb_root)/build/version_info_FreeBSD.sh $(VERSION_FLAGS) >version_string.ver
 MAKE_TBBVARS=sh $(tbb_root)/build/generate_tbbvars.sh
 
 ifdef LD_LIBRARY_PATH
