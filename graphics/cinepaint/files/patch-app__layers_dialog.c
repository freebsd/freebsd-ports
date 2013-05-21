--- app/layers_dialog.c.orig
+++ app/layers_dialog.c
@@ -2773,7 +2773,7 @@
 # ifdef DEBUG
     printf("%s:%d %s() wrong data or widget\n", __FILE__,__LINE__,__func__);
 # endif
-    return FALSE;
+    return;
   }
 
 
