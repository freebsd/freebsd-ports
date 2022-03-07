--- setup.py.orig	2022-02-24 22:37:13 UTC
+++ setup.py
@@ -258,7 +257,7 @@ setup(
         "Programming Language :: Python :: 3.10",
     ],
     use_scm_version={"write_to": "ddtrace/_version.py"},
-    setup_requires=["setuptools_scm[toml]>=4,<6.1", "cython", "cmake", "ninja"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython"],
     ext_modules=ext_modules
     + cythonize(
         [
@@ -309,14 +308,6 @@ setup(
                 "ddtrace.profiling._build",
                 sources=["ddtrace/profiling/_build.pyx"],
                 language="c",
-            ),
-            Cython.Distutils.Extension(
-                "ddtrace.appsec._ddwaf",
-                sources=["ddtrace/appsec/_ddwaf.pyx"],
-                include_dirs=["ddtrace/appsec/include"],
-                library_dirs=["ddtrace/appsec/lib"],
-                libraries=ddwaf_libraries,
-                language="c++",
             ),
         ],
         compile_time_env={
