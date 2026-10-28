--- dm/svd_linpack.cpp.orig	2001-07-18 23:40:38 UTC
+++ dm/svd_linpack.cpp
@@ -10,7 +10,9 @@
 #endif
 
 #include <stdio.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
+using namespace std;
 
 #ifdef __cplusplus
 extern "C" {
@@ -59,7 +61,7 @@ typedef double doublereal;
 typedef short int shortint;
 typedef float real;
 typedef double doublereal;
-typedef struct { real r, i; } complex;
+typedef struct { real r, i; } ccomplex; /* renamed from "complex" to avoid a collision with std::complex */
 typedef struct { doublereal r, i; } doublecomplex;
 typedef long int logical;
 typedef short int shortlogical;
@@ -177,7 +180,7 @@ union Multitype {	/* for multiple entry points */
 	/* longint j; */
 	real r;
 	doublereal d;
-	complex c;
+	ccomplex c;
 	doublecomplex z;
 	};
 
