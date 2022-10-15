--- plugins/builtin/source/content/helpers/math_evaluator.cpp.orig	2022-10-12 10:48:50 UTC
+++ plugins/builtin/source/content/helpers/math_evaluator.cpp
@@ -434,9 +434,9 @@ namespace hex {
     template<typename T>
     void MathEvaluator<T>::registerStandardVariables() {
         this->setVariable("ans", 0);
-        this->setVariable("pi", std::numbers::pi, true);
-        this->setVariable("e", std::numbers::e, true);
-        this->setVariable("phi", std::numbers::phi, true);
+        this->setVariable("pi", 3.141592653589793238462643383279502884L, true);
+        this->setVariable("e", 2.718281828459045235360287471352662498L, true);
+        this->setVariable("phi", 1.618033988749894848204586834365638117L, true);
     }
 
     template<typename T>
