--- products.py.orig	Wed Jan 25 13:06:09 2006
+++ products.py	Fri Feb  3 00:08:27 2006
@@ -871,6 +871,18 @@
       cxxlibs.extend(['stdc++', 'supc++'])
       zmat_platform='Linux4'
       mpilibs.extend(['mpich'])
+   elif cfg['IFDEF']=='FREEBSD':
+      opt['MATH_LIST']  = [cfg['LAPACKLIB'], cfg['BLASLIB'], cfg['ATLASLIB'], 'g2c']
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
@@ -1011,7 +1023,7 @@
       for lib in ('common', 'scotch', 'scotcherr', 'scotcherrcom'):
          ftools.findlib_and_set(cfg, 'SCOTCHLIB', lib,
             kargs['libdirs'], cfg['HOME_SCOTCH'],
-            typ='lib', err=True, append=True, check_home=('HOME_SCOTCH', 'bin'))
+            typ='lib', err=True, append=True, check_home=('HOME_SCOTCH', 'lib'))
       ftools.find_and_set(cfg, 'CINCLUDE', 'scotchf.h',
          kargs['incdirs'], cfg['HOME_SCOTCH'],
          typ='inc', err=True, append=True)
