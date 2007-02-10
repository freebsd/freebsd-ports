--- setup.py.orig	Fri Oct 22 03:55:55 2004
+++ setup.py	Sat Feb 10 00:52:11 2007
@@ -3,7 +3,8 @@
 from distutils.command.install import install
 from distutils.core import setup
 
-headers = glob (os.path.join ("CXX","*.hxx"))
+headers = glob (os.path.join ("CXX", "*.hxx")) + \
+          glob (os.path.join ("CXX", "*.h"))
 sources = glob (os.path.join ("Src", "*.cxx")) + \
           glob (os.path.join ("Src", "*.c"))
 
