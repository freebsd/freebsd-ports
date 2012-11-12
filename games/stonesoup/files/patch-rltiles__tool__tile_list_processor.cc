--- ./rltiles/tool/tile_list_processor.cc.orig	2012-09-30 23:25:33.000000000 +0200
+++ ./rltiles/tool/tile_list_processor.cc	2012-10-27 20:49:08.847233795 +0200
@@ -51,7 +51,7 @@
         ""
     };
 
-    if (m_sdir != "" || background && m_back_sdir != "")
+    if (m_sdir != "" || (background && m_back_sdir != ""))
     {
         std::vector<const char *> dirs;
         if (m_sdir != "")
