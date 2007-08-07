--- user-def.mk.orig	1969-12-31 14:00:00.000000000 -1000
+++ user-def.mk	2007-08-07 00:38:53.000000000 -0800
@@ -0,0 +1,74 @@
+export NAN_DEBUG=-g
+
+export TYPE := $(shell echo `uname -s`)
+
+# Allow 64bit compiles.
+export NAN_YESIAMSTUPID=true
+
+ifeq ($(TYPE), SunOS)
+	export NAN_PYTHON=/usr/local
+	export NAN_PYTHON_VERSION=2.5
+	export NAN_OPENAL=/export/scratch/blender/src/openal/SunOS5.8
+	export NAN_JPEG=/usr/local
+	export NAN_PNG=/usr/local
+	export NAN_SDL=/usr/local
+	export NAN_SDLLIBS ?= $(shell $(NAN_SDL)/bin/sdl-config --libs) -lSDL_mixer
+	export NAN_OPENEXR=/usr/local
+        export NAN_OPENEXR_LIBS ?= $(NAN_OPENEXR)/lib/libIlmImf.a \
+		$(NAN_OPENEXR)/lib/libIlmThread.a \
+		$(NAN_OPENEXR)/lib/libHalf.a \
+		$(NAN_OPENEXR)/lib/libIex.a
+
+	export NAN_ZLIB=/usr/local
+	export NAN_FREETYPE=/usr/local
+	export NAN_MOZILLA_INC=/usr/local/include/mozilla-1.0.1/
+	export NAN_MOZILLA_LIB=/usr/local/lib/mozilla-1.0.1/
+	export NAN_NSPR=/export/scratch/blender/SunOS5.8
+	export NAN_GETTEXT=/opt/gnu
+	export WITH_FREETYPE2=true
+	export INTERNATIONAL=true
+	export EXPYTHON=true
+	export WITH_BF_GAMEPLAYER=true
+	export NAN_NO_PLUGIN=true
+#	export NAN_NO_KETSJI=true
+	export WITH_FFMPEG=true
+#	export NAN_FFMPEG=/export/scratch/blender/src/lib/solaris-2.8-sparc/ffmpeg
+	export NAN_ICONV_LIBS=-L/opt/gnu/lib -R/opt/gnu/lib -liconv
+	export WITH_ICONV=false
+else
+	export WITH_ICONV=false
+#	export WITH_FFMPEG=true
+	export WITH_FFMPEG=false
+	export NAN_PYTHON=/usr/local
+	export NAN_PYTHON_VERSION=2.5
+	export NAN_OPENAL=/usr
+	export NAN_FMOD=/usr/local
+	export NAN_JPEG=/usr/local
+	export NAN_PNG=/usr/local
+	export WITH_OPENEXR=true
+#	export NAN_OPENEXR=/usr/local
+	export NAN_OPENEXR=/usr/local
+        export NAN_OPENEXR_LIBS ?= $(NAN_OPENEXR)/lib/libIlmImf.a \
+		$(NAN_OPENEXR)/lib/libHalf.a \
+		$(NAN_OPENEXR)/lib/libIex.a
+
+#		$(NAN_OPENEXR)/lib/libIlmThread.a \
+
+	export NAN_SDL=/export/scratch/blender/src/lib/linux-glibc2.2.5-i386/sdl
+	export NAN_ODE=/export/scratch/blender/src/blender/extern/ode/dist
+	export NAN_ZLIB=/usr/local
+#	export NAN_FREETYPE=/usr
+	export NAN_MESA=/export/scratch/crap/Mesa-6.2.1
+	export NAN_MOZILLA_INC=/usr/include/mozilla/
+	export NAN_MOZILLA_LIB=/usr/lib/mozilla/
+	# I think it only needs includes so should be alright...
+	export NAN_NSPR=/export/scratch/blender/src/nspr-4.2.2/mozilla/nsprpub/dist
+
+	export WITH_FREETYPE2=true
+	export INTERNATIONAL=true
+	export NAN_NO_STATIC = true
+	export NAN_NO_PLUGIN=true
+endif
+
+export WITH_VERSE=true
+export WITH_BULLET=true
