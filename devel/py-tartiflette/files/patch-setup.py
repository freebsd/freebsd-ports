--- setup.py.orig	2020-05-02 18:17:15 UTC
+++ setup.py
@@ -38,13 +38,11 @@ def _build_libgraphqlparser():
 
 class BuildExtCmd(build_ext):
     def run(self):
-        _build_libgraphqlparser()
         build_ext.run(self)
 
 
 class BuildPyCmd(build_py):
     def run(self):
-        _build_libgraphqlparser()
         build_py.run(self)
 
 
@@ -88,7 +86,7 @@ setup(
     ],
     keywords="api graphql protocol api rest relay tartiflette dailymotion",
     packages=_PACKAGES,
-    install_requires=["cffi>=1.0.0,<2.0.0", "lark-parser==0.8.5", "pytz"],
+    install_requires=["cffi>=1.0.0,<2.0.0", "lark-parser>=0.8.5", "pytz"],
     tests_require=_TEST_REQUIRE,
     extras_require={"test": _TEST_REQUIRE, "benchmark": _BENCHMARK_REQUIRE},
     cmdclass={"build_ext": BuildExtCmd, "build_py": BuildPyCmd},
