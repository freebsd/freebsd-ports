--- src/lib_radare2.pri.orig	2024-05-24 00:09:14 UTC
+++ src/lib_radare2.pri
@@ -78,8 +78,8 @@ win32 {
     equals(USE_PKGCONFIG, 1) {
         CONFIG += link_pkgconfig
        # PKGCONFIG += r_core
-        R2_INCLUDEPATH = "$$system("bash -c 'pkg-config --variable=includedir r_core'")/libr"
-        R2_INCLUDEPATH += "$$system("bash -c 'pkg-config --variable=includedir r_core'")/libr/sdb"
+        R2_INCLUDEPATH = "$$system("sh -c 'pkg-config --variable=includedir r_core'")/libr"
+        R2_INCLUDEPATH += "$$system("sh -c 'pkg-config --variable=includedir r_core'")/libr/sdb"
         INCLUDEPATH += $$R2_INCLUDEPATH
         LIBS += $$system("pkg-config --libs r_core")
     } else {
