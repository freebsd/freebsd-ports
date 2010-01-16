--- src/mumble/Audio.cpp.orig	2010-01-08 00:37:46.000000000 +0200
+++ src/mumble/Audio.cpp	2010-01-11 01:24:46.000000000 +0200
@@ -49,6 +49,7 @@ CodecInit ciInit;
 void CodecInit::initialize() {
 	CELTCodec *codec = NULL;
 
+#ifndef __FreeBSD__
 	codec = new CELTCodec061(QLatin1String("0.6.1"));
 	if (codec->isValid()) {
 		codec->report();
@@ -64,6 +65,7 @@ void CodecInit::initialize() {
 	} else {
 		delete codec;
 	}
+#endif
 
 	codec = new CELTCodec070(QLatin1String("0.7.0"));
 	if (codec->isValid()) {
@@ -105,6 +107,8 @@ CELTCodec::CELTCodec(const QString &vers
 #if defined(Q_OS_MAC)
 	alternatives << QString::fromLatin1("celt.%1.dylib").arg(version);
 	alternatives << QString::fromLatin1("libcelt.%1.dylib").arg(version);
+#elif defined(__FreeBSD__)
+	alternatives << QString::fromLatin1("libcelt.so.0");
 #elif defined(Q_OS_UNIX)
 	alternatives << QString::fromLatin1("celt.so.%1").arg(version);
 	alternatives << QString::fromLatin1("libcelt.so.%1").arg(version);
