Index: lib/yaml/representer.py
===================================================================
--- pyyaml/trunk/lib/yaml/representer.py (revision 152)
+++ pyyaml/trunk/lib/yaml/representer.py (revision 168)
@@ -193,7 +193,12 @@
         return self.represent_scalar(u'tag:yaml.org,2002:int', unicode(data))
 
-    repr_pos_inf = repr(1e300000)
-    repr_neg_inf = repr(-1e300000)
-    repr_nan = repr(1e300000/1e300000)
+    inf_value = 1e300
+    while repr(inf_value) != repr(inf_value*inf_value):
+        inf_value *= inf_value
+    nan_value = inf_value/inf_value
+
+    repr_pos_inf = repr(inf_value)
+    repr_neg_inf = repr(-inf_value)
+    repr_nan = repr(inf_value/inf_value)
 
     def represent_float(self, data):
