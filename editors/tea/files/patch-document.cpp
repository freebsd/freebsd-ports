--- document.cpp.orig
+++ document.cpp
@@ -206,11 +206,11 @@
 
   qDebug() << "defined(Q_OS_WIN) || defined(Q_OS_OS2)";
 
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
 
   eol = "\n";
 
-  qDebug() << "Q_OS_LINUX";
+  qDebug() << "defined(Q_OS_LINUX) || defined(Q_OS_UNIX)";
 
 
 #elif defined(Q_OS_MAC)
