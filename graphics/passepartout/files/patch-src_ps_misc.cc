--- src/ps/misc.cc.orig	2007-07-04 13:49:34.000000000 -0400
+++ src/ps/misc.cc	2007-07-04 13:48:35.000000000 -0400
@@ -3,6 +3,8 @@
 ///
 #include "misc.h"
 
-std::ostream& PS::operator << (std::ostream& out, const PS::Concat& c) {
+namespace PS {
+std::ostream& operator << (std::ostream& out, const Concat& c) {
   return out << '[' << c.matrix << "] concat\n";
 }
+}
