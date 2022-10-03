--- setup.py.orig	2022-09-23 19:22:12 UTC
+++ setup.py
@@ -258,7 +258,6 @@ setup(
         "pathlib2; python_version<'3.5'",
         "jsonschema",
         "xmltodict>=0.12",
-        "ipaddress",
         "envier",
     ]
     + bytecode,
@@ -293,7 +292,7 @@ setup(
         "Programming Language :: Python :: 3.10",
     ],
     use_scm_version={"write_to": "ddtrace/_version.py"},
-    setup_requires=["setuptools_scm[toml]>=4,<6.1", "cython", "cmake", "ninja"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython"],
     ext_modules=ext_modules
     + cythonize(
         [
@@ -344,14 +343,6 @@ setup(
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
