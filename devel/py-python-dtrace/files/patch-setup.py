--- setup.py.orig	2015-01-26 14:26:50 UTC
+++ setup.py
@@ -14,9 +14,12 @@ try:
     from Cython.Distutils import build_ext
 
     BUILD_EXTENSION = {'build_ext': build_ext}
-    EXT_MODULES = [Extension("dtrace", ["dtrace_cython/dtrace_h.pxd",
-                                        "dtrace_cython/consumer.pyx"],
-                             libraries=["dtrace"])]
+    EXT_MODULES = [Extension("dtrace",
+        ["dtrace_cython/dtrace_h.pxd", "dtrace_cython/consumer.pyx"],
+        libraries=["dtrace","proc","ctf","elf","z","rtld_db","pthread","util"],
+        include_dirs=['/sys/cddl/compat/opensolaris',
+		'/sys/cddl/contrib/opensolaris/uts/common',
+		'/usr/src/cddl/contrib/opensolaris/lib/libdtrace/common'])]
 
 except ImportError:
     BUILD_EXTENSION = {}
