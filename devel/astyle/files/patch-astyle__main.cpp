--- astyle_main.cpp.orig	Thu Mar  7 08:22:30 2002
+++ astyle_main.cpp	Sat May  7 22:31:21 2005
@@ -267,7 +267,7 @@
     {
         manuallySetJavaStyle(formatter);
     }
-    else if ( IS_OPTIONS(arg, "t", "indent=tab=") )
+    else if ( IS_PARAM_OPTIONS(arg, "t", "indent=tab=") )
     {
         int spaceNum = 4;
         string spaceNumParam = GET_PARAMS(arg, "t", "indent=tab=");
@@ -275,7 +275,7 @@
             spaceNum = atoi(spaceNumParam.c_str());
         formatter.setTabIndentation(spaceNum, false);
     }
-    else if ( IS_OPTIONS(arg, "T", "force-indent=tab=") )
+    else if ( IS_PARAM_OPTIONS(arg, "T", "force-indent=tab=") )
     {
         int spaceNum = 4;
         string spaceNumParam = GET_PARAMS(arg, "T", "force-indent=tab=");
