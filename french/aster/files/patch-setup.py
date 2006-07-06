--- setup.py.orig	Wed Jun 28 17:31:56 2006
+++ setup.py	Sat Jul  1 20:00:55 2006
@@ -275,6 +275,8 @@
          cfg['IFDEF']='LINUX64'
       else:
          cfg['IFDEF']='P_LINUX'
+   elif sys.platform[:7] == 'freebsd':
+      cfg['IFDEF']='FREEBSD'
    # elif sys.platform == 'win32':
    #    ???
    elif sys.platform[:4] == 'osf1':
