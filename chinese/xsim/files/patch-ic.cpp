--- xsim/ic.cpp.orig	2007-08-12 15:43:13.000000000 +0200
+++ xsim/ic.cpp	2007-08-12 15:43:35.000000000 +0200
@@ -103,5 +103,5 @@
 
 int TIC::alive()
 {
-	return (int)im;
+	return (intptr_t)im;
 }
