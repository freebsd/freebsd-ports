--- relement.cpp.orig	Fri Nov  8 16:01:15 2002
+++ relement.cpp	Fri Nov  8 16:03:44 2002
@@ -3683,7 +3683,7 @@
 
   // Search pattern in /usr/share/<proj>/hatches dir:
   if(!QFileInfo(patternPath).exists()) {
-    patternPath = QString("/usr/share/")+DEF_APPNAME_L+"/hatches/"+_pattern+".dxf";
+    patternPath = QString("DATADIR")+DEF_APPNAME_L+"/hatches/"+_pattern+".dxf";
   }
 #endif
   */
