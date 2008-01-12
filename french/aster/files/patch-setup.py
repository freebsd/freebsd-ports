--- setup.py.orig	2007-12-21 17:08:17.000000000 +0100
+++ setup.py	2008-01-08 14:56:44.000000000 +0100
@@ -286,6 +286,8 @@
          cfg['IFDEF'] = 'LINUX64'
       else:
          cfg['IFDEF'] = 'LINUX'
+   elif sys.platform[:7] == 'freebsd':
+      cfg['IFDEF']='FREEBSD'
    elif sys.platform[:4] == 'osf1':
       cfg['IFDEF']='TRU64'
    elif sys.platform == 'sunos5':
@@ -397,6 +399,7 @@
    # and modify command line of those which don't have a --display= option
    ListEdit=[
       ['nedit' , 'nedit',],
+      ['gvim' , 'gvim --display=@D',],
       ['gedit' , 'gedit --display=@D',],
       ['kwrite', 'kwrite --display @D',],
       ['xemacs', 'xemacs -display @D',],
