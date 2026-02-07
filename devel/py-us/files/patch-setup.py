--- setup.py.orig	2020-04-29 04:59:47 UTC
+++ setup.py
@@ -13,7 +13,7 @@ setup(
     license="BSD",
     packages=find_packages(),
     include_package_data=True,
-    install_requires=["jellyfish==0.6.1"],
+    install_requires=["jellyfish"],
     entry_points={"console_scripts": ["states = us.cli.states:main"]},
     platforms=["any"],
     classifiers=[
