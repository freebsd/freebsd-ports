--- libraries/botan/botan.pri.orig	2025-06-01 19:29:53 UTC
+++ libraries/botan/botan.pri
@@ -59,8 +59,11 @@ unix:*-g++* {
     QMAKE_CXXFLAGS -= -Werror
 }
 
-linux*|freebsd* {
+linux {
     LIBS += -lrt $$QMAKE_LIBS_DYNLOAD
     DEFINES += BOTAN_TARGET_OS_HAS_GETAUXVAL
 }
+
+freebsd:DEFINES += BOTAN_TARGET_OS_HAS_CLOCK_GETTIME \
+    BOTAN_TARGET_OS_HAS_ELF_AUX_INFO BOTAN_TARGET_OS_HAS_POSIX1
 }
