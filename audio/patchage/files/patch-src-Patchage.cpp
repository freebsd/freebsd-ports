--- src/Patchage.cpp.orig	2008-07-22 22:19:44.000000000 +0200
+++ src/Patchage.cpp	2008-07-22 22:22:20.000000000 +0200
@@ -342,6 +342,12 @@
 }
 
 
+static float
+log2f(float x)
+{
+	return (logf(x) / logf(2.0));
+}
+
 void
 Patchage::update_toolbar()
 {
