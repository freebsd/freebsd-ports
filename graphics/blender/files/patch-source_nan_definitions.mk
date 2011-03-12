--- source/nan_definitions.mk.orig	2009-09-01 17:21:54.000000000 +0200
+++ source/nan_definitions.mk	2011-03-09 22:06:13.000000000 +0100
@@ -267,6 +267,12 @@
     export NAN_SDLLIBS ?= $(shell sdl-config --libs)
     export NAN_SDLCFLAGS ?= $(shell sdl-config --cflags)
 
+    ifeq ($(WITH_OPENEXR), true)
+      export NAN_OPENEXR ?= $(shell pkg-config --variable=prefix OpenEXR )
+      export NAN_OPENEXR_INC ?= $(shell pkg-config --cflags OpenEXR )
+      export NAN_OPENEXR_LIBS ?= $(addprefix ${NAN_OPENEXR}/lib/lib,$(addsuffix
+    endif
+
     # Uncomment the following line to use Mozilla inplace of netscape
     # CPPFLAGS +=-DMOZ_NOT_NET
     # Location of MOZILLA/Netscape header files...
