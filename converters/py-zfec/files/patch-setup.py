Obtained from:  https://github.com/tahoe-lafs/zfec/commit/7d159d3b6ebb28417b333b89b11c0d88cc069568
		https://github.com/tahoe-lafs/zfec/commit/819ca0443fc71e33e61226aef9b0b3fd1a93dd41

--- setup.py.orig	2018-04-08 04:36:59 UTC
+++ setup.py
@@ -60,11 +60,14 @@ setup(
     long_description=open('README.rst', 'rU').read(),
     url="https://github.com/tahoe-lafs/zfec",
     install_requires=[
-        "pyutil >= 3.0.0",
         "argparse >= 0.8 ; python_version <= '2.7'",
         # note to self: single-quotes on the '2.7' are ok:
         # https://github.com/pypa/packaging/blob/16.8/packaging/markers.py#L121
 ],
+    extras_require={
+        "bench": ["pyutil >= 3.0.0"],
+        "test": ["twisted", "setuptools_trial", "pyutil >= 3.0.0"],
+    },
     ext_modules=extensions,
     cmdclass=versioneer.get_cmdclass(),
 )
