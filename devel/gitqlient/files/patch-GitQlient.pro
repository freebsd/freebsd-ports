--- GitQlient.pro.orig	2024-10-14 22:38:13 UTC
+++ GitQlient.pro
@@ -4,11 +4,6 @@ DEFINES += QT_DEPRECATED_WARNINGS
 QT += widgets core network gui
 DEFINES += QT_DEPRECATED_WARNINGS
 
-if (!exists(src/git/.git) || !exists(src/AuxiliarCustomWidgets/.git) || !exists(src/QLogger/.git) || !exists(src/QPinnableTabWidget/.git)) {
-    message("Submodule update:")
-    system(git submodule update --init --recursive)
-}
-
 unix:!macos {
    TARGET = gitqlient
    QMAKE_LFLAGS += -no-pie
@@ -57,19 +52,9 @@ OTHER_FILES += \
 OTHER_FILES += \
     $$PWD/LICENSE
 
-
-isEmpty(VERSION) {
-   VERSION = $$system(git describe --abbrev=0)
-   VERSION = $$replace(VERSION, "v", "")
-}
-
-!defined(GQ_SHA, var) {
-   GQ_SHA = $$system(git rev-parse --short HEAD)
-}
-
 DEFINES += \
-    VER=\\\"$$VERSION\\\" \
-    SHA_VER=\\\"$$GQ_SHA\\\"
+    VER=\\\"%%DISTVERSION%%\\\" \
+    SHA_VER=\\\"%%SHASHORT%%\\\"
 
 !win32-msvc* {
     debug {
