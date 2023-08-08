--- src/gui/MainApplication.cpp.orig	2023-06-17 16:02:33 UTC
+++ src/gui/MainApplication.cpp
@@ -35,6 +35,18 @@
 	QApplication(argc, argv),
 	m_queuedFile()
 {
+#if !defined(LMMS_BUILD_WIN32) && !defined(LMMS_BUILD_APPLE) && !defined(LMMS_BUILD_HAIKU) && QT_VERSION >= 0x050000
+	// Work around a bug of KXmlGui < 5.55
+	// which breaks the recent files menu
+	// https://bugs.kde.org/show_bug.cgi?id=337491
+	for (auto child : children())
+	{
+		if (child->inherits("KCheckAcceleratorsInitializer"))
+		{
+			delete child;
+		}
+	}
+#endif
 #if defined(LMMS_BUILD_WIN32) && QT_VERSION >= 0x050000
 	installNativeEventFilter(this);
 #endif
