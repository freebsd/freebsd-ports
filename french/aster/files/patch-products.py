--- products.py.orig	2019-10-01 12:45:34 UTC
+++ products.py
@@ -637,7 +637,8 @@ def setup_mumps(dep, summary, **kargs):
             'capturestderr' : False,
          }),
          ('Make'     , {
-            'command' : '%(PYTHON_ALIAS)s ; ./waf build --jobs=1' % cfg,
+	 # Work-around on FreeBSD: MAKE_JOBS_UNSAFE + -vvv to get full logs in setup.dbg
+            'command' : '%(PYTHON_ALIAS)s ; ./waf build -vvv --jobs=1' % cfg,
             'capturestderr' : False,
          }),
          ('Install',   {
@@ -691,7 +692,8 @@ def setup_aster(dep, summary, **kargs):
            'HOME_MUMPS', 'HOME_MPI', 'INCLUDE_MUMPS', 'HOME_METIS',
            'HOME_MED', 'HOME_HDF', 'HOME_MFRONT',
            #'HOME_GMSH', 'HOME_HOMARD', optional
-           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
+           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS', 'LDFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
       reqobj=['file:?ASTER_ROOT?/bin/as_run',
               'file:?ASTER_ROOT?/etc/codeaster/profile.sh'],
    )
