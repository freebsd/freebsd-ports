--- scripts/makefile.inc.orig	Thu Jul 12 14:41:20 2007
+++ scripts/makefile.inc	Mon Oct  8 16:11:27 2007
@@ -17,7 +17,7 @@
 
 # Common paths:
 # X directory
-X11BASE ?=/usr/X11R6
+X11BASE ?=/usr/local
 
 # MinGW32 directory:
 MINGWDIR ?=/mingw
@@ -73,22 +73,7 @@
 endif
 
 # Compiler selection:
-# refuse cc for CC which is the default for make
-# accept environment or command line overrides.
-CC_DEFAULT:=gcc
-ifeq ($(origin CC),environment)
-CC_OVERRIDE:=1
-# watch for stale environment defs
-ifeq ($(CC),)
-CC_OVERRIDE:=
-endif
-endif
-ifeq ($(origin CC),command line)
-CC_OVERRIDE:=1
-endif
-ifeq ($(CC_OVERRIDE),)
-CC := $(CC_DEFAULT)
-endif
+CC ?= cc
 
 NASM ?= $(NASM_BIN)
 WINDRES ?= windres
