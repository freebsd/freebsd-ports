--- products_data.py.orig	2020-10-26 15:54:27 UTC
+++ products_data.py
@@ -130,10 +130,8 @@ def configure(self):
         '%(HOME_HDF)s/include',
         '%(HOME_MED)s/include',
         '%(HOME_MUMPS)s/include',
-        '%(HOME_MUMPS)s/include_seq',
         '%(HOME_METIS)s/include',
         '%(HOME_SCOTCH)s/include',
-        '%(HOME_MFRONT)s/include',
     ])
 
     self.env['OPTLIB_FLAGS'] = %(MATHLIB)r.split() \
