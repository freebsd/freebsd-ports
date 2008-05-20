--- pre.mk	2008-03-29 14:41:03.000000000 -0500
+++ pre.mk	2008-05-20 10:56:16.000000000 -0500
@@ -1,53 +1,28 @@
-# detect system architecture: i386, x86_64, or PPC/PPC64
+# detect system architecture: i386, amd64, or PPC/PPC64
 UNAME = $(shell uname -m)
-ifeq ("$(UNAME)","x86_64")
+ifeq ("$(UNAME)","amd64")
   CPU = X86
   ifeq ("$(BITS)", "32")
-    ARCH = 64BITS_32
+    ARCH_DETECTED = 64BITS_32
   else
-    ARCH = 64BITS
+    ARCH_DETECTED = 64BITS
   endif
 endif
 ifneq ("$(filter i%86,$(UNAME))","")
   CPU = X86
-  ARCH = 32BITS
+  ARCH_DETECTED = 32BITS
 endif
 ifeq ("$(UNAME)","ppc")
   CPU = PPC
-  ARCH = 32BITS
+  ARCH_DETECTED = 32BITS
 endif
 ifeq ("$(UNAME)","ppc64")
   CPU = PPC
-  ARCH = 64BITS
+  ARCH_DETECTED = 64BITS
 endif
 
-# find installed assembler: yasm or nasm
-ifneq ("$(shell which yasm 2>&1 | head -c 9)", "which: no")
-  ASM=yasm
-else
-  ifneq ("$(shell which nasm 2>&1 | head -c 9)", "which: no")
-    ASM=nasm
-  else
-    # throw error
-    $(error No yasm or nasm found!)
-  endif
-endif
-
-# test for presence of SDL
-ifeq ("$(shell which sdl-config 2>&1 | head -c 9)", "which: no")
-  # throw error
-  $(error No SDL development libraries found!)
-endif
-
-# test for presence of GTK 2.0
-ifeq ("$(shell which pkg-config 2>&1 | head -c 9)", "which: no")
-  # throw error
-  $(error No GTK 2.x development libraries found!)
-endif
-ifneq ("$(shell pkg-config gtk+-2.0 --modversion | head -c 2)", "2.")
-  # throw error
-  $(error No GTK 2.x development libraries found!)
-endif
+# set assembler program
+ASM	?=	$(LOCALBASE)/bin/nasm
 
 # set GTK flags and libraries
 GTK_FLAGS	= `pkg-config gtk+-2.0 --cflags` -D_GTK2
@@ -55,36 +30,36 @@
 GTHREAD_LIBS	= `pkg-config gthread-2.0 --libs`
 
 # set base program pointers and flags
-CC      = gcc
-CXX     = g++
-LD      = g++
-STRIP   = strip --strip-all
-RM      = rm
-MV      = mv
-CP      = cp
-MD      = mkdir
-FIND    = find
-PROF    = gprof
-INSTALL = ginstall
+CC      ?= gcc
+CXX     ?= g++
+LD      ?= $(CXX)
+STRIP   ?= strip --strip-all
+RM      ?= rm
+MV      ?= mv
+CP      ?= cp
+MD      ?= mkdir
+FIND    ?= find
+PROF    ?= gprof
+INSTALL ?= ginstall
 
 # set base CFLAGS and LDFLAGS for all systems
-CFLAGS = -pipe -O3 -ffast-math -funroll-loops -fexpensive-optimizations -fno-strict-aliasing
-LDFLAGS =
+CFLAGS += -ffast-math -funroll-loops -fexpensive-optimizations -fno-strict-aliasing
+LDFLAGS +=
 
 # set special flags per-system
 ifeq ($(CPU), X86)
-  ifeq ($(ARCH), 64BITS)
-    CFLAGS += -march=athlon64
+  ifeq ($(ARCH_DETECTED), 64BITS)
+    CFLAGS += 
   else
-    CFLAGS += -march=i686 -mtune=pentium-m -mmmx -msse
+    CFLAGS += -mmmx -msse
     ifneq ($(PROFILE), 1)
       CFLAGS += -fomit-frame-pointer
     endif
   endif
   # tweak flags for 32-bit build on 64-bit system
-  ifeq ($(ARCH), 64BITS_32)
-    CFLAGS += -m32
-    LDFLAGS += -m32 -m elf_i386
+  ifeq ($(ARCH_DETECTED), 64BITS_32)
+    CFLAGS += 
+    LDFLAGS += 
   endif
 endif
 ifeq ($(CPU), PPC)
@@ -105,8 +80,8 @@
 
 # set CFLAGS, LIBS, and LDFLAGS for external dependencies
 
-SDL_FLAGS	= `sdl-config --cflags`
-SDL_LIBS	= `sdl-config --libs`
+SDL_FLAGS	= `${SDL_CONFIG} --cflags`
+SDL_LIBS	= `${SDL_CONFIG} --libs`
 
 AVIFILE_FLAGS	= `avifile-config --cflags`
 AVIFILE_LIBS	= `avifile-config --libs`
@@ -116,5 +91,5 @@
 
 PLUGIN_LDFLAGS	= -Wl,-Bsymbolic -shared
 
-LIBGL_LIBS	= -L/usr/X11R6/lib -lGL
+LIBGL_LIBS	= -L${LOCALBASE}/lib -lGL
 
