--- mapunion.c.orig	2011-05-17 10:23:51.000000000 +0800
+++ mapunion.c	2011-05-17 10:24:57.000000000 +0800
@@ -311,7 +311,7 @@
         {
             /* get items requested by the union layer plus the required items */
             msLayerSetProcessingKey(srclayer, "ITEMS", itemlist);
-            if (msLayerWhichItems(srclayer, TRUE, NULL) != MS_SUCCESS)
+            if (msLayerWhichItems(srclayer, MS_TRUE, NULL) != MS_SUCCESS)
             {
                 msFree(itemlist);
                 return MS_FAILURE;
@@ -320,7 +320,7 @@
         else
         {
             /* get only the required items */
-            if (msLayerWhichItems(srclayer, FALSE, NULL) != MS_SUCCESS)
+            if (msLayerWhichItems(srclayer, MS_FALSE, NULL) != MS_SUCCESS)
                 return MS_FAILURE;
         }
     }
@@ -349,7 +349,7 @@
             msUnionLayerFreeExpressionTokens(srclayer);
             
             /* get only the required items */
-            if (msLayerWhichItems(srclayer, FALSE, NULL) != MS_SUCCESS)
+            if (msLayerWhichItems(srclayer, MS_FALSE, NULL) != MS_SUCCESS)
                 return MS_FAILURE;
         }
 
