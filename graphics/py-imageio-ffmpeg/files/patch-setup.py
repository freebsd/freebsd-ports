--- setup.py.orig	2022-04-13 08:52:15 UTC
+++ setup.py
@@ -57,7 +57,6 @@ setup(
     platforms="any",
     provides=["imageio_ffmpeg"],
     python_requires=">=3.5",
-    setup_requires=["pip>19"],
     install_requires=[],
     packages=["imageio_ffmpeg"],
     package_dir={"imageio_ffmpeg": "imageio_ffmpeg"},
