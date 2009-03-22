--- user-def.mk.orig	2009-03-07 12:58:21.000000000 +0100
+++ user-def.mk	2009-03-07 13:30:16.000000000 +0100
@@ -0,0 +1,26 @@
+export NAN_DEBUG=
+
+export TYPE := $(shell echo `uname -s`)
+
+# Allow 64bit compiles.
+export NAN_YESIAMSTUPID=true
+
+export NAN_PYTHON ?= /usr/local
+export NAN_PYTHON_VERSION ?= 2.5
+export NAN_OPENAL ?= /usr/local
+export NAN_FMOD ?= /usr/local
+export NAN_FTGL ?= /usr/local
+export NAN_JPEG ?= /usr/local
+export NAN_PNG ?= /usr/local
+export NAN_GLEW ?= /usr/local
+export NAN_OPENEXR ?= /usr/local
+export NAN_OPENEXR_LIBS ?= $(NAN_OPENEXR)/lib/libIlmImf.a \
+	$(NAN_OPENEXR)/lib/libHalf.a \
+	$(NAN_OPENEXR)/lib/libIex.a
+export NAN_ZLIB ?= /usr/local
+export NAN_ODE ?= /usr/local
+export NAN_MESA = /export/scratch/crap/Mesa-6.2.1
+export NAN_NSPR = /export/scratch/blender/src/nspr-4.2.2/mozilla/nsprpub/dist
+export NAN_FREETYPE ?= /usr/local
+export NAN_FFMPEGLIBS = %%FFMPEGLIBS%%
+export NAN_FFPMEGCFLAGS = %%FFMPEGCFLAGS%%
