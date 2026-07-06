diff --git setup.py setup.py
index b06c872..fba3906 100644
--- setup.py
+++ setup.py
@@ -318,7 +318,7 @@ setup(
     cmdclass={"build_ext": my_build_ext},
     ext_modules=[make_extension()],
     test_suite="tests",
-    setup_requires=["Cython>=3.0.0,<3.2.0", "cysignals"],
+    setup_requires=["Cython>=3.0.0", "cysignals"],
     install_requires=["cysignals"],
     packages=["tesserocr"],
     package_dir={"tesserocr": "tesserocr"},
