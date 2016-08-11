--- src/mumble/CELTCodec.cpp.orig	2014-08-08 15:51:59 UTC
+++ src/mumble/CELTCodec.cpp
@@ -64,6 +64,7 @@ CELTCodec::CELTCodec(const QString &vers
 	alternatives << QString::fromLatin1("libcelt0.so.%1").arg(version);
 	alternatives << QString::fromLatin1("libcelt.so.%1").arg(version);
 	alternatives << QString::fromLatin1("celt.so.%1").arg(version);
+	alternatives << QString::fromLatin1("libcelt-mumble.so.%1").arg(version);
 #else
 	int cpuinfo[4];
 	__cpuid(cpuinfo, 1);
