--- src/manage/agl_gramcode.c.orig	Thu Apr 17 06:15:13 2003
+++ src/manage/agl_gramcode.c	Sat Jun 21 14:55:49 2003
@@ -465,8 +465,7 @@
 					type = SKIP_TOKEN;
 					break;
 				default:
-					if isdigit
-						(c)
+					if (isdigit(c))
 					{
 						type = INT_TOKEN;
 						uval = c - '0';
@@ -600,8 +599,7 @@
 				}
 				else
 				{
-					if isdigit
-						(c)
+					if (isdigit(c))
 					{
 						type = INT_TOKEN;
 						uval = c - '0';
