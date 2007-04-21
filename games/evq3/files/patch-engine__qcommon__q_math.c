--- ./engine/qcommon/q_math.c.orig	Tue Apr  3 21:05:30 2007
+++ ./engine/qcommon/q_math.c	Mon Apr 16 23:57:25 2007
@@ -651,7 +651,7 @@
 	y = y * (threehalfs - (x2 * y * y));	// 1st iteration
 //      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
 #ifndef Q3_VM
-#ifdef __linux__
+#ifdef __unix__
 	assert(!isnan(y));			// bk010122 - FPE?
 #endif
 #endif
@@ -819,7 +819,7 @@
 }
 
 
-#if !( (defined __linux__ || __FreeBSD__) && (defined __i386__) && (!defined C_ONLY))	// rb010123
+#if !( (defined __unix__) && (defined __i386__) && (!defined C_ONLY))	// rb010123
 
 #if defined __LCC__ || defined C_ONLY || !id386 || defined __VECTORC
 
