--- config.mk.orig	2012-04-19 19:06:22.083888852 +0600
+++ config.mk	2012-04-19 19:06:44.350893457 +0600
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
 
 # default CFLAGS
 CFLAGS ?= -g -O2
