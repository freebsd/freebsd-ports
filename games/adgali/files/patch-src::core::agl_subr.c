--- src/core/agl_subr.c.orig	Sun May  4 07:20:06 2003
+++ src/core/agl_subr.c	Sat Jun 21 14:56:41 2003
@@ -103,8 +103,7 @@
 					type = NUMBER_TOKEN;
 					break;
 				default:
-					if isdigit
-						(c)
+					if (isdigit(c))
 					{
 						type = INT_TOKEN;
 						uval = c - '0';
@@ -120,8 +119,7 @@
 				}
 				else
 				{
-					if isdigit
-						(c)
+					if (isdigit(c))
 					{
 						type = INT_TOKEN;
 						uval = c - '0';
