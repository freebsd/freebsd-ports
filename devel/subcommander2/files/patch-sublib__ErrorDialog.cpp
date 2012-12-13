--- sublib/ErrorDialog.cpp.orig	2007-08-19 22:04:03.000000000 +0900
+++ sublib/ErrorDialog.cpp	2012-05-10 05:49:27.000000000 +0900
@@ -219,6 +219,7 @@
 {
 }
 
+#if _WIN32
 static const char* copyString( const QString& s )
 {
   QByteArray qs = s.toLocal8Bit();
@@ -226,6 +227,7 @@
   strncpy( result, (const char*)qs, qs.length() );
   return result;
 }
+#endif
 
 void ErrorDialog::send()
 {
