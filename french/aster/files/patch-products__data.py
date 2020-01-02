--- products_data.py.orig	2019-10-01 12:45:34 UTC
+++ products_data.py
@@ -110,10 +110,8 @@ def configure(self):
         '%(HOME_HDF)s/include',
         '%(HOME_MED)s/include',
         '%(HOME_MUMPS)s/include',
-        '%(HOME_MUMPS)s/include_seq',
         '%(HOME_METIS)s/include',
         '%(HOME_SCOTCH)s/include',
-        '%(HOME_MFRONT)s/include',
     ])
 
     self.env['OPTLIB_FLAGS'] = %(MATHLIB)r.split() \
