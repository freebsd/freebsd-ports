--- src/mumble/CELTCodec.cpp.orig	2013-08-07 07:26:41.259860710 +0200
+++ src/mumble/CELTCodec.cpp	2013-08-07 07:27:58.905421337 +0200
@@ -64,6 +64,7 @@
 	alternatives << QString::fromLatin1("libcelt0.so.%1").arg(version);
 	alternatives << QString::fromLatin1("libcelt.so.%1").arg(version);
 	alternatives << QString::fromLatin1("celt.so.%1").arg(version);
+	alternatives << QString::fromLatin1("libcelt-mumble.so.%1").arg(version);
 #else
 	int cpuinfo[4];
 	__cpuid(cpuinfo, 1);

