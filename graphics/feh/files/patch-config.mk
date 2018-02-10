s--- config.mk.orig	2017-12-28 18:28:35 UT2
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
