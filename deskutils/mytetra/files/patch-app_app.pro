--- app/app.pro.orig	2025-02-18 14:02:57 UTC
+++ app/app.pro
@@ -6,7 +6,7 @@ TARGET_OS=ANY_OS
 
 # Build type
 # "debug" or "release"
-BUILD_TYPE="debug"
+BUILD_TYPE=$$find(CONFIG, debug|release)
 
 # Enable console for Windows
 # 0 - disable, 1 - enable (this is for compile mytetra.exe and rename to mytetra_debug.exe)
@@ -54,13 +54,7 @@ QT = gui \
 CONFIG += qt \
     warn_on
 
-# If debug build
-equals(BUILD_TYPE, "debug") {
-  message(Is debug build)
-  CONFIG += debug
-} else {
-  message(Is release build)
-}
+message(Is $$first(BUILD_TYPE) build)
 
 # If Windows console enable
 equals(WINDOWS_CONSOLE_ENABLE, 1) {
@@ -92,7 +86,7 @@ INCLUDEPATH += $${_PRO_FILE_PWD_}/src
 contains(TARGET_OS, ANY_OS) {
   message(Building the any OS version...)
   SYSTEM_PROGRAM_NAME=mytetra
-  BINARY_INSTALL_PATH=/usr/local/bin
+  BINARY_INSTALL_PATH=$$PREFIX/bin
 }
 
 contains(TARGET_OS, MEEGO_OS){
@@ -116,7 +110,7 @@ message(Set installation directory for binary file to 
 target.path=$${BINARY_INSTALL_PATH}
 INSTALLS+=target
 
-desktop_file.path=/usr/share/applications
+desktop_file.path=$$PREFIX/share/applications
 contains(TARGET_OS, ANY_OS) {
   desktop_file.files=desktop/any/mytetra.desktop
 }
@@ -128,11 +122,11 @@ contains(TARGET_OS, ANDROID_OS) {
 }
 INSTALLS+=desktop_file
 
-icon_scalable_file.path=/usr/share/icons/hicolor/scalable/apps
+icon_scalable_file.path=$$PREFIX/share/icons/hicolor/scalable/apps
 icon_scalable_file.files=desktop/mytetra.svg
 INSTALLS+=icon_scalable_file
 
-icon_48_file.path=/usr/share/icons/hicolor/48x48/apps
+icon_48_file.path=$$PREFIX/share/icons/hicolor/48x48/apps
 icon_48_file.files=desktop/mytetra.png
 INSTALLS+=icon_48_file
 
