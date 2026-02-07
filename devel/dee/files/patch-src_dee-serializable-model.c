--- src/dee-serializable-model.c.orig	2013-09-16 18:21:20 UTC
+++ src/dee-serializable-model.c
@@ -1327,8 +1327,10 @@ dee_serializable_model_get_position (DeeModel     *sel
   pos = 0;
   _iter = dee_model_get_first_iter (self);
   while (!dee_model_is_last (self, iter) && iter != _iter)
-    _iter = dee_model_next (self, _iter);
-    pos++;
+    {
+      _iter = dee_model_next (self, _iter);
+      pos++;
+    }
 
   if (iter == _iter)
     return pos;
