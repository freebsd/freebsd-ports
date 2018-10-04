--- build/BSD.inc.orig	2018-06-19 16:04:20 UTC
+++ build/BSD.inc
@@ -26,17 +26,23 @@ ifndef arch
         ifeq ($(shell uname -m),amd64)
                 export arch:=intel64
         endif
+        ifeq ($(shell uname -m),arm)
+                export arch:=armv7
+        endif
+        ifeq ($(shell uname -m),arm64)
+                export arch:=arm64
+        endif
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
@@ -46,7 +52,7 @@ RD?=rmdir
 MD?=mkdir -p
 NUL= /dev/null
 SLASH=/
-MAKE_VERSIONS=sh $(tbb_root)/build/version_info_linux.sh $(VERSION_FLAGS) >version_string.ver
+MAKE_VERSIONS=sh $(tbb_root)/build/version_info_FreeBSD.sh $(VERSION_FLAGS) >version_string.ver
 MAKE_TBBVARS=sh $(tbb_root)/build/generate_tbbvars.sh
 
 ifdef LD_LIBRARY_PATH
