--- src/formats.cpp.orig	2014-08-20 19:25:29.000000000 +0200
+++ src/formats.cpp	2014-08-20 19:26:13.000000000 +0200
@@ -36,7 +36,7 @@
 
 void Formats::loadFormats()
 {
-#ifdef Q_OS_LINUX || Q_OS_FREEBSD
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     list<CoderInfo> coderList;
     coderInfoList(&coderList,
                   CoderInfo::TrueMatch,
