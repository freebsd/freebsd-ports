--- src/appleseed.studio/mainwindow/project/objectinstanceitem.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed.studio/mainwindow/project/objectinstanceitem.cpp
@@ -124,8 +124,10 @@ QMenu* ObjectInstanceItem::get_single_it
 {
     QMenu* menu = ItemBase::get_single_item_context_menu();
 
+#ifdef APPLESEED_WITH_DISNEY_MATERIAL
     menu->addSeparator();
     menu->addAction("Assign New Disney Material", this, SLOT(slot_assign_new_disney_material()));
+#endif // APPLESEED_WITH_DISNEY_MATERIAL
 
     menu->addSeparator();
     menu->addAction("Assign Materials...", this, SLOT(slot_open_material_assignment_editor()));
@@ -168,15 +170,18 @@ QMenu* ObjectInstanceItem::get_multiple_
 
     QMenu* menu = ItemBase::get_multiple_items_context_menu(items);
 
+#ifdef APPLESEED_WITH_DISNEY_MATERIAL
     menu->addSeparator();
     menu->addAction("Assign New Disney Material", this, SLOT(slot_assign_new_disney_material()))
         ->setData(QVariant::fromValue(items));
+#endif // APPLESEED_WITH_DISNEY_MATERIAL
 
     add_material_assignment_menu_actions(menu, items);
 
     return menu;
 }
 
+#ifdef APPLESEED_WITH_DISNEY_MATERIAL
 // Friend of ObjectInstanceItem class, thus cannot be placed in anonymous namespace.
 class AssignNewDisneyMaterialAction
   : public RenderingManager::IScheduledAction
@@ -255,12 +260,15 @@ class AssignNewDisneyMaterialAction
     EntityEditorContext&    m_editor_context;
     const QList<ItemBase*>  m_items;
 };
+#endif // APPLESEED_WITH_DISNEY_MATERIAL
 
 void ObjectInstanceItem::slot_assign_new_disney_material()
 {
+#ifdef APPLESEED_WITH_DISNEY_MATERIAL
     m_editor_context.m_rendering_manager.schedule_or_execute(
         auto_ptr<RenderingManager::IScheduledAction>(
             new AssignNewDisneyMaterialAction(m_editor_context, get_action_items())));
+#endif // APPLESEED_WITH_DISNEY_MATERIAL
 }
 
 void ObjectInstanceItem::slot_open_material_assignment_editor()
