--- products_data.py.orig	2020-10-26 15:54:27 UTC
+++ products_data.py
@@ -48,7 +48,7 @@ export LIBPATH_HDF5="%(LIBPATH_HDF)s"
 export PYPATH_ASRUN="%(ASTER_ROOT)s/lib/python%(PYTHON_XY)s/site-packages"
 
 export LIBPATH_HDF5="%(LIBPATH_HDF)s"
-export INCLUDES_HDF5="%(HOME_HDF)s/include"
+export INCLUDES_HDF5="%(HOME_HDF)s/include/hdf5-110"
 
 export LIBPATH_MED="%(LIBPATH_MED)s"
 export INCLUDES_MED="%(HOME_MED)s/include"
@@ -127,13 +127,11 @@ def configure(self):
     ])
 
     self.env.append_value('INCLUDES', [
-        '%(HOME_HDF)s/include',
+        '%(HOME_HDF)s/include/hdf5-110',
         '%(HOME_MED)s/include',
         '%(HOME_MUMPS)s/include',
-        '%(HOME_MUMPS)s/include_seq',
         '%(HOME_METIS)s/include',
         '%(HOME_SCOTCH)s/include',
-        '%(HOME_MFRONT)s/include',
     ])
 
     self.env['OPTLIB_FLAGS'] = %(MATHLIB)r.split() \
