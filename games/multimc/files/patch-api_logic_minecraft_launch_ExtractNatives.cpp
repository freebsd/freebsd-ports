--- api/logic/minecraft/launch/ExtractNatives.cpp.orig	2017-12-18 00:19:43 UTC
+++ api/logic/minecraft/launch/ExtractNatives.cpp
@@ -23,6 +23,14 @@
 #include "FileSystem.h"
 #include <QDir>
 
+//C library defines interfere with Java version check
+#ifdef major
+    #undef major
+#endif
+#ifdef minor
+    #undef minor
+#endif
+
 static QString replaceSuffix (QString target, const QString &suffix, const QString &replacement)
 {
 	if (!target.endsWith(suffix))
