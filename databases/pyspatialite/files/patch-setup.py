--- setup.py.orig	2013-11-22 19:17:22 UTC
+++ setup.py
@@ -65,8 +65,6 @@ class DocBuilder(Command):
         if rc != 0:
             print "Is sphinx installed? If not, try 'sudo easy_install sphinx'."
 
-AMALGAMATION_ROOT = "amalgamation/libspatialite-amalgamation-3.0.1"
-
 TRUTHY = ("yes", "true", "t", "1")
 
 class HeaderNotFoundException(Exception):
@@ -220,12 +218,11 @@ def get_setup_args():
         print "Fatal error: PYSPATIALITE_VERSION could not be detected!"
         sys.exit(1)
 
-    data_files = [("pyspatialite-doc",
+    data_files = [("/usr/local/share/doc/pyspatialite",
                         glob.glob("doc/*.html") \
                       + glob.glob("doc/*.txt") \
                       + glob.glob("doc/*.css")),
-                   ("pyspatialite-doc/code",
-                        glob.glob("doc/code/*.py"))]
+                 ]
 
     py_modules = ["spatialite"]
     setup_args = dict(
@@ -259,11 +256,8 @@ def get_setup_args():
                         "src/statement.c",
                         "src/util.c",
                         "src/row.c",
-                        os.path.join(AMALGAMATION_ROOT, "sqlite3.c"),
-                        os.path.join(AMALGAMATION_ROOT, "spatialite.c")
                     ],
                     include_dirs = [
-                        os.path.join(AMALGAMATION_ROOT,"headers")
                     ],
                     library_dirs = [],
                     runtime_library_dirs = [],
@@ -272,7 +266,6 @@ def get_setup_args():
                         ("VERSION",'"%s"' % PYSPATIALITE_VERSION),
                         ("SQLITE_ENABLE_RTREE", "1"),   # build with fulltext search enabled
                         ("NDEBUG","1"),
-                        ("SPL_AMALGAMATION","1"),
                         ('MODULE_NAME', '\\"spatialite.dbapi2\\"') if sys.platform == "win32" else ('MODULE_NAME', '"spatialite.dbapi2"')
                     ],
                 )
