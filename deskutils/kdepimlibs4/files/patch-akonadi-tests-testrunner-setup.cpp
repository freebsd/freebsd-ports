--- ../akonadi/tests/testrunner/setup.cpp.orig	2009-01-31 17:51:35.000000000 +0100
+++ ../akonadi/tests/testrunner/setup.cpp	2009-01-31 20:19:24.000000000 +0100
@@ -50,9 +50,13 @@
 
   foreach(const QString& s, environment.keys()) {
     if (s != "HOME") {
+#if defined(Q_OS_FREEBSD) && __FreeBSD_version < 700038
+      unsetenv( s.toAscii() );
+#else
       if ( !unsetenv( s.toAscii() )) {
         return false;
       }
+#endif
     }
   }
 
