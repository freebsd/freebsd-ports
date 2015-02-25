--- products.py.orig	2014-12-19 10:21:30.000000000 +0100
+++ products.py	2015-02-15 19:39:55.000000000 +0100
@@ -777,7 +777,8 @@
            'HOME_PYTHON', 'PYTHON_EXE', 'PYTHONLIB',
            'HOME_MUMPS', 'HOME_ZMAT', 'HOME_MPI', 'INCLUDE_MUMPS', 'HOME_METIS',
            'HOME_MED', 'HOME_HDF', # 'HOME_MFRONT', because of v11 branch
-           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
+           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS', 'LDFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
       reqobj=['file:?ASTER_ROOT?/bin/as_run',
               'file:?ASTER_ROOT?/etc/codeaster/profile.sh'],
    )
@@ -817,7 +818,8 @@
             'capturestderr' : False,
          }),
          ('Make'  , {
-            'command'   : './waf build',
+            # Work-around on FreeBSD: MAKE_JOBS_UNSAFE + -vvv to get full logs in setup.dbg
+            'command'   : './waf build -vvv --jobs=1',
             'capturestderr' : False,
          }),
          ('Install'  , {
