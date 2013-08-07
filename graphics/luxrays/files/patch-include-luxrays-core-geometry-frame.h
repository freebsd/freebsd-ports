--- include/luxrays/core/geometry/frame.h.orig	2013-08-04 12:00:53.496371213 +0200
+++ include/luxrays/core/geometry/frame.h	2013-08-04 12:01:10.695167535 +0200
@@ -44,11 +44,11 @@
 		SetFromZ(z);
 	}
 
-	Frame(const Normal &z) {
+	Frame(const luxrays::Normal &z) {
 		SetFromZ(Vector(z));
 	}
 
-	void SetFromZ(const Normal &z) {
+	void SetFromZ(const luxrays::Normal &z) {
 		SetFromZ(Vector(z)); 
 	}
 
