--- products.py.orig	2016-09-07 08:44:22 UTC
+++ products.py
@@ -117,8 +117,8 @@ def setup_hdf5(dep, summary, **kargs):
 
       actions=(
          ('IsInstalled', { 'filename' :
-             [osp.join('__setup.installdir__', 'lib', 'libhdf5.a'),
-              osp.join('__setup.installdir__', 'include', 'hdf5.h')]
+             [osp.join('__setup.installdir__', 'lib', 'libhdf5-18.a'),
+              osp.join('__setup.installdir__', 'include/hdf5-18', 'hdf5.h')]
          } ),
          ('Extract'  , {}),
          # gcc>=4.9 not supported by configure, should not use -ansi
@@ -842,8 +842,9 @@ def setup_aster(dep, summary, **kargs):
       req=['ASTER_ROOT', 'ASTER_VERSION',
            'HOME_PYTHON', 'PYTHON_EXE', 'PYTHONLIB',
            'HOME_MUMPS', 'HOME_ZMAT', 'HOME_MPI', 'INCLUDE_MUMPS', 'HOME_METIS',
-           'HOME_MED', 'HOME_HDF', # 'HOME_MFRONT', because of v11 branch
-           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
+           'HOME_MED', 'HOME_HDF', 'HOME_MFRONT',
+           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS', 'LDFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
       reqobj=['file:?ASTER_ROOT?/bin/as_run',
               'file:?ASTER_ROOT?/etc/codeaster/profile.sh'],
    )
@@ -885,7 +886,8 @@ def setup_aster(dep, summary, **kargs):
             'capturestderr' : False,
          }),
          ('Make'  , {
-            'command'   : './waf build',
+            # Work-around on FreeBSD: MAKE_JOBS_UNSAFE + -vvv to get full logs in setup.dbg
+            'command'   : './waf build -vvv --jobs=1',
             'capturestderr' : False,
          }),
          ('Install'  , {
