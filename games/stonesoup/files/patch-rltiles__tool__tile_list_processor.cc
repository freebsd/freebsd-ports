--- ./rltiles/tool/tile_list_processor.cc.orig	2013-09-30 20:32:00.000000000 +0200
+++ ./rltiles/tool/tile_list_processor.cc	2013-10-11 22:07:08.181888672 +0200
@@ -52,7 +52,7 @@
         ""
     };
 
-    if (m_sdir != "" || background && m_back_sdir != "")
+    if (m_sdir != "" || (background && m_back_sdir != ""))
     {
         vector<const char *> dirs;
         if (m_sdir != "")
