--- sublib/CrashHandler.cpp.orig	2007-08-19 22:04:03.000000000 +0900
+++ sublib/CrashHandler.cpp	2012-05-10 05:56:28.000000000 +0900
@@ -22,6 +22,7 @@
 #endif // _WIN32
 
 
+#if _WIN32
 // helper
 static const char* copyString( const sc::String& src )
 {
@@ -37,6 +38,7 @@
   QString sbj = _q("%1 [%2] crashed...").arg(getLongAppName()).arg(SUBCOMMANDER_VERSION);
   return sc::String(sbj.toUtf8());
 }
+#endif
 
 static sc::String getMessage()
 {
