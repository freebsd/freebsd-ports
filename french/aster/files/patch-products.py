--- products.py.orig	2020-10-26 15:54:27 UTC
+++ products.py
@@ -658,7 +658,8 @@ def setup_mumps(dep, summary, **kargs):
             'capturestderr' : False,
          }),
          ('Make'     , {
-            'command' : '%(PYTHON_ALIAS)s ; ./waf build --jobs=1' % cfg,
+	 # Work-around on FreeBSD: MAKE_JOBS_UNSAFE + -vvv to get full logs in setup.dbg
+            'command' : '%(PYTHON_ALIAS)s ; ./waf build -vvv --jobs=1' % cfg,
             'capturestderr' : False,
          }),
          ('Install',   {
@@ -718,7 +719,8 @@ def setup_aster(dep, summary, **kargs):
            'HOME_MED', 'HOME_HDF', 'HOME_MFRONT', 'HOME_BOOST',
            'LIBPATH_BOOST', 'LIBNAME_BOOST',
            #'HOME_GMSH', 'HOME_HOMARD', optional
-           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
+           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS', 'LDFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
       set=['LIBPATH_HDF', 'LIBPATH_MED', 'LIBPATH_METIS', 'LIBPATH_SCOTCH',
            'LIBPATH_MUMPS', 'LIBPATH_MFRONT'],
       reqobj=['file:?ASTER_ROOT?/bin/as_run',
