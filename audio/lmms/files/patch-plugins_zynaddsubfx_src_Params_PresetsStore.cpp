--- plugins/zynaddsubfx/src/Params/PresetsStore.cpp.orig	2011-10-04 13:25:02.000000000 +0000
+++ plugins/zynaddsubfx/src/Params/PresetsStore.cpp	2011-10-04 13:26:03.000000000 +0000
@@ -167,7 +167,7 @@
 bool PresetsStore::pastepreset(XMLwrapper *xml, int npreset)
 {
     npreset--;
-    if(npreset >= presets.size())
+    if(npreset >= (int)presets.size())
         return false;
     string filename = presets[npreset].file;
     if(filename.empty())
@@ -179,7 +179,7 @@
 void PresetsStore::deletepreset(int npreset)
 {
     npreset--;
-    if(npreset >= presets.size())
+    if(npreset >= (int)presets.size())
         return;
     string filename = presets[npreset].file;
     if(filename.empty())
