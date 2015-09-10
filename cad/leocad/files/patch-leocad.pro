--- leocad.pro.orig	2014-01-30 23:26:55 UTC
+++ leocad.pro
@@ -7,8 +7,7 @@ greaterThan(QT_MAJOR_VERSION, 4) {
 }
 
 INCLUDEPATH += qt common
-CONFIG += precompile_header incremental
-PRECOMPILED_HEADER = common/lc_global.h
+CONFIG += incremental
 win32 { 
 	QMAKE_CXXFLAGS_WARN_ON += -wd4100
 	DEFINES += _CRT_SECURE_NO_WARNINGS _CRT_SECURE_NO_DEPRECATE=1 _CRT_NONSTDC_NO_WARNINGS=1
