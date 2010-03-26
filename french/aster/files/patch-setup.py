--- ./setup.py.orig	2010-02-09 10:04:59.000000000 +0100
+++ ./setup.py	2010-02-11 23:32:34.000000000 +0100
@@ -318,6 +318,14 @@
             cfg['ARCH'] = 'x86_64'
       else:
          cfg['IFDEF'] = 'LINUX'
+   elif sys.platform[:7] == 'freebsd':
+      cfg['IFDEF']='FREEBSD'
+      cfg['ARCH'] = 'x86'
+      if machine.endswith('64'):
+         if machine in ('x86_64', 'ia64'):
+            cfg['ARCH'] = machine
+         else: # force to x86_64
+            cfg['ARCH'] = 'x86_64'
    elif sys.platform[:4] == 'osf1':
       cfg['IFDEF']='TRU64'
    elif sys.platform == 'sunos5':
@@ -442,13 +450,6 @@
    if not type(math_lib) in (list, tuple):
       math_lib = [math_lib,]
    sys_lib = []
-   for glob_lib in ('pthread', 'z',):
-      cfg['__tmp__'] = ''
-      del cfg['__tmp__']
-      ftools.findlib_and_set(cfg, '__tmp__', glob_lib, prefshared=True, err=False, silent=False)
-      if cfg.get('__tmp__'):
-         ftools.AddToCache('lib', glob_lib, cfg['__tmp__'])
-         sys_lib.append(glob_lib)
 
    # 1.4.2. ----- check for compilers
    cfg_ini = cfg.copy()
@@ -541,6 +542,7 @@
    # and modify command line of those which don't have a --display= option
    ListEdit=[
       ['nedit' , 'nedit',],
+      ['gvim' , 'gvim --display=@D',],
       ['gedit' , 'gedit --display=@D',],
       ['kwrite', 'kwrite --display @D',],
       ['xemacs', 'xemacs -display @D',],
