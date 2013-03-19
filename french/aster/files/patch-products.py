--- products.py.orig	2013-01-28 13:35:55.000000000 +0100
+++ products.py	2013-03-17 21:30:27.000000000 +0100
@@ -995,9 +995,10 @@
            'HOME_PYTHON', 'PYTHON_EXE', 'PYTHONLIB',
            'HOME_MUMPS', 'HOME_ZMAT', 'HOME_MPI', 'INCLUDE_MUMPS', 'HOME_METIS',
            'HOME_MED', 'HOME_HDF', 'HOME_CRPCRS', 'HOME_NUMPY', 'USE_NUMPY',
-           'LD', 'CC', 'F77', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
-      reqobj=['file:?ASTER_ROOT?/bin/as_run',
-              'file:?ASTER_ROOT?/etc/codeaster/profile.sh'],
+           'LD', 'CC', 'F77', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
+      reqobj=['file:/usr/ports/french/aster/work/aster-full-src-10.8.0/instdir/bin/as_run',
+              'file:/usr/ports/french/aster/work/aster-full-src-10.8.0/instdir/etc/codeaster/profile.sh'],
       set=['MEDLIB', 'HDFLIB', 'MATHLIB',
            'MUMPSLIB', 'ZMATLIB', 'SCOTCHLIB',
            'CINCLUDE', 'FINCLUDE', 'F90INCLUDE',
@@ -1043,6 +1044,19 @@
    if   cfg['IFDEF'] in ('LINUX', 'P_LINUX'):
       zmat_platform = 'Linux'
       mpilibs.extend(['mpich'])
+   elif cfg['IFDEF']=='FREEBSD':
+      # Don't check gfortran, already part of SYSLIB
+      opt['MATH_LIST']  = [cfg['LAPACKLIB'], cfg['BLASLIB']]
+      opt['SYSLIB']     = cfg['SYSLIB']
+      opt['LDFLAGS']    = cfg['LDFLAGS']
+      opt['CFLAGS_DBG'] = cfg['CFLAGS_DBG']
+      opt['CFLAGS']     = cfg['CFLAGS']
+      opt['FFLAGS_DBG'] = cfg['FFLAGS_DBG']
+      opt['FFLAGS']     = cfg['FFLAGS']
+      opt['FINCLUDE']   = ''
+      cxxlibs.extend(['stdc++', 'supc++'])
+      zmat_platform=''
+      mpilibs.extend(['mpich', 'mpl'])
    elif cfg['IFDEF'] == 'LINUX64':
       mpilibs.extend(['mpich'])
       # others have not been tested !
@@ -1097,11 +1111,12 @@
 
    # ----- libs c++ (for MED and ZMAT)
    #XXX probably to remove (done by check_compiler)
-   if cfg['HOME_MED'] != '' or cfg['HOME_ZMAT'] != '':
-      for lib in cxxlibs:
-         ftools.findlib_and_set(cfg, 'CXXLIB', lib,
-            [cfg['HOME_MED'], cfg['HOME_ZMAT']],
-            err=False, append=True, maxdepth=max(ftools.maxdepth,10))
+   # CXXLIB already set for FreeBSD
+   #if cfg['HOME_MED'] != '' or cfg['HOME_ZMAT'] != '':
+   #   for lib in cxxlibs:
+   #      ftools.findlib_and_set(cfg, 'CXXLIB', lib,
+   #         [cfg['HOME_MED'], cfg['HOME_ZMAT']],
+   #         err=False, append=True, maxdepth=max(ftools.maxdepth,10))
 
    # ----- METIS
    if cfg.get('METISLIB'):
