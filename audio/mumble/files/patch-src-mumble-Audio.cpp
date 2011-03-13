--- ../mumble-1.2.3/src/mumble/Audio.cpp	2011-02-19 16:35:16.000000000 -0500
+++ src/mumble/Audio.cpp	2011-03-01 16:46:50.000000000 -0500
@@ -65,6 +65,7 @@
 		}
 	}
 
+#if defined(__FreeBSD__) && !defined(FREEBSD_SYSTEM_CELT)
 	codec = new CELTCodec080(QLatin1String("0.9.0"));
 	if (codec->isValid()) {
 		codec->report();
@@ -102,6 +103,7 @@
 			delete codec;
 		}
 	}
+#endif
 }
 
 void CodecInit::destroy() {
@@ -132,6 +134,10 @@
 	alternatives << QString::fromLatin1("celt0.%1.dylib").arg(version);
 	alternatives << QString::fromLatin1("libcelt.%1.dylib").arg(version);
 	alternatives << QString::fromLatin1("celt.%1.dylib").arg(version);
+#elif defined(__FreeBSD__) && defined(FREEBSD_SYSTEM_CELT)
+	alternatives << QString::fromLatin1("libcelt.so.0");
+#elif defined(__FreeBSD__)
+	alternatives << QString::fromLatin1("libcelt-mumble.so.%1").arg(version);
 #elif defined(Q_OS_UNIX)
 	alternatives << QString::fromLatin1("libcelt0.so.%1").arg(version);
 	alternatives << QString::fromLatin1("libcelt.so.%1").arg(version);
