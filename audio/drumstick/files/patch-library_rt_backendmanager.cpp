--- library/rt/backendmanager.cpp.orig	2016-09-24 21:08:23 UTC
+++ library/rt/backendmanager.cpp
@@ -140,7 +140,7 @@ namespace rt {
         d->appendDir( appPath + QStringLiteral("../PlugIns/") + QSTR_DRUMSTICK, result );
     #endif // Linux, Unix...
         QStringList libs;
-        libs << "../lib/" << "../lib32/" << "../lib64/";
+        libs << "../lib/";
         foreach(const QString& lib, libs) {
             d->appendDir( appPath + lib + QSTR_DRUMSTICK, result );
         }
