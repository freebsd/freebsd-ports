--- setup.py.orig	Sun Jan 30 12:22:14 2005
+++ setup.py	Thu Nov 16 18:46:25 2006
@@ -40,7 +40,7 @@
 f2py2e.main()
 '''%(os.path.basename(sys.executable))
 
-f2py_exe = 'f2py'+os.path.basename(sys.executable)[6:]
+f2py_exe = 'f2py'
 if f2py_exe[-4:]=='.exe':
     f2py_exe = f2py_exe[:-4] + '.py'
 if 'bdist_wininst' in sys.argv and f2py_exe[-3:] != '.py':
