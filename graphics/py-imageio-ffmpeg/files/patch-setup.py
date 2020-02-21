--- setup.py.orig	2020-02-18 12:37:49 UTC
+++ setup.py
@@ -57,7 +57,6 @@ setup(
     platforms="any",
     provides=["imageio_ffmpeg"],
     python_requires=">=3.4",
-    setup_requires=["pip>19"],
     install_requires=[],
     packages=["imageio_ffmpeg"],
     package_dir={"imageio_ffmpeg": "imageio_ffmpeg"},
