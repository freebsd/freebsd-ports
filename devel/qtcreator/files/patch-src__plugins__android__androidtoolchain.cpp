--- ./src/plugins/android/androidtoolchain.cpp.orig	2012-09-10 07:29:16.000000000 -0700
+++ ./src/plugins/android/androidtoolchain.cpp	2012-09-15 15:58:23.920133451 -0700
@@ -103,6 +103,8 @@
         "windows"
 #elif defined(Q_OS_MAC)
         "darwin-x86"
+#elif defined(Q_OS_FREEBSD)
+	"freebsd-x86"
 #endif
     );
 
