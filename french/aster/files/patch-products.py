--- products.py.orig	Tue Jan  2 17:13:15 2007
+++ products.py	Fri Feb  2 23:13:35 2007
@@ -833,16 +833,18 @@
            'HOME_PYTHON', 'PYTHON_EXE', 'PYTHONLIB', 'PYMODULES_PREFIX',
            'HOME_MUMPS', 'HOME_ZMAT', 'HOME_MPI',
            'HOME_MED', 'HOME_HDF', 'HOME_CRPCRS',
-           'LD', 'CC', 'F77', 'F90',],
+           'LD', 'CC', 'F77', 'F90','LDFLAGS', 'SYSLIB',
+           'CFLAGS', 'CFLAGS_DBG',
+           'FFLAGS', 'FFLAGS_DBG',
+           'F90FLAGS', 'F90FLAGS_DBG'],
       reqobj=['file:?HOME_ASTK?/ASTK_SERV/bin/as_run',
               'file:?HOME_ASTK?/ASTK_SERV/conf/aster_profile.sh'],
-      set=['SYSLIB', 'OTHERLIB',
+      set=['OTHERLIB',
            'MEDLIB', 'HDFLIB', 'LAPACKLIB',
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
@@ -885,6 +887,18 @@
       cxxlibs.extend(['stdc++', 'supc++'])
       zmat_platform='Linux'
       mpilibs.extend(['mpich'])
+   elif cfg['IFDEF']=='FREEBSD':
+      opt['MATH_LIST']  = [cfg['LAPACKLIB'], cfg['BLASLIB'], 'gfortran']
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
       opt['MATH_LIST']  = ['lapack', 'blas', 'g2c']
       opt['SYSLIB']     = '-Wl,--allow-multiple-definition -Wl,--export-dynamic -lieee -ldl -lpthread -lutil -lm'
@@ -939,8 +953,8 @@
       opt['FINCLUDE']   = ''
 
    # ----- F90
-   opt['F90FLAGS_DBG'] = opt['FFLAGS_DBG']
-   opt['F90FLAGS']     = opt['FFLAGS']
+   opt['F90FLAGS_DBG'] = cfg['F90FLAGS_DBG']
+   opt['F90FLAGS'] = cfg['F90FLAGS']
    opt['F90INCLUDE']=''
 
    # ----- check for MED and HDF5 libraries, and HDF5 includes
@@ -973,11 +987,14 @@
 
    # ----- MUMPS
    if cfg['HOME_MUMPS'] != '':
-      for lib in ('dmumps', 'zmumps', 'pord', 'mpiseq'):
-         ftools.findlib_and_set(cfg, 'MUMPSLIB', lib,
-            kargs['libdirs'], cfg['HOME_MUMPS'],
-            err=False, append=True)
-         ftools.CheckFromLastFound(cfg, 'HOME_MUMPS', 'lib')
+      if cfg['MUMPSLIB'] != '':
+         opt['MUMPSLIB'] =  cfg['MUMPSLIB']
+      else:
+         for lib in ('dmumps', 'zmumps', 'pord', 'mpiseq'):
+            ftools.findlib_and_set(cfg, 'MUMPSLIB', lib,
+               kargs['libdirs'], cfg['HOME_MUMPS'],
+               err=False, append=True)
+            ftools.CheckFromLastFound(cfg, 'HOME_MUMPS', 'lib')
       opt['F90INCLUDE'] += ' -I%s' % os.path.join(cfg['ASTER_ROOT'],cfg['ASTER_VERSION'],'bibf90','include_mumps')
    else:
       opt['MUMPSLIB'] = ''
@@ -1033,7 +1050,7 @@
          ftools.findlib_and_set(cfg, 'SCOTCHLIB', lib,
             kargs['libdirs'], cfg['HOME_SCOTCH'],
             err=True, append=True)
-         ftools.CheckFromLastFound(cfg, 'HOME_SCOTCH', 'bin')
+         ftools.CheckFromLastFound(cfg, 'HOME_SCOTCH', 'lib')
       ftools.find_and_set(cfg, 'CINCLUDE', 'scotchf.h',
          kargs['incdirs'], cfg['HOME_SCOTCH'],
          typ='inc', err=True, append=True)
