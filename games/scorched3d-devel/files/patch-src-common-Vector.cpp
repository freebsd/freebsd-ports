--- ./src/common/Vector.cpp.orig	Wed Jun  2 19:35:42 2004
+++ ./src/common/Vector.cpp	Fri Feb 25 09:47:57 2005
@@ -105,15 +105,22 @@
 
 Vector Vector::operator/(const float a)
 {
-	Vector v(V[0]/a, V[1]/a, V[2]/a);
+	const float b = (a==0.0f?0.00001f:a);
+	Vector v(V[0]/b, V[1]/b, V[2]/b);
 	return v;
 }
 
 Vector Vector::operator/(const Vector &Vin)
 {
-	Vector v(V[0]/ ((Vector &) Vin)[0], 
-			V[1]/ ((Vector &) Vin)[1], 
-			V[2]/ ((Vector &) Vin)[2]);
+	float a = ((Vector &)Vin)[0];
+	float b = ((Vector &)Vin)[1];
+	float c = ((Vector &)Vin)[2];
+
+	const float a2 = (a==0.0f?0.00001f:a);
+	const float b2 = (b==0.0f?0.00001f:b);
+	const float c2 = (c==0.0f?0.00001f:c);
+
+	Vector v(V[0]/ a2, V[1]/ b2, V[2]/ c2);
 	return v;
 }
 
@@ -152,10 +159,8 @@
 {
 	float mag = Magnitude();
 	Vector v;
-	if (mag != 0.0f)
-	{
-		v = (*this) / mag;
-	}
+	if (mag == 0.0f) mag = 0.00001f;
+	v = (*this) / mag;
 	return v;
 }
 
@@ -163,10 +168,8 @@
 {
 	float mag = float(sqrt(V[0]*V[0] + V[1]*V[1]));
 	Vector v;
-	if (mag != 0.0f)
-	{
-		v = (*this) / mag;
-	}
+	if (mag == 0.0f) mag = 0.00001f;
+	v = (*this) / mag;
 	return v;
 }
 
@@ -185,10 +188,8 @@
 void Vector::StoreNormalize()
 {
 	float mag = Magnitude();
-	if (mag != 0.0f)
-	{
-		(*this) /= mag;
-	}
+	if (mag == 0.0f) mag = 0.00001f;
+	(*this) /= mag;
 }
 
 float Vector::dotP(const Vector &Vin)
@@ -233,16 +234,25 @@
 
 void Vector::operator/=(const float a)
 {
-	V[0] /= a;
-	V[1] /= a;
-	V[2] /= a;
+	const float b = (a==0.0f?0.00001f:a);
+	V[0] /= b;
+	V[1] /= b;
+	V[2] /= b;
 }
 
 void Vector::operator/=(const Vector &Vin)
 {
-	V[0] /= ((Vector &)Vin)[0];
-	V[1] /= ((Vector &)Vin)[1];
-	V[2] /= ((Vector &)Vin)[2];
+	float a = ((Vector &)Vin)[0];
+	float b = ((Vector &)Vin)[1];
+	float c = ((Vector &)Vin)[2];
+
+	const float a2 = (a==0.0f?0.00001f:a);
+	const float b2 = (b==0.0f?0.00001f:b);
+	const float c2 = (c==0.0f?0.00001f:c);
+
+	V[0] /= a2;
+	V[1] /= b2;
+	V[2] /= c2;
 }
 
 void Vector::operator+=(const float a)
