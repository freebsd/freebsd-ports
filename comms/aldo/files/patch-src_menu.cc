--- src/menu.cc.orig	2012-03-31 11:32:34 UTC
+++ src/menu.cc
@@ -112,19 +112,19 @@ void Menu::add_item(id_type id, std::str
 
 void Menu::add_item_at(unsigned int pos, id_type id, std::string c, Function1 f)
 {
-    IT it(&m_its[pos]);
+    IT it(m_its.begin() + pos);
     m_its.insert(it, Item(id,c,f) );
 }
 
 void Menu::add_item_at(unsigned int pos, id_type id, std::string c, Function2 f)
 {
-    IT it(&m_its[pos]);
+    IT it(m_its.begin() + pos);
     m_its.insert(it, Item(id,c,f) );
 }
 
 void Menu::delete_item_at(unsigned int pos)
 {
-    IT it(&m_its[pos]);
+    IT it(m_its.begin() + pos);
     m_its.erase(it);
 }
 
