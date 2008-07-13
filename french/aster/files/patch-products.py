--- products.py.orig	2008-07-03 18:50:57.000000000 +0200
+++ products.py	2008-07-10 21:13:03.000000000 +0200
@@ -936,16 +936,18 @@
            'HOME_PYTHON', 'PYTHON_EXE', 'PYTHONLIB', 'PYMODULES_PREFIX',
            'HOME_MUMPS', 'HOME_ZMAT', 'HOME_MPI', 'INCLUDE_MUMPS',
            'HOME_MED', 'HOME_HDF', 'HOME_CRPCRS',
-           'LD', 'CC', 'F77', 'F90', 'CXXLIB', 'OTHERLIB',],
+           'LD', 'CC', 'F77', 'F90', 'LDFLAGS', 'SYSLIB',
+           'CFLAGS', 'CFLAGS_DBG',
+           'FFLAGS', 'FFLAGS_DBG',
+           'F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', 'OTHERLIB',],
       reqobj=['file:?HOME_ASTK?/ASTK_SERV/bin/as_run',
               'file:?HOME_ASTK?/ASTK_SERV/conf/aster_profile.sh'],
       set=['SYSLIB',
            'MEDLIB', 'HDFLIB', 'LAPACKLIB', 'MATHLIB',
            'MUMPSLIB', 'ZMATLIB', 'SCOTCHLIB',
-           'LDFLAGS',
-           'CFLAGS', 'CFLAGS_DBG', 'CINCLUDE',
-           'FFLAGS', 'FFLAGS_DBG', 'FINCLUDE',
-           'F90FLAGS', 'F90FLAGS_DBG', 'F90INCLUDE',
+           'CINCLUDE',
+           'FINCLUDE',
+           'F90INCLUDE',
            'NOBUILD', ],
    )
    cfg['ENV_SH']   = cfg.get('ENV_SH', '')
@@ -981,6 +983,19 @@
       opt['FINCLUDE']   = ''
       zmat_platform='Linux'
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
+      mpilibs.extend(['mpich'])
    elif cfg['IFDEF'] == 'LINUX64':
       opt['SYSLIB']     = '-Wl,--allow-multiple-definition -Wl,--export-dynamic -lieee -ldl -lutil -lm'
       opt['LDFLAGS']    = '-v'
@@ -1033,8 +1048,8 @@
       opt['FINCLUDE']   = ''
 
    # ----- F90
-   opt['F90FLAGS_DBG'] = opt['FFLAGS_DBG']
-   opt['F90FLAGS']     = opt['FFLAGS']
+   opt['F90FLAGS_DBG'] = cfg['F90FLAGS_DBG']
+   opt['F90FLAGS'] = cfg['F90FLAGS']
    opt['F90INCLUDE']=''
 
    # ----- check for MED and HDF5 libraries, and HDF5 includes
@@ -1071,12 +1086,15 @@
    # ----- MUMPS
    if cfg['HOME_MUMPS'] != '':
       cfg['DEFINED'] += ' _HAVE_MUMPS'
-      for lib in ('dmumps', 'zmumps', 'pord', 'mpiseq'):
-         ftools.findlib_and_set(cfg, 'MUMPSLIB', lib,
-            kargs['libdirs'], cfg['HOME_MUMPS'],
-            err=False, append=True)
-         if lib == 'dmumps':
-            ftools.CheckFromLastFound(cfg, 'HOME_MUMPS', 'lib')
+      if cfg['MUMPSLIB'] != '':
+         opt['MUMPSLIB'] =  cfg['MUMPSLIB']
+      else:
+         for lib in ('dmumps', 'zmumps', 'pord', 'mpiseq'):
+            ftools.findlib_and_set(cfg, 'MUMPSLIB', lib,
+               kargs['libdirs'], cfg['HOME_MUMPS'],
+               err=False, append=True)
+            if lib == 'dmumps':
+               ftools.CheckFromLastFound(cfg, 'HOME_MUMPS', 'lib')
       opt['F90INCLUDE'] += ' -I%s' % os.path.join(cfg['ASTER_ROOT'],cfg['ASTER_VERSION'],'bibf90',cfg['INCLUDE_MUMPS'])
       if cfg['HOME_MPI'] != '':
          cfg['DEFINED'] += ' _USE_MPI_MUMPS'
@@ -1132,7 +1150,7 @@
             kargs['libdirs'], cfg['HOME_SCOTCH'],
             err=True, append=True)
          if lib == 'common':
-            ftools.CheckFromLastFound(cfg, 'HOME_SCOTCH', 'bin')
+            ftools.CheckFromLastFound(cfg, 'HOME_SCOTCH', 'lib')
       ftools.find_and_set(cfg, 'CINCLUDE', 'scotchf.h',
          kargs['incdirs'], cfg['HOME_SCOTCH'],
          typ='inc', err=True, append=True)
