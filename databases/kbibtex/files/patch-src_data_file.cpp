--- src/data/file.cpp.orig	2023-01-12 18:57:44 UTC
+++ src/data/file.cpp
@@ -44,8 +44,8 @@ const QString File::ListSeparator = QStringLiteral("Li
 const QString File::NameFormatting = QStringLiteral("NameFormatting");
 const QString File::ListSeparator = QStringLiteral("ListSeparator");
 
-const quint64 valid = 0x08090a0b0c0d0e0f;
-const quint64 invalid = 0x0102030405060708;
+const quint64 valid = Q_UINT64_C(0x08090a0b0c0d0e0f);
+const quint64 invalid = Q_UINT64_C(0x0102030405060708);
 
 class File::FilePrivate
 {
