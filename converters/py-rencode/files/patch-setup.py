# 1) make setup.py test command work via test_suite directive
# 2) Honour/respect user CFLAGS
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233561

--- setup.py.orig	2024-01-31 07:33:33 UTC
+++ setup.py
@@ -42,7 +42,6 @@ ext_modules = [
 ext_modules = [
     Extension(
         "rencode._rencode",
-        extra_compile_args=["-O3"],
         sources=["rencode/_rencode" + source_ext],
     ),
 ]
@@ -97,4 +96,5 @@ setup(
     cmdclass={"build_ext": optional_build_ext},
     ext_modules=ext_modules,
     setup_requires=["setuptools"],
+    test_suite='tests',
 )
