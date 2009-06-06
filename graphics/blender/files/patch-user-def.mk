--- user-def.mk.orig       1970-01-01 01:00:00.000000000 +0100
+++ user-def.mk    2009-06-01 12:32:18.000000000 +0200
@@ -0,0 +1,20 @@
+export NAN_DEBUG=
+
+export TYPE := $(shell echo `uname -s`)
+
+# Allow 64bit compiles.
+export NAN_YESIAMSTUPID=true
+
+export NAN_FMOD ?= /usr/local
+export NAN_OPENJPEG ?= /usr/local
+export NAN_FTGL ?= /usr/local
+export NAN_GLEW ?= /usr/local
+export NAN_OPENEXR ?= /usr/local
+export NAN_OPENEXR_LIBS ?= $(NAN_OPENEXR)/lib/libIlmImf.a \
+       $(NAN_OPENEXR)/lib/libHalf.a \
+       $(NAN_OPENEXR)/lib/libIex.a
+export NAN_ZLIB ?= /usr/local
+export NAN_ODE ?= /usr/local
+export NAN_FREETYPE ?= /usr/local
+export NAN_FFMPEGLIBS = %%FFMPEGLIBS%%
+export NAN_FFPMEGCFLAGS = %%FFMPEGCFLAGS%%
