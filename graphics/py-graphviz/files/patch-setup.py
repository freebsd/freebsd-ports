--- setup.py.orig	2015-09-06 13:49:49 UTC
+++ setup.py
@@ -54,8 +54,8 @@ if __name__ == "__main__":
         Extension(
             "pygraphviz._graphviz",
             ["pygraphviz/graphviz_wrap.c"],
-            include_dirs=[],
-            library_dirs=[],
+            include_dirs=["%%LOCALBASE%%/include"],
+            library_dirs=["%%LOCALBASE%%/lib/graphviz"],
             libraries=["cgraph", "cdt"],
             define_macros=define_macros
         )
