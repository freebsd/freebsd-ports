--- avmedia/source/qt6/QtPlayer.cxx.orig	2025-05-20 08:25:45 UTC
+++ avmedia/source/qt6/QtPlayer.cxx
@@ -41,6 +41,14 @@ using namespace ::com::sun::star;
 
 using namespace ::com::sun::star;
 
+namespace
+{
+inline OUString toOUString(const QString& s)
+{
+    return OUString(reinterpret_cast<const sal_Unicode*>(s.data()), s.length());
+}
+}
+
 namespace avmedia::qt
 {
 QtPlayer::QtPlayer()
