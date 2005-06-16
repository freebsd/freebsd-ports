--- ./setup.py	Wed Mar 23 13:16:40 2005
+++ ./setup.py	Thu Jun 16 13:24:28 2005
@@ -129,14 +129,25 @@
 
         prefix = sysconfig.get_config_var("prefix")
         if prefix:
-            add_directory(library_dirs, os.path.join(prefix, "lib"))
-            add_directory(include_dirs, os.path.join(prefix, "include"))
+            add_directory(library_dirs,
+                          os.path.join(os.getenv("PREFIX"), "lib"))
+            add_directory(include_dirs,
+                          os.path.join(os.getenv("PREFIX"), "include"))
+            add_directory(include_dirs,
+                          os.path.join(os.getenv("X11BASE"), "include"))
 
         #
         # locate tkinter libraries
 
         if _tkinter:
             TCL_VERSION = _tkinter.TCL_VERSION[:3]
+            TK_VERSION = _tkinter.TK_VERSION[:3]
+            add_directory(include_dirs,
+                          os.path.join(os.getenv("PREFIX"),
+                                       "include/tcl%s" % TCL_VERSION))
+            add_directory(include_dirs,
+                          os.path.join(os.getenv("PREFIX"),
+                                       "include/tk%s" % TK_VERSION))
 
         if _tkinter and not TCL_ROOT:
             # we have Tkinter but the TCL_ROOT variable was not set;
