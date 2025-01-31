--- src/src.pro.orig	2025-01-23 11:34:32 UTC
+++ src/src.pro
@@ -18,7 +18,7 @@ windows: INCLUDEPATH += ../win64/zlib/include
 DEFINES += LIBSSH_STATIC SSH_NO_CPP_EXCEPTIONS
 
 windows: INCLUDEPATH += ../win64/zlib/include
-INCLUDEPATH += ../include ../include/freerdp2 ../include/winpr2
+INCLUDEPATH += \"/usr/local/include/freerdp2\" \"/usr/local/include/winpr2\" ../include ../include/freerdp2 ../include/winpr2
 
 !isEmpty(OPENSSL_ROOT_DIR) {
     INCLUDEPATH += $$clean_path($${OPENSSL_ROOT_DIR}/include)
@@ -53,8 +53,6 @@ windows {
 
         LIBS += -lOpenSLES
         FREERDP_CHANNEL_LIBS = ../*.$${QMAKE_EXTENSION_STATICLIB}
-    } else {
-        FREERDP_CHANNEL_LIBS = ../lib/freerdp2/*.$${QMAKE_EXTENSION_STATICLIB}
     }
 
     LIBS += -L../lib -lssh -lvncclient
