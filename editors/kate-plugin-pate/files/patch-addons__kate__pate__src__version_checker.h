--- addons/kate/pate/src/version_checker.h.orig	2014-09-16 02:55:37.897246249 +0200
+++ addons/kate/pate/src/version_checker.h	2014-09-16 02:58:31.732234283 +0200
@@ -24,6 +24,13 @@
 # include <QtCore/QStringList>
 # include <QtCore/QtGlobal>
 
+# ifdef major
+#  undef major
+# endif
+# ifdef minor
+#  undef minor
+# endif
+
 namespace Pate {
 
 /**
