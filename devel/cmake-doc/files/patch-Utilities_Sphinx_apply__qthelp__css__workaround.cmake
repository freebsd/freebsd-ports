The file Sphinx generates is currently called classic.css, not default.css.
--- Utilities/Sphinx/apply_qthelp_css_workaround.cmake.orig	2016-03-08 14:36:25 UTC
+++ Utilities/Sphinx/apply_qthelp_css_workaround.cmake
@@ -1,7 +1,7 @@
 
 file(READ "${CSS_DIR}/basic.css" BasicCssContent)
 
-file(READ "${CSS_DIR}/default.css" DefaultCssContent)
+file(READ "${CSS_DIR}/classic.css" DefaultCssContent)
 string(REPLACE
   "@import url(\"basic.css\")" "${BasicCssContent}"
   DefaultCssContent "${DefaultCssContent}"
