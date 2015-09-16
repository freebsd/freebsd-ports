--- src/data/file.cpp.orig	2015-08-09 18:14:19 UTC
+++ src/data/file.cpp
@@ -42,8 +42,8 @@ const QString File::ProtectCasing = QLat
 const QString File::NameFormatting = QLatin1String("NameFormatting");
 const QString File::ListSeparator = QLatin1String("ListSeparator");
 
-const quint64 valid = 0x08090a0b0c0d0e0f;
-const quint64 invalid = 0x0102030405060708;
+const quint64 valid = Q_UINT64_C(0x08090a0b0c0d0e0f);
+const quint64 invalid = Q_UINT64_C(0x0102030405060708);
 
 class File::FilePrivate
 {
