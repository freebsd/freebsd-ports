--- build/BSD.inc.orig	2019-12-18 22:42:41 UTC
+++ build/BSD.inc
@@ -22,17 +22,26 @@ ifndef arch
         ifeq ($(shell uname -m),amd64)
                 export arch:=intel64
         endif
+        ifeq ($(shell uname -m),arm)
+                export arch:=armv7
+        endif
+        ifeq ($(shell uname -m),arm64)
+                export arch:=arm64
+        endif
+        ifeq ($(shell uname -p),powerpc64)
+                export arch:=powerpc64
+        endif
 endif
 
 ifndef runtime
-        clang_version:=$(shell clang --version | sed -n "1s/.*version \(.*[0-9]\) .*/\1/p")
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
@@ -42,7 +51,7 @@ RD?=rmdir
 MD?=mkdir -p
 NUL= /dev/null
 SLASH=/
-MAKE_VERSIONS=sh $(tbb_root)/build/version_info_linux.sh $(VERSION_FLAGS) >version_string.ver
+MAKE_VERSIONS=sh $(tbb_root)/build/version_info_FreeBSD.sh $(VERSION_FLAGS) >version_string.ver
 MAKE_TBBVARS=sh $(tbb_root)/build/generate_tbbvars.sh
 
 ifdef LD_LIBRARY_PATH
