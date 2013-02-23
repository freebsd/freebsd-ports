--- config.mk.orig	2013-02-14 00:04:00.993386340 +0100
+++ config.mk	2013-02-14 00:04:51.942387392 +0100
@@ -6,12 +6,12 @@
 
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
 
 # default CFLAGS
