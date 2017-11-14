--- products.py.orig	2017-08-26 13:56:41 UTC
+++ products.py
@@ -118,8 +118,8 @@ def setup_hdf5(dep, summary, **kargs):
 
       actions=(
          ('IsInstalled', { 'filename' :
-             [osp.join('__setup.installdir__', 'lib', 'libhdf5.a'),
-              osp.join('__setup.installdir__', 'include', 'hdf5.h')]
+             [osp.join('__setup.installdir__', 'lib', 'libhdf5-18.a'),
+              osp.join('__setup.installdir__', 'include/hdf5-18', 'hdf5.h')]
          } ),
          ('Extract'  , {}),
          # gcc>=4.9 not supported by configure, should not use -ansi
@@ -723,7 +723,8 @@ def setup_aster(dep, summary, **kargs):
            'HOME_MUMPS', 'HOME_ZMAT', 'HOME_MPI', 'INCLUDE_MUMPS', 'HOME_METIS',
            'HOME_MED', 'HOME_HDF', 'HOME_MFRONT',
            #'HOME_GMSH', 'HOME_GIBI', 'HOME_HOMARD', optional
-           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
+           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS', 'LDFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
       reqobj=['file:?ASTER_ROOT?/bin/as_run',
               'file:?ASTER_ROOT?/etc/codeaster/profile.sh'],
    )
@@ -777,7 +778,8 @@ def setup_aster(dep, summary, **kargs):
             'capturestderr' : False,
          }),
          ('Make'  , {
-            'command'   : './waf build',
+            # Work-around on FreeBSD: MAKE_JOBS_UNSAFE + -vvv to get full logs in setup.dbg
+            'command'   : './waf build -vvv --jobs=1',
             'capturestderr' : False,
          }),
          ('Install'  , {
