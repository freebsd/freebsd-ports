--- build/FreeBSD.inc.orig	2012-09-03 13:10:45.423760088 -0400
+++ build/FreeBSD.inc	2012-09-03 13:13:15.765760027 -0400
@@ -37,14 +37,14 @@
 endif
 
 ifndef runtime
-        gcc_version:=$(shell gcc -v 2>&1 | grep 'gcc version' | sed -e 's/^gcc version //' | sed -e 's/ .*$$//')
+        gcc_version:=$(shell $(CC) -v 2>&1 | grep ' version' | sed -e 's/^.* version //' | sed -e 's/ .*$$//')
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
@@ -54,7 +54,7 @@
 MD?=mkdir -p
 NUL= /dev/null
 SLASH=/
-MAKE_VERSIONS=sh $(tbb_root)/build/version_info_linux.sh $(CPLUS) $(CPLUS_FLAGS) $(INCLUDES) >version_string.ver
+MAKE_VERSIONS=sh $(tbb_root)/build/version_info_FreeBSD.sh $(CPLUS) $(CPLUS_FLAGS) $(INCLUDES) >version_string.ver
 MAKE_TBBVARS=sh $(tbb_root)/build/generate_tbbvars.sh
 
 ifdef LD_LIBRARY_PATH
