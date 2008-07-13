--- setup.py.orig	2008-07-03 18:50:57.000000000 +0200
+++ setup.py	2008-07-08 00:05:35.000000000 +0200
@@ -296,6 +296,14 @@
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
@@ -406,7 +414,7 @@
    if not type(math_lib) in (list, tuple):
       math_lib = [math_lib,]
    sys_lib = []
-   for glob_lib in ('pthread', 'g2c', 'z',):
+   for glob_lib in ('pthread', 'f2c', 'z',):
       cfg['__tmp__'] = ''
       del cfg['__tmp__']
       ftools.findlib_and_set(cfg, '__tmp__', glob_lib, libdirs, [], prefshared=True,
@@ -502,6 +510,7 @@
    # and modify command line of those which don't have a --display= option
    ListEdit=[
       ['nedit' , 'nedit',],
+      ['gvim' , 'gvim --display=@D',],
       ['gedit' , 'gedit --display=@D',],
       ['kwrite', 'kwrite --display @D',],
       ['xemacs', 'xemacs -display @D',],
