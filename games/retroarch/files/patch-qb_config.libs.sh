--- qb/config.libs.sh.orig	2015-07-19 09:50:27 UTC
+++ qb/config.libs.sh
@@ -31,6 +31,9 @@ fi
 
 add_define_make DYLIB_LIB "$DYLIB"
 
+add_include_dirs /usr/local/include
+add_library_dirs /usr/local/lib
+
 [ "$OS" = 'Darwin' ] && HAVE_X11=no # X11 breaks on recent OSXes even if present.
 
 [ -d /opt/vc/lib ] && add_library_dirs /opt/vc/lib
@@ -125,11 +128,11 @@ fi
    add_define_make libretro "$LIBRETRO"
 }
 
-if [ "$MAN_DIR" ]; then
+#if [ "$MAN_DIR" ]; then
    add_define_make MAN_DIR "$MAN_DIR"
-else
-   add_define_make MAN_DIR "${PREFIX}/share/man/man1"
-fi
+#else
+   add_define_make MAN_DIR "${PREFIX}/man/man1"
+#fi
 
 if [ "$OS" = 'Win32' ]; then
    HAVE_THREADS=yes
@@ -182,7 +185,7 @@ fi
 check_pkgconf ALSA alsa
 check_header OSS sys/soundcard.h
 check_header OSS_BSD soundcard.h
-check_lib OSS_LIB -lossaudio
+#check_lib OSS_LIB -lossaudio
 
 if [ "$OS" = 'Darwin' ]; then
    check_lib AL "-framework OpenAL" alcOpenDevice
