--- ../setup.py.orig	Fri May  9 05:00:56 2003
+++ ../setup.py	Wed Aug  6 10:40:45 2003
@@ -51,6 +51,9 @@
 if os.path.exists('/sw/lib'):
     LIBRARY_DIRS.append('/sw/lib')
 
+INCLUDE_DIRS.append(os.path.join(os.getenv("PREFIX"), "include"))
+LIBRARY_DIRS.append(os.path.join(os.getenv("PREFIX"), "lib"))
+
 HAVE_LIBJPEG = 0
 HAVE_LIBTIFF = 0
 HAVE_LIBZ = 0
@@ -126,7 +129,13 @@
     pass
 else:
     INCLUDE_DIRS = ["libImaging"]
+    INCLUDE_DIRS.append(os.path.join(os.getenv("X11BASE"), "include"))
+    INCLUDE_DIRS.append(os.path.join(os.getenv("PREFIX"),
+									 "include/tcl%s" % TCL_VERSION))
+    INCLUDE_DIRS.append(os.path.join(os.getenv("PREFIX"),
+									 "include/tk%s" % TCL_VERSION))
     LIBRARY_DIRS = ["libImaging"]
+    LIBRARY_DIRS.append(os.path.join(os.getenv("PREFIX"), "lib"))
     LIBRARIES = ["Imaging"]
     EXTRA_COMPILE_ARGS = None
     EXTRA_LINK_ARGS = None
@@ -206,7 +215,8 @@
 
         if not tk_framework_found:
             # assume the libraries are installed in the default location
-            LIBRARIES.extend(["tk" + TCL_VERSION, "tcl" + TCL_VERSION])
+            version = TCL_VERSION[0] + TCL_VERSION[2]
+            LIBRARIES.extend(["tk" + version, "tcl" + version])
             HAVE_TCLTK = 1
 
     if HAVE_TCLTK:
@@ -266,6 +276,14 @@
         # FIXME: search for libraries
         LIBRARIES.append("freetype")
         INCLUDE_DIRS.append("/usr/include/freetype2")
+    elif os.path.isdir("/usr/local/include/freetype2"):
+        # assume that the freetype library is installed in a
+        # standard location
+        # FIXME: search for libraries
+        LIBRARIES.append("freetype")
+        INCLUDE_DIRS.append("/usr/local/include")
+        INCLUDE_DIRS.append("/usr/local/include/freetype2")
+        LIBRARY_DIRS.append("/usr/local/lib")
     elif os.path.isdir("/sw/include/freetype2"):
         # assume that the freetype library is installed in a
         # standard location
