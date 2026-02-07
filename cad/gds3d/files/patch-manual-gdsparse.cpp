- workaround for error: reference to 'byte' is ambiguous, see https://github.com/trilomix/GDS3D/issues/23

--- ../libgdsto3d/gdsparse.cpp.orig	2023-07-20 10:59:11.684448000 -0700
+++ ../libgdsto3d/gdsparse.cpp	2023-07-20 10:59:35.325794000 -0700
@@ -127,7 +127,7 @@
 
 bool GDSParse::ParseFile(char *topcell)
 {
-	byte recordtype, datatype;
+	::byte recordtype, datatype;
 	char *tempstr;
 	//struct ProcessLayer *layer = NULL;
     
@@ -1086,7 +1086,7 @@
 
 short GDSParse::GetBitArray()
 {
-	byte byte1;
+	::byte byte1;
 
 	fread(&byte1, 1, 1, _iptr);
 	fread(&byte1, 1, 1, _iptr);
@@ -1097,8 +1097,8 @@
 
 double GDSParse::GetEightByteReal()
 {
-	byte value;
-	byte b8, b2, b3, b4, b5, b6, b7;
+	::byte value;
+	::byte b8, b2, b3, b4, b5, b6, b7;
 	double sign=1.0;
 	double exponent;
 	double mant;
