--- products.py.orig	2008-12-23 18:01:01.000000000 +0100
+++ products.py	2009-01-04 19:56:33.000000000 +0100
@@ -931,16 +931,19 @@
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
            'MEDLIB', 'HDFLIB', 'MATHLIB',
            'MUMPSLIB', 'ZMATLIB', 'SCOTCHLIB',
            'LDFLAGS',
-           'CFLAGS', 'CFLAGS_DBG', 'CINCLUDE',
-           'FFLAGS', 'FFLAGS_DBG', 'FINCLUDE',
-           'F90FLAGS', 'F90FLAGS_DBG', 'F90INCLUDE',
+           'CINCLUDE',
+           'FINCLUDE',
+           'F90INCLUDE',
            'NOBUILD', ],
    )
    cfg['ENV_SH']   = cfg.get('ENV_SH', '')
@@ -975,6 +978,19 @@
       opt['FFLAGS']     = '-O2'
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
@@ -1056,12 +1072,15 @@
    # ----- MUMPS
    if cfg['HOME_MUMPS'] != '':
       cfg['DEFINED'] += ' _HAVE_MUMPS'
-      for lib in ('dmumps', 'zmumps', 'pord', 'mpiseq'):
-         ftools.findlib_and_set(cfg, 'MUMPSLIB', lib,
-            cfg['HOME_MUMPS'],
-            err=False, append=True)
-         if lib == 'dmumps':
-            ftools.CheckFromLastFound(cfg, 'HOME_MUMPS', 'lib')
+      if cfg['MUMPSLIB'] != '':
+         opt['MUMPSLIB'] =  cfg['MUMPSLIB']
+      else:
+         for lib in ('dmumps', 'zmumps', 'pord', 'mpiseq'):
+            ftools.findlib_and_set(cfg, 'MUMPSLIB', lib,
+               cfg['HOME_MUMPS'],
+               err=False, append=True)
+            if lib == 'dmumps':
+               ftools.CheckFromLastFound(cfg, 'HOME_MUMPS', 'lib')
       opt['F90INCLUDE'] += ' -I%s' % os.path.join(cfg['ASTER_ROOT'],cfg['ASTER_VERSION'],'bibf90',cfg['INCLUDE_MUMPS'])
       if cfg['HOME_MPI'] != '':
          cfg['DEFINED'] += ' _USE_MPI_MUMPS'
@@ -1102,7 +1121,7 @@
       ftools.find_and_set(cfg, 'FINCLUDE', 'mpif.h',
          cfg['HOME_MPI'],
          typ='inc', err=False, append=True)
-      opt['DEFINED'] +=' _USE_MPI _USE_MPI_FETI'
+      cfg['DEFINED'] +=' _USE_MPI _USE_MPI_FETI'
 
    else:
       opt['MPILIB']=''
@@ -1117,7 +1136,7 @@
             cfg['HOME_SCOTCH'],
             err=True, append=True)
          if lib == 'common':
-            ftools.CheckFromLastFound(cfg, 'HOME_SCOTCH', 'bin')
+            ftools.CheckFromLastFound(cfg, 'HOME_SCOTCH', 'lib')
       ftools.find_and_set(cfg, 'CINCLUDE', 'scotchf.h',
          cfg['HOME_SCOTCH'],
          typ='inc', err=True, append=True)
