--- src/web/UBEmbedController.cpp.orig	2026-03-23 11:30:46 UTC
+++ src/web/UBEmbedController.cpp
@@ -150,7 +150,7 @@ void UBEmbedController::textChanged(const QString& new
     static const QRegularExpression regExp("[<>:\"/\\\\|?*]");
 #endif
 
-#ifdef Q_OS_LINUX // Defined on X11.
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) // Defined on X11/FreeBSD.
     QString illegalCharList("      < > : \" / \\ | ? * ");
     static const QRegularExpression regExp("[<>:\"/\\\\|?*]");
 #endif
