--- products_data.py.orig	2017-08-26 13:56:41 UTC
+++ products_data.py
@@ -107,13 +107,11 @@ def configure(self):
     ])
 
     self.env.append_value('INCLUDES', [
-        '%(HOME_HDF)s/include',
+        '%(HOME_HDF)s/include/hdf5-18',
         '%(HOME_MED)s/include',
         '%(HOME_MUMPS)s/include',
-        '%(HOME_MUMPS)s/include_seq',
         '%(HOME_METIS)s/include',
         '%(HOME_SCOTCH)s/include',
-        '%(HOME_MFRONT)s/include',
     ])
 
     self.env['OPTLIB_FLAGS'] = %(MATHLIB)r.split() \
