--- phoenix.pro.orig	2016-01-31 22:20:45 UTC
+++ phoenix.pro
@@ -31,7 +31,7 @@
 # QTPLUGIN  += qjpeg qsqlite
 
 
-CONFIG += debug_and_release
+CONFIG += release
 win32 {
 # release build using msvc 2010 needs to use Multi-threaded (/MT) for the code generation/runtime library option
 # release build using msvc 2010 needs to add msvcrt.lib;%(IgnoreSpecificDefaultLibraries) to the linker/no default libraries option
@@ -92,7 +92,7 @@ macx {
 unix {
     !macx { # unix is defined on mac
         HARDWARE_PLATFORM = $$system(uname -m)
-        contains( HARDWARE_PLATFORM, x86_64 ) {
+        contains( HARDWARE_PLATFORM, amd64 ) {
             DEFINES += LINUX_64
         } else {
             DEFINES += LINUX_32
@@ -101,7 +101,7 @@ unix {
     }
 
         isEmpty(PREFIX) {
-                PREFIX = /usr
+                PREFIX = /usr/local
         }
         BINDIR = $$PREFIX/bin
         DATADIR = $$PREFIX/share
@@ -114,11 +114,11 @@ unix {
         desktop.path = $$DATADIR/applications
         desktop.files += fritzing.desktop
 
-        manpage.path = $$DATADIR/man/man1
+        manpage.path = /usr/local/man/man1
         manpage.files += Fritzing.1
 
-        icon.path = $$DATADIR/icons
-        icon.extra = install -D -m 0644 $$PWD/resources/images/fritzing_icon.png $(INSTALL_ROOT)$$DATADIR/icons/fritzing.png
+        icon.path = $$DATADIR/icons/hicolor/64x64/apps
+        icon.extra = install -m 0644 $$PWD/resources/images/fritzing_icon.png $(INSTALL_ROOT)$$DATADIR/icons/hicolor/64x64/apps/fritzing.png
 
         parts.path = $$PKGDATADIR
         parts.files += parts
