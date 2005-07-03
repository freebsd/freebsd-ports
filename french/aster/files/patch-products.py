--- products.py.orig	Thu Jun 30 09:38:46 2005
+++ products.py	Fri Jul  1 23:22:35 2005
@@ -781,6 +781,19 @@
       cxxlibs.extend(['stdc++', 'supc++'])
       zmat_platform='Linux4'
       mpilibs.extend(['mpich'])
+   elif cfg['IFDEF']=='FREEBSD':
+      opt['BLASLIB']    = cfg['BLASLIB']
+      opt['LAPACKLIB']  = cfg['LAPACKLIB']
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
       opt['BLASLIB']    = '-lblas'
       opt['LAPACKLIB']  = '-llapack'
