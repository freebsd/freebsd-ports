--- setup.py.orig	2008-09-03 04:07:23.000000000 +0400
+++ setup.py	2009-04-03 05:57:49.000000000 +0400
@@ -9,18 +9,6 @@
 
 # If we are going to use pyrex, we need to use at least 0.9.6.3.
 have_sufficient_pyrex = False
-try:
-    import Pyrex.Compiler.Version
-    if Pyrex.Compiler.Version.version.split('.') >= ['0','9','6','3']:
-        have_sufficient_pyrex = True
-    else:
-        print "*"*80
-        print "Pyrex is older that 0.9.6.3.  C files will not be updated."
-        print "*"*80
-except ImportError:
-    print "*"*80
-    print "Could not import Pyrex.  C files will not be updated."
-    print "*"*80
 
 # <hack type="ugly">
 if have_sufficient_pyrex:
@@ -43,8 +31,8 @@
 
         transform = {}
         exclude = []
-        compile_args = ["-O3"]
-        link_args = []
+        compile_args = ["-I"+os.environ['LOCALBASE']+"/include"]
+        link_args = ["-L"+os.environ['LOCALBASE']+"/lib"]
         if sys.platform == "win32":
             transform = {'GL':'opengl32', 'GLU':'glu32'}
             exclude = ['m']
