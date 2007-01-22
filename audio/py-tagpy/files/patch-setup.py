--- setup.py	Sun Jan  8 19:36:27 2006
+++ setup.py.port	Mon Jan 22 15:51:41 2007
@@ -4,12 +4,12 @@
 from distutils.core import setup,Extension
 
 # BEGIN USER CUSTOMIZABLE SECTION --------------------
-TAGLIB_INCLUDE_DIRS = ["/usr/include/taglib"]
+TAGLIB_INCLUDE_DIRS = ["%%LOCALBASE%%/include/taglib"]
 TAGLIB_LIBRARY_DIRS = []
 TAGLIB_LIBRARIES = ["tag"]
 
-BOOST_INCLUDE_DIRS = []
-BOOST_LIBRARY_DIRS = []
+BOOST_INCLUDE_DIRS = ["%%PYTHON_INCLUDEDIR%%", "%%LOCALBASE%%/include"]
+BOOST_LIBRARY_DIRS = ["%%PYTHON_LIBDIR%%", "%%LOCALBASE%%/lib"]
 BOOST_LIBRARIES = ["boost_python"]
 # END USER CUSTOMIZABLE SECTION ----------------------
 
