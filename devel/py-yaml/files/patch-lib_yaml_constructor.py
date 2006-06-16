Index: lib/yaml/constructor.py
===================================================================
--- pyyaml/trunk/lib/yaml/constructor.py (revision 147)
+++ pyyaml/trunk/lib/yaml/constructor.py (revision 168)
@@ -232,5 +232,7 @@
             return sign*int(value)
 
-    inf_value = 1e300000
+    inf_value = 1e300
+    while repr(inf_value) != repr(inf_value*inf_value):
+        inf_value *= inf_value
     nan_value = inf_value/inf_value
