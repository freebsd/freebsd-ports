--- pre.mk	2009-01-09 00:29:06.000000000 -0500
+++ pre.mk	2009-01-09 00:51:15.000000000 -0500
@@ -21,26 +21,34 @@
 
 # detect system architecture: i386, x86_64, or PPC/PPC64
 UNAME = $(shell uname -m)
+ifeq ("$(UNAME)","amd64")
+  CPU = X86
+  ifeq ("$(BITS)", "32")
+    ARCH_DETECTED = 64BITS_32
+  else
+    ARCH_DETECTED = 64BITS
+  endif
+endif
 ifeq ("$(UNAME)","x86_64")
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
   NO_ASM = 1
 endif
 ifeq ("$(UNAME)","ppc64")
   CPU = PPC
-  ARCH = 64BITS
+  ARCH_DETECTED = 64BITS
   NO_ASM = 1
 endif
 
@@ -56,6 +64,9 @@
   OS = OSX
   LDFLAGS += -liconv -lpng
 endif
+ifeq ("$(UNAME)","FreeBSD")
+  OS = FREEBSD
+endif
 
 ifeq ($(OS),)
    $(warning OS not supported or detected, using default linux options.)
@@ -66,8 +77,9 @@
 ifeq ($(shell which sdl-config 2>/dev/null),)
   $(error No SDL development libraries found!)
 endif
-SDL_FLAGS	= $(shell sdl-config --cflags)
-SDL_LIBS	= $(shell sdl-config --libs)
+
+SDL_FLAGS	= `${SDL_CONFIG} --cflags`
+SDL_LIBS	= `${SDL_CONFIG} --libs`
 
 # test for presence of FreeType
 ifeq ($(shell which freetype-config 2>/dev/null),)
@@ -147,23 +159,26 @@
 endif
 
 # set base program pointers and flags
-CC      = gcc
-CXX     = g++
-LD      = g++
+CC      ?= gcc
+CXX     ?= g++
+LD      ?= g++
 ifeq ($(OS),LINUX)
-STRIP	= strip -s
+STRIP	?= strip -s
+endif
+ifeq ($(OS),FREEBSD)
+STRIP	?= strip -s
 endif
 ifeq ($(OS),OSX)
-STRIP	= strip -x 
+STRIP	?= strip -x 
 endif
-RM      = rm
-RM_F    = rm -f
-MV      = mv
-CP      = cp
-MD      = mkdir
-FIND    = find
-PROF    = gprof
-INSTALL = ginstall
+RM      ?= rm
+RM_F    ?= rm -f
+MV      ?= mv
+CP      ?= cp
+MD      ?= mkdir
+FIND    ?= find
+PROF    ?= gprof
+INSTALL ?= ginstall
 
 # create SVN version defines
 MUPEN_RELEASE = 1.5
@@ -185,23 +200,40 @@
 endif
 
 # set base CFLAGS and LDFLAGS
-CFLAGS += -pipe -O3 -ffast-math -funroll-loops -fexpensive-optimizations -fno-strict-aliasing
-CORE_LDFLAGS += -lz -lm -lpng -lfreetype -ldl
+CFLAGS += -ffast-math -funroll-loops -fexpensive-optimizations -fno-strict-aliasing
+ifeq ($(OS), FREEBSD)
+  CORE_LDFLAGS += -lz -lm -lpng -lfreetype
+else
+  CORE_LDFLAGS += -lz -lm -lpng -lfreetype -ldl
+endif
 
 # set special flags per-system
 ifeq ($(CPU), X86)
-  ifeq ($(ARCH), 64BITS)
-    CFLAGS += -march=athlon64
+  ifeq ($(ARCH_DETECTED), 64BITS)
+    ifeq ($(OS), FREEBSD)
+      CFLAGS +=
+    else
+      CFLAGS += -march=athlon64
+    endif
   else
-    CFLAGS += -march=i686 -mtune=pentium-m -mmmx -msse
+    ifeq ($(OS), FREEBSD)
+      CFLAGS += -mmmx -msse
+    else
+      CFLAGS += -march=i686 -mtune=pentium-m -mmmx -msse
+    endif
     ifneq ($(PROFILE), 1)
       CFLAGS += -fomit-frame-pointer
     endif
   endif
   # tweak flags for 32-bit build on 64-bit system
-  ifeq ($(ARCH), 64BITS_32)
-    CFLAGS += -m32
-    LDFLAGS += -m32 -m elf_i386
+  ifeq ($(ARCH_DETECTED), 64BITS_32)
+    ifeq ($(OS), FREEBSD)
+      CFLAGS += 
+      LDFLAGS += 
+    else
+      CFLAGS += -m32
+      LDFLAGS += -m32 -m elf_i386
+    endif
   endif
 endif
 ifeq ($(CPU), PPC)
@@ -209,6 +241,9 @@
 endif
 
 # set CFLAGS, LIBS, and LDFLAGS for external dependencies
+ifeq ($(OS),FREEBSD)
+  PLUGIN_LDFLAGS	= -Wl,-Bsymbolic -shared
+endif
 ifeq ($(OS),LINUX)
   PLUGIN_LDFLAGS	= -Wl,-Bsymbolic -shared
 endif
@@ -216,6 +251,9 @@
   PLUGIN_LDFLAGS	= -bundle
 endif
 
+ifeq ($(OS),FREEBSD)
+  LIBGL_LIBS	= -L${LOCALBASE}/lib -lGL -lGLU
+endif
 ifeq ($(OS),LINUX)
   LIBGL_LIBS	= -L/usr/X11R6/lib -lGL -lGLU
 endif
