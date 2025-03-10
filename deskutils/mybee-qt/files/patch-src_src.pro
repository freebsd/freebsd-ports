--- src/src.pro.orig	2025-02-16 18:06:21 UTC
+++ src/src.pro
@@ -15,7 +15,8 @@ DEFINES += LIBSSH_STATIC SSH_NO_CPP_EXCEPTIONS
 CONFIG += file_copies lrelease embed_translations
 
 DEFINES += LIBSSH_STATIC SSH_NO_CPP_EXCEPTIONS
-INCLUDEPATH += ../include ../include/freerdp2 ../include/winpr2
+#INCLUDEPATH += ../include ../include/freerdp2 ../include/winpr2
+INCLUDEPATH += \"/usr/local/include/freerdp2\" \"/usr/local/include/freerdp2/freerdp/client\"  \"/usr/local/include/winpr2\" ../include ../include/freerdp2 ../include/winpr2
 
 !isEmpty(OPENSSL_ROOT_DIR) {
     INCLUDEPATH += $$clean_path($${OPENSSL_ROOT_DIR}/include)
@@ -63,10 +64,10 @@ windows {
 
 } else { # any other unix & linux
 
-    LIBS += ../lib/libssh.a ../lib/libvncclient.a
-    LIBS += ../lib/libfreerdp-client2.a ../lib/freerdp2/lib*.a ../lib/libfreerdp2.a ../lib/libwinpr2.a
-    LIBS += ../lib/libturbojpeg.a ../lib/libz.a
-    LIBS += -lssl -lcrypto -ldl -lutil
+#    LIBS += /usr/local/lib/libssh.a ../lib/libvncclient.a
+#    LIBS += ../lib/libfreerdp-client2.a ../lib/freerdp2/lib*.a ../lib/libfreerdp2.a ../lib/libwinpr2.a
+#    LIBS += ../lib/libturbojpeg.a ../lib/libz.a
+    LIBS += -lssl -lcrypto -ldl -lutil -lturbojpeg -lz-ng -lssh -lfreerdp-client2 -lfreerdp2 -lwinpr2 -lvncclient -lz
 }
 
 SOURCES += \
