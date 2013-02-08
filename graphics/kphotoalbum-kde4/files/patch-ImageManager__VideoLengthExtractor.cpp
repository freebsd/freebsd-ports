--- ./ImageManager/VideoLengthExtractor.cpp.orig	2012-09-25 17:40:43.000000000 +0200
+++ ./ImageManager/VideoLengthExtractor.cpp	2013-01-06 03:18:46.827523021 +0100
@@ -32,6 +32,18 @@
 #  define Debug if(0) qDebug
 #endif
 
+/*
+ * As in Utilities/Process.cpp, <KDebug> pulls in <stdio.h> which defines 
+ * stdout/stderr to __stdoutp/__stderrp which is obviously not what is
+ * intended here.
+ */
+#ifdef stdout
+#  undef stdout
+#endif
+#ifdef stderr
+#  undef stderr
+#endif
+
 ImageManager::VideoLengthExtractor::VideoLengthExtractor(QObject *parent) :
     QObject(parent), m_process(0)
 {
