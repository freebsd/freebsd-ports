--- setup.py.orig	Sun Dec  3 11:37:29 2006
+++ setup.py	Sat Jan 13 07:24:13 2007
@@ -145,14 +145,25 @@
 
         prefix = sysconfig.get_config_var("prefix")
         if prefix:
-            add_directory(library_dirs, os.path.join(prefix, "lib"))
-            add_directory(include_dirs, os.path.join(prefix, "include"))
+            add_directory(library_dirs,
+                          os.path.join(os.getenv("PREFIX"), "lib"))
+            add_directory(include_dirs,
+                          os.path.join(os.getenv("PREFIX"), "include"))
+            add_directory(include_dirs,
+                          os.path.join(os.getenv("LOCALBASE"), "include"))
 
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
