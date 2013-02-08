--- ./src/plugins/android/androidsettingswidget.cpp.orig	2012-09-10 07:29:16.000000000 -0700
+++ ./src/plugins/android/androidsettingswidget.cpp	2012-09-15 15:10:10.396152998 -0700
@@ -345,6 +345,9 @@
 #elif defined(Q_OS_DARWIN)
     dir = QLatin1String("/opt/local/bin/ant");
     QLatin1String antApp("ant");
+#elif defined(Q_OS_FREEBSD)
+    dir = QLatin1String("/usr/local/bin/ant");
+    QLatin1String antApp("ant");
 #endif
     const QString file =
         QFileDialog::getOpenFileName(this, tr("Select ant Script"), dir, antApp);
