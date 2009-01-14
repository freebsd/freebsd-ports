--- setup.py.orig	2008-12-23 18:01:02.000000000 +0100
+++ setup.py	2009-01-04 17:54:20.000000000 +0100
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
@@ -509,6 +517,7 @@
    # and modify command line of those which don't have a --display= option
    ListEdit=[
       ['nedit' , 'nedit',],
+      ['gvim' , 'gvim --display=@D',],
       ['gedit' , 'gedit --display=@D',],
       ['kwrite', 'kwrite --display @D',],
       ['xemacs', 'xemacs -display @D',],
