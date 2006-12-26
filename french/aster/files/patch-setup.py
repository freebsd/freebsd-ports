--- setup.py.orig	Fri Dec 22 17:56:58 2006
+++ setup.py	Sun Dec 24 11:00:55 2006
@@ -278,6 +278,8 @@
          cfg['IFDEF'] = 'LINUX64'
       else:
          cfg['IFDEF'] = 'LINUX'
+   elif sys.platform[:7] == 'freebsd':
+      cfg['IFDEF']='FREEBSD'
    elif sys.platform[:4] == 'osf1':
       cfg['IFDEF']='TRU64'
    elif sys.platform == 'sunos5':
