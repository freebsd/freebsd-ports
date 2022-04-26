--- setup.py.orig	2022-03-18 21:14:31 UTC
+++ setup.py
@@ -17,7 +17,7 @@ extras_require: dict[str, list[str]] = {
     "dataframe": ["numpy >= 1.18", "pandas >= 1.0"],
     "distributed": ["distributed == 2022.03.0"],
     "diagnostics": [
-        "bokeh >= 2.4.2",
+        "bokeh >= 2.3.3",
         "jinja2",
     ],
     "delayed": [],  # keeping for backwards compatibility
