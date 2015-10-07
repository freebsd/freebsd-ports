--- src/appleseed.studio/mainwindow/project/materialcollectionitem.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed.studio/mainwindow/project/materialcollectionitem.cpp
@@ -94,6 +94,7 @@ MaterialCollectionItem::MaterialCollecti
     add_items(materials);
 }
 
+#ifdef APPLESEED_WITH_DISNEY_MATERIAL
 const Material& MaterialCollectionItem::create_default_disney_material(const string& material_name)
 {
     auto_release_ptr<Material> material =
@@ -110,6 +111,7 @@ const Material& MaterialCollectionItem::
 
     return *material_ptr;
 }
+#endif // APPLESEED_WITH_DISNEY_MATERIAL
 
 QMenu* MaterialCollectionItem::get_single_item_context_menu() const
 {
