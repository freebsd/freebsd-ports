--- setup.py.orig	2013-07-29 11:39:57.000000000 +0200
+++ setup.py	2013-08-15 17:14:57.000000000 +0200
@@ -330,7 +330,8 @@
    log._print(_separ, """Installation on :
 %s""" % sident, _separ)
 
-   common_libs = ['pthread', 'z']
+   # FreeBSD patch: no -lpthread, but PTHREAD_LIBS already added
+   common_libs = ['z']
    if plt.startswith('linux'):
        plt = 'linux'
    if plt == 'win32':
@@ -502,7 +503,10 @@
    # 1.4.1g. ----- check for system dependent libraries (and only used by Code_Aster)
    cfg['SYSLIB'] = cfg.get('SYSLIB', '')
    aster_sys_lib = []
-   if cfg['IFDEF'] in ('LINUX', 'P_LINUX', 'LINUX64'):
+   if cfg['IFDEF'] == 'FREEBSD':
+      cfg['SYSLIB'] += ' -Wl,--allow-multiple-definition -Wl,--export-dynamic'
+      aster_sys_lib.extend(['util', 'm'])
+   elif cfg['IFDEF'] in ('LINUX', 'P_LINUX', 'LINUX64'):
       cfg['SYSLIB'] += ' -Wl,--allow-multiple-definition -Wl,--export-dynamic'
       aster_sys_lib.extend(['dl', 'util', 'm'])
    elif cfg['IFDEF'] == 'TRU64':
