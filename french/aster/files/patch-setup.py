--- setup.py.orig	Mon Jan  3 16:40:16 2005
+++ setup.py	Sat Jan  8 16:37:54 2005
@@ -247,6 +247,8 @@
 # 1.3.2. ----- convert uname value to Code_Aster terminology...
 if sys.platform == 'linux2':
    cfg['IFDEF']='P_LINUX'
+elif sys.platform[:7] == 'freebsd':
+   cfg['IFDEF']='FREEBSD'
 elif sys.platform[:4] == 'osf1':
    cfg['IFDEF']='TRU64'
 elif sys.platform == 'sunos5':
