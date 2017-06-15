--- setup.py.orig	2016-09-07 08:44:22 UTC
+++ setup.py
@@ -357,7 +357,7 @@ def main():
       else:
          cfg['IFDEF'] = 'DARWIN'
    elif plt.startswith('freebsd'):
-      common_libs = []
+      common_libs = ['z']
       cfg['IFDEF']='FREEBSD'
       cfg['ARCH'] = 'x86'
       if machine.endswith('64'):
@@ -513,7 +513,10 @@ def main():
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
