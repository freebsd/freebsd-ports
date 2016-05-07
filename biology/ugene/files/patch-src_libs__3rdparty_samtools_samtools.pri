--- src/libs_3rdparty/samtools/samtools.pri.orig	2016-03-31 12:21:56 UTC
+++ src/libs_3rdparty/samtools/samtools.pri
@@ -3,7 +3,7 @@ UGENE_RELATIVE_DESTDIR = ''
 
 TEMPLATE = lib
 CONFIG +=thread debug_and_release staticlib warn_off
-INCLUDEPATH += src src/samtools ../../include /usr/include
+INCLUDEPATH += src src/samtools ../../include
 win32 : INCLUDEPATH += src/samtools/win32
 DEFINES+="_FILE_OFFSET_BITS=64" _LARGEFILE64_SOURCE _USE_KNETFILE
 win32 : DEFINES += _USE_MATH_DEFINES "inline=__inline" "__func__=__FUNCTION__" "R_OK=4" "atoll=_atoi64" "alloca=_alloca"
