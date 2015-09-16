--- build/FreeBSD.inc.orig	2015-06-11 14:18:55 UTC
+++ build/FreeBSD.inc
@@ -29,14 +29,14 @@ ifndef arch
 endif
 
 ifndef runtime
-        gcc_version:=$(shell gcc -dumpversion)
+        gcc_version:=$(shell $(CC) -dumpversion)
         os_version:=$(shell uname -r)
         os_kernel_version:=$(shell uname -r | sed -e 's/-.*$$//')
         export runtime:=cc$(gcc_version)_kernel$(os_kernel_version)
 endif
 
-native_compiler := gcc
-export compiler ?= gcc
+native_compiler := $(CC)
+export compiler ?= $(CC)
 debugger ?= gdb
 
 CMD=$(SHELL) -c
@@ -46,7 +46,7 @@ RD?=rmdir
 MD?=mkdir -p
 NUL= /dev/null
 SLASH=/
-MAKE_VERSIONS=sh $(tbb_root)/build/version_info_linux.sh $(VERSION_FLAGS) >version_string.ver
+MAKE_VERSIONS=sh $(tbb_root)/build/version_info_FreeBSD.sh $(VERSION_FLAGS) >version_string.ver
 MAKE_TBBVARS=sh $(tbb_root)/build/generate_tbbvars.sh
 
 ifdef LD_LIBRARY_PATH
