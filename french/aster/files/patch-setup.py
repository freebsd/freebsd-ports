--- setup.py.orig	Thu Jun 30 16:35:15 2005
+++ setup.py	Fri Jul  1 20:46:30 2005
@@ -260,6 +260,8 @@
    # 1.3.2. ----- convert uname value to Code_Aster terminology...
    if sys.platform == 'linux2':
       cfg['IFDEF']='P_LINUX'
+   elif sys.platform[:7] == 'freebsd':
+      cfg['IFDEF']='FREEBSD'
    elif sys.platform == 'x86_64':
       cfg['IFDEF']='x86_64'
    elif sys.platform[:4] == 'osf1':
