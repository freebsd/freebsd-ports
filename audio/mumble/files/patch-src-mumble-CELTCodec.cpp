--- src/mumble/CELTCodec.cpp.orig	2019-03-20 19:21:57 UTC
+++ src/mumble/CELTCodec.cpp
@@ -40,6 +40,7 @@ CELTCodec::CELTCodec(const QString &celt_version) {
 	alternatives << QString::fromLatin1("libcelt0.so.%1").arg(celt_version);
 	alternatives << QString::fromLatin1("libcelt.so.%1").arg(celt_version);
 	alternatives << QString::fromLatin1("celt.so.%1").arg(celt_version);
+	alternatives << QString::fromLatin1("libcelt-mumble.so.%1").arg(celt_version);
 #else
 	int cpuinfo[4];
 	__cpuid(cpuinfo, 1);
