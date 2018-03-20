--- src/pfs/pfsutils.cpp.orig	2018-01-25 17:09:12 UTC
+++ src/pfs/pfsutils.cpp
@@ -57,7 +57,13 @@ string getColorspaceString(ColorSpace cs
         return "HLG YCbCr 2020";
     case CS_RGB2020:
         return "RGB2020";
+    case CS_YUV:
+        return "YUV";
+    case CS_Yxy:
+        return "Yxy";
+    default: ;
   }
+  return "(unknown)";
 }
 
 string intToString(int a){
