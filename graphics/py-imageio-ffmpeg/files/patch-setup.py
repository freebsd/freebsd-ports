--- setup.py.orig	2019-04-12 09:07:51 UTC
+++ setup.py
@@ -57,7 +57,6 @@ setup(
     platforms="any",
     provides=["imageio_ffmpeg"],
     python_requires=">=3.4",
-    setup_requires=["pip>19"],
     install_requires=[],  # todo: maybe numpy
     packages=["imageio_ffmpeg"],
     package_dir={"imageio_ffmpeg": "imageio_ffmpeg"},
