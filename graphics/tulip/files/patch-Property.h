--- library/tulip/include/tulip/Property.h.orig	Mon Jan 20 23:40:43 2003
+++ library/tulip/include/tulip/Property.h	Fri Oct 29 14:14:08 2004
@@ -46,8 +46,10 @@
       dataSet= context->dataSet;
     }
     else
-      (void *)dataSet=(void *)superGraph = (void *)propertyProxy = (void *)pluginProgress = (void *)NULL;
-
+      dataSet = NULL;
+      superGraph = NULL;
+      propertyProxy = NULL;
+      pluginProgress = NULL;
   }
   ///
   virtual ~Property(){}
