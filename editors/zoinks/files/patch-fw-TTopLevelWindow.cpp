--- ./fw/TTopLevelWindow.cpp.orig	2007-11-03 00:02:58.000000000 +0100
+++ ./fw/TTopLevelWindow.cpp	2007-11-03 00:03:17.000000000 +0100
@@ -91,8 +91,8 @@
 		}
 		
 		XClassHint* classHints = XAllocClassHint();
-		classHints->res_name = "Zoinks";
-		classHints->res_class = "ZOINKS";
+		classHints->res_name = (char *)"Zoinks";
+		classHints->res_class = (char *)"ZOINKS";
 		
 		int argc = 0;
 		char** argv = NULL;
