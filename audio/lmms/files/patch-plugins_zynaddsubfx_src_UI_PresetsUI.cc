--- plugins/zynaddsubfx/src/UI/PresetsUI.cc	2011-07-02 13:14:01.000000000 +0000
+++ plugins/zynaddsubfx/src/UI/PresetsUI.cc.new	2011-09-30 21:19:59.000000000 +0000
@@ -263,7 +263,7 @@
   pastebrowse->clear();
   p->rescanforpresets();
   
-  for (int i=0;i<presetsstore.presets.size();i++){
+  for (int i=0;i<(int)presetsstore.presets.size();i++){
      std::string name=presetsstore.presets[i].name;
      if(name.empty())
          continue;
