--- src/engine/ActionMeta.h.orig	Wed Jul 30 17:41:29 2003
+++ src/engine/ActionMeta.h	Sun Aug  3 09:07:12 2003
@@ -29,7 +29,7 @@
 
 #define REGISTER_ACTION_HEADER(x) \
 	virtual const char *getActionName() { return #x ; } \
-	##x *getActionCopy() { return new x ; } \
+	x *getActionCopy() { return new x ; } \
 	virtual bool getReferenced() { return true; }
 #define REGISTER_ACTION_SOURCE(x) \
 	struct META_##x { META_##x() { ActionMetaRegistration::addMap(#x , new x ); } }; \
