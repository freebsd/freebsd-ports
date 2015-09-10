--- rltiles/tool/tile_list_processor.cc.orig	2015-03-04 04:53:29 UTC
+++ rltiles/tool/tile_list_processor.cc
@@ -52,7 +52,7 @@ bool tile_list_processor::load_image(til
         ""
     };
 
-    if (m_sdir != "" || background && m_back_sdir != "")
+    if (m_sdir != "" || (background && m_back_sdir != ""))
     {
         vector<const char *> dirs;
         if (m_sdir != "")
