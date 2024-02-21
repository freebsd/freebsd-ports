--- setup.py.orig	2023-11-29 18:29:08 UTC
+++ setup.py
@@ -188,7 +188,6 @@ with open('README.rst', 'r') as readme_file:
 extensions = [
     Extension('pykdtree.kdtree', sources=['pykdtree/kdtree.pyx', 'pykdtree/_kdtree_core.c'],
               include_dirs=[np.get_include()],
-              define_macros=[("NPY_NO_DEPRECATED_API", "NPY_1_7_API_VERSION")],
               compiler_directions={"language_level": "3"},
               ),
 ]
