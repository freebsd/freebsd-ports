--- products.py.orig	2010-12-22 17:42:46.000000000 +0100
+++ products.py	2010-12-27 23:44:22.000000000 +0100
@@ -922,15 +922,16 @@
            'HOME_PYTHON', 'PYTHON_EXE', 'PYTHONLIB',
            'HOME_MUMPS', 'HOME_ZMAT', 'HOME_MPI', 'INCLUDE_MUMPS', 'HOME_METIS',
            'HOME_MED', 'HOME_HDF', 'HOME_CRPCRS', 'HOME_NUMPY', 'USE_NUMPY',
-           'LD', 'CC', 'F77', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
+           'LD', 'CC', 'F77', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
       reqobj=['file:?ASTER_ROOT?/bin/as_run',
               'file:?ASTER_ROOT?/etc/codeaster/profile.sh'],
       set=['MEDLIB', 'HDFLIB', 'MATHLIB',
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
@@ -968,6 +969,19 @@
    if   cfg['IFDEF'] in ('LINUX', 'P_LINUX'):
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
+      mpilibs.extend(['mpich', 'mpl'])
    elif cfg['IFDEF'] == 'LINUX64':
       mpilibs.extend(['mpich'])
       # others have not been tested !
@@ -1010,11 +1024,12 @@
       cfg['MEDLIB']=''
 
    # ----- libs c++ (for MED and ZMAT)
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
 
    # ----- MUMPS
    if cfg['HOME_MUMPS'] != '':
@@ -1023,12 +1038,15 @@
       if not less_than_version(dict_prod['mumps'], '4.8.0'):
          mumps_lib.extend(['smumps', 'cmumps', 'mumps_common'])
       mumps_lib.extend(['pord', 'mpiseq'])
-      for lib in mumps_lib:
-         ftools.findlib_and_set(cfg, 'MUMPSLIB', lib,
-            cfg['HOME_MUMPS'],
-            err=False, append=True)
-         if lib == 'dmumps':
-            ftools.CheckFromLastFound(cfg, 'HOME_MUMPS', 'lib')
+      if cfg['MUMPSLIB'] != '':
+         opt['MUMPSLIB'] =  cfg['MUMPSLIB']
+      else:
+         for lib in mumps_lib:
+            ftools.findlib_and_set(cfg, 'MUMPSLIB', lib,
+               cfg['HOME_MUMPS'],
+               err=False, append=True)
+            if lib == 'dmumps':
+               ftools.CheckFromLastFound(cfg, 'HOME_MUMPS', 'lib')
       if cfg['HOME_METIS'] != '':
          cfg['MUMPSLIB'] += " -L%s/lib -lmetis" % cfg['HOME_METIS']
       opt['F90INCLUDE'] += ' -I%s' % os.path.join(cfg['ASTER_ROOT'],cfg['ASTER_VERSION'],'bibf90',cfg['INCLUDE_MUMPS'])
