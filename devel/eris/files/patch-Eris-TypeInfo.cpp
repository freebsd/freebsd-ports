--- Eris/TypeInfo.cpp.orig	Mon Oct  3 18:22:17 2005
+++ Eris/TypeInfo.cpp	Mon Oct  3 18:22:20 2005
@@ -172,17 +172,17 @@
         (*C)->addAncestor(tp);
 }
 
-static Atlas::Objects::Root gameEntityFactory()
+static Atlas::Objects::Root gameEntityFactory(const std::string &, int)
 {
     return Atlas::Objects::Entity::GameEntity();
 }
 
-static Atlas::Objects::Root adminEntityFactory()
+static Atlas::Objects::Root adminEntityFactory(const std::string &, int)
 {
     return Atlas::Objects::Entity::AdminEntity();
 }
 
-static Atlas::Objects::Root actionFactory()
+static Atlas::Objects::Root actionFactory(const std::string &, int)
 {
     return Atlas::Objects::Operation::Action();
 }
