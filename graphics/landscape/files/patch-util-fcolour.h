--- util/fcolour.h.orig	2007-08-07 09:37:31.000000000 +0100
+++ util/fcolour.h	2007-08-07 09:37:53.000000000 +0100
@@ -42,11 +42,11 @@
 
 	fcolour blend(fcolour& c);
 
-	fcolour fcolour::operator+(fcolour c);
-	fcolour fcolour::operator-(fcolour c);
-	fcolour fcolour::operator*(float f);
-	fcolour fcolour::operator/(float f);
-	fcolour fcolour::operator*(fcolour c);
+	fcolour operator+(fcolour c);
+	fcolour operator-(fcolour c);
+	fcolour operator*(float f);
+	fcolour operator/(float f);
+	fcolour operator*(fcolour c);
 
 	static void exposure(fcolour& c, float exp=1.0);
 
