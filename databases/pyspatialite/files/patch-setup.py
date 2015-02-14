--- setup.py.orig	2014-12-30 18:38:25.823292562 +0100
+++ setup.py	2014-12-30 18:39:43.418635165 +0100
@@ -65,7 +65,7 @@
         if rc != 0:
             print "Is sphinx installed? If not, try 'sudo easy_install sphinx'."
 
-AMALGAMATION_ROOT = "amalgamation/libspatialite-amalgamation-3.0.1"
+#AMALGAMATION_ROOT = "amalgamation/libspatialite-amalgamation-3.0.1"
 
 TRUTHY = ("yes", "true", "t", "1")
 
@@ -258,12 +258,12 @@
                         "src/prepare_protocol.c",
                         "src/statement.c",
                         "src/util.c",
-                        "src/row.c",
-                        os.path.join(AMALGAMATION_ROOT, "sqlite3.c"),
-                        os.path.join(AMALGAMATION_ROOT, "spatialite.c")
+                        "src/row.c"
+#                        os.path.join(AMALGAMATION_ROOT, "sqlite3.c"),
+#                        os.path.join(AMALGAMATION_ROOT, "spatialite.c")
                     ],
                     include_dirs = [
-                        os.path.join(AMALGAMATION_ROOT,"headers")
+#                        os.path.join(AMALGAMATION_ROOT,"headers")
                     ],
                     library_dirs = [],
                     runtime_library_dirs = [],
@@ -272,7 +272,7 @@
                         ("VERSION",'"%s"' % PYSPATIALITE_VERSION),
                         ("SQLITE_ENABLE_RTREE", "1"),   # build with fulltext search enabled
                         ("NDEBUG","1"),
-                        ("SPL_AMALGAMATION","1"),
+#                        ("SPL_AMALGAMATION","1"),
                         ('MODULE_NAME', '\\"spatialite.dbapi2\\"') if sys.platform == "win32" else ('MODULE_NAME', '"spatialite.dbapi2"')
                     ],
                 )
