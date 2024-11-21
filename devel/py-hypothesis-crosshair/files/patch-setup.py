--- setup.py.orig	2024-10-18 11:40:32 UTC
+++ setup.py
@@ -11,7 +11,7 @@ setuptools.setup(
     description="Level-up your Hypothesis tests with CrossHair.",
     long_description=open("README.md", encoding="utf-8").read(),
     long_description_content_type="text/markdown",
-    install_requires=["hypothesis>=6.113.0", "crosshair-tool>=0.0.74"],
+    install_requires=["crosshair-tool>=0.0.74"],
     python_requires=">=3.8",
     entry_points={
         "hypothesis": ["_ = hypothesis_crosshair_provider:_hypothesis_setup_hook"]
