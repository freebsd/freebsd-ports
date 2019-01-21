--- astropy/modeling/setup_package.py.orig	2016-03-10 22:20:43 UTC
+++ astropy/modeling/setup_package.py
@@ -123,8 +123,7 @@ def preprocess_source():
 
 def get_package_data():
     return {
-        'astropy.modeling.tests': ['data/*.fits', 'data/*.hdr',
-                                   '../../wcs/tests/maps/*.hdr']
+        'astropy.modeling.tests': ['data/*.fits', 'data/*.hdr' ]
     }
 
 
