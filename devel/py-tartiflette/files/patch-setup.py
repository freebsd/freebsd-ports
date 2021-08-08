--- setup.py.orig	2021-08-02 14:49:15 UTC
+++ setup.py
@@ -42,7 +42,6 @@ class BuildExtCmd(build_ext):
 
 class BuildPyCmd(build_py):
     def run(self):
-        _build_libgraphqlparser()
         super().run()
 
 
@@ -91,10 +90,9 @@ setup(
     ],
     keywords="api graphql protocol api rest relay tartiflette dailymotion",
     packages=_PACKAGES,
-    install_requires=["cffi>=1.0.0,<2.0.0", "lark-parser==0.11.3", "pytz"],
+    install_requires=["cffi>=1.0.0,<2.0.0", "lark-parser>=0.11.3", "pytz"],
     tests_require=_TEST_REQUIRE,
     extras_require={"test": _TEST_REQUIRE, "benchmark": _BENCHMARK_REQUIRE},
-    cmdclass={"build_ext": BuildExtCmd, "build_py": BuildPyCmd},
-    ext_modules=[LibGraphQLParserExtension()],
+    cmdclass={"build_py": BuildPyCmd},
     include_package_data=True,
 )
