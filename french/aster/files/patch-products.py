--- products.py.orig	Wed Jan 25 13:06:09 2006
+++ products.py	Wed May 31 22:34:26 2006
@@ -822,16 +822,18 @@
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
    cfg['OTHERLIB'] = cfg.get('OTHERLIB', '')
@@ -871,6 +873,18 @@
       cxxlibs.extend(['stdc++', 'supc++'])
       zmat_platform='Linux4'
       mpilibs.extend(['mpich'])
+   elif cfg['IFDEF']=='FREEBSD':
+      opt['MATH_LIST']  = [cfg['LAPACKLIB'], cfg['BLASLIB'], 'g2c']
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
    elif cfg['IFDEF']=='x86_64':
       opt['MATH_LIST']  = ['lapack', 'blas', 'g2c']
       opt['SYSLIB']     = '-Wl,--allow-multiple-definition -Wl,--export-dynamic -lieee -ldl -lpthread -lutil -lm'
@@ -922,8 +936,8 @@
       opt['FINCLUDE']   = ''
 
    # ----- F90
-   opt['F90FLAGS_DBG'] = opt['FFLAGS_DBG']
-   opt['F90FLAGS']     = opt['FFLAGS']
+   opt['F90FLAGS_DBG'] = cfg['F90FLAGS_DBG']
+   opt['F90FLAGS'] = cfg['F90FLAGS']
    opt['F90INCLUDE']=''
 
    # ----- check for MED and HDF5 libraries, and HDF5 includes
@@ -1011,7 +1025,7 @@
       for lib in ('common', 'scotch', 'scotcherr', 'scotcherrcom'):
          ftools.findlib_and_set(cfg, 'SCOTCHLIB', lib,
             kargs['libdirs'], cfg['HOME_SCOTCH'],
-            typ='lib', err=True, append=True, check_home=('HOME_SCOTCH', 'bin'))
+            typ='lib', err=True, append=True, check_home=('HOME_SCOTCH', 'lib'))
       ftools.find_and_set(cfg, 'CINCLUDE', 'scotchf.h',
          kargs['incdirs'], cfg['HOME_SCOTCH'],
          typ='inc', err=True, append=True)
