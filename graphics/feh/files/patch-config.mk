--- config.mk.orig	2017-12-28 18:28:35 UTC
+++ config.mk
@@ -22,12 +22,12 @@ endif
 
 # Directories for manuals, executables, docs, data, etc.
 main_dir = ${DESTDIR}${PREFIX}
-man_dir = ${main_dir}/share/man
+man_dir = ${main_dir}/man
 bin_dir = ${main_dir}/bin
 doc_dir = ${main_dir}/share/doc/feh
 image_dir = ${main_dir}/share/feh/images
 font_dir = ${main_dir}/share/feh/fonts
-example_dir = ${main_dir}/share/doc/feh/examples
+example_dir = ${main_dir}/share/examples/feh
 desktop_dir = ${main_dir}/share/applications
 icon_dir = ${ICON_PREFIX}/hicolor
 48_icon_dir = ${icon_dir}/48x48/apps
@@ -38,7 +38,7 @@ CFLAGS ?= -g -O2
 CFLAGS += -Wall -Wextra -pedantic
 
 # Settings for glibc >= 2.19 - may need to be adjusted for other systems
-CFLAGS += -std=c11 -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=500
+CFLAGS += -std=c11
 
 ifeq (${curl},1)
 	CFLAGS += -DHAVE_LIBCURL
