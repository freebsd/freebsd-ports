--- engine/src/model/model.h.orig	Fri Dec 22 15:34:42 2006
+++ engine/src/model/model.h	Fri Dec 22 15:34:53 2006
@@ -235,7 +235,7 @@
       void deleteModule(utils::AutoPtr<Graph>, int moduleID);
 
 #ifndef NDEBUG
-      void Model::checkGraphSerialisation();
+      void checkGraphSerialisation();
 #endif
 
     };
