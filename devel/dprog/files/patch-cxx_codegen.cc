--- cxx_codegen.cc.orig	Mon Apr 12 11:13:48 2004
+++ cxx_codegen.cc	Mon Apr 12 11:15:00 2004
@@ -8,6 +8,7 @@
 #include <fstream>
 #include <sstream>
 #include <set>
+#include <cassert>
 
 using namespace ast;
 using namespace std;
@@ -83,7 +84,7 @@
 {
     _cc_os << "for (int " << rexpr.index() << " = ";
     rexpr.begin()->accept(*this);
-    if (not rexpr.begin_br()->include())
+    if (! rexpr.begin_br()->include())
 	{
 	    if (rexpr.begin_br()->is_less())
 		_cc_os << " + 1";
