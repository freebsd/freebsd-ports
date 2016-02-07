--- Opcodes/chua/ChuaOscillator.cpp.orig	2015-09-29 11:13:27 UTC
+++ Opcodes/chua/ChuaOscillator.cpp
@@ -117,8 +117,8 @@
 //     d = sys_variables(12);
 //     gnor = a*(x.^3) + b*(x.^2) + c*x + d;
 
-#include <OpcodeBase.hpp>
 #include <boost/numeric/ublas/vector.hpp>
+#include <OpcodeBase.hpp>
 using namespace boost::numeric;
 #include <cmath>
 
