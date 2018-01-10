--- sfx2/source/control/emojiview.cxx.orig	2017-10-25 14:25:39 UTC
+++ sfx2/source/control/emojiview.cxx
@@ -104,12 +104,12 @@ void EmojiView::Populate()
     }
 
     // TODO::populate view using the orcus json parser
-    using node = orcus::json_document_tree::node;
+    using node = orcus::json::node;
 
     // default json config
     orcus::json_config config;
 
-    orcus::json_document_tree aEmojiInfo;
+    orcus::json::document_tree aEmojiInfo;
 
     // Load JSON string into a document tree.
     aEmojiInfo.load(msJSONData, config);
@@ -122,7 +122,7 @@ void EmojiView::Populate()
         orcus::pstring key = *it;
         node value = root.child(key);
 
-        if(value.type() == orcus::json_node_t::object)
+        if(value.type() == orcus::json::node_t::object)
         {
             // iterate each element to get the keys
             std::vector<orcus::pstring> aEmojiParams = value.keys();
