--- src/libvpsc/csolve_VPSC.h.bak	2011-07-08 20:25:09.468790000 +0200
+++ src/libvpsc/csolve_VPSC.h	2013-10-17 12:54:54.000000000 +0200
@@ -11,10 +11,7 @@
 #ifndef _CSOLVE_VPSC_H_
 #define _CSOLVE_VPSC_H_
 #ifdef __cplusplus
-class vpsc::Variable;
-class vpsc::Constraint;
-class vpsc::Solver;
-class vpsc::IncSolver;
+
 using namespace vpsc;
 extern "C" {
 #else
