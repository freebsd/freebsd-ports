--- pool8.C.orig	Sun Jan  9 01:17:59 2000
+++ pool8.C	Sun Jan  9 01:18:18 2000
@@ -56,7 +56,7 @@
 
 void Pool8::Triangle( const Vec2 &vec )
 {
-static t[15] = {		1,
+static int t[15] = {		1,
 						-1, -2,
 					  2,  0,  3,
 				  -3,  4, -4, -5,
@@ -186,7 +186,7 @@
 
 void Pool9::Triangle( const Vec2 &vec )
 {
-static t[9] = {		1,
+static int t[9] = {		1,
 						 2,  3,
 					  4, -1,  5,
 				       6,  7,
