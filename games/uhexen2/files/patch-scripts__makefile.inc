--- ./scripts/makefile.inc.orig	Fri Oct  6 13:43:36 2006
+++ ./scripts/makefile.inc	Tue Jan  9 16:56:32 2007
@@ -15,7 +15,8 @@
 
 # Common paths:
 # X directory
-X11_PATH ?=/usr/X11R6
+X11BASE ?= /usr/X11R6
+X11_PATH ?= $(X11BASE)
 
 # MinGW32 directory:
 MINGWDIR ?=/mingw
@@ -61,22 +62,7 @@
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
+CC ?= gcc
 
 NASM ?= $(NASM_BIN)
 WINDRES ?= windres
@@ -104,9 +90,6 @@
 
 # default CPU flags
 CPUFLAGS:=
-ifeq ($(MACH_TYPE),x86)
-CPUFLAGS:=-march=i586
-endif
 
 # NASM flags:
 # These are required for IA32 assembly for hexen2/hexenworld clients
@@ -121,7 +104,7 @@
 # be added to the make command
 DFLAGS := -g -Wall
 ifdef DEBUG
-CFLAGS := $(DFLAGS)
+CFLAGS := $(CFLAGS) $(DFLAGS)
 endif
 
 # the "sdl-config" command
