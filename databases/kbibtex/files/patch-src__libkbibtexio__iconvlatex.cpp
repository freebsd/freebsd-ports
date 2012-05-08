--- ./src/libkbibtexio/iconvlatex.cpp.orig	2012-05-05 10:50:42.000000000 +0000
+++ ./src/libkbibtexio/iconvlatex.cpp	2012-05-06 00:53:04.285249457 +0000
@@ -58,7 +58,7 @@
 QByteArray IConvLaTeX::encode(const QString &input)
 {
     QByteArray inputByteArray = input.toUtf8();
-#ifdef Q_WS_WIN
+#ifndef Q_OS_LINUX
     /// iconv on Windows likes to have it as const char *
     const char *inputBuffer = inputByteArray.data();
 #else
