--- splat.cpp.orig	2010-03-21 09:53:44.000000000 -0400
+++ splat.cpp	2010-03-21 09:54:01.000000000 -0400
@@ -2586,7 +2586,7 @@
 
 			if (fgets(string,80,fd)!=NULL)
 			{
-				pointer=strchr(string,':');
+				pointer=strchr(string,';');
 
 				if (pointer!=NULL)
 					*pointer=0;
