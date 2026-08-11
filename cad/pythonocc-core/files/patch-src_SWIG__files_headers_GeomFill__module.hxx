--- src/SWIG_files/headers/GeomFill_module.hxx.orig	2026-08-04 19:50:29 UTC
+++ src/SWIG_files/headers/GeomFill_module.hxx
@@ -51,7 +51,8 @@ along with pythonOCC.  If not, see <http://www.gnu.org
 #include<GeomFill_FunctionGuide.hxx>
 #include<GeomFill_Generator.hxx>
 #include<GeomFill_Gordon.hxx>
-#include<GeomFill_GordonBuilder.hxx>
+// removed in 8.0.1
+// #include<GeomFill_GordonBuilder.hxx>
 #include<GeomFill_GuideTrihedronAC.hxx>
 #include<GeomFill_GuideTrihedronPlan.hxx>
 #include<GeomFill_HArray1OfLocationLaw.hxx>
