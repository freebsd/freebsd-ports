
$FreeBSD$

--- tclcl.h.orig
+++ tclcl.h
@@ -45,7 +45,6 @@
 }
 
 #include "tclcl-config.h"
-#include "tclcl-mappings.h"
 #include "tracedvar.h"
 
 struct Tk_Window_;
@@ -253,6 +252,8 @@
 	InstVar* instvar_;
 	TracedVar* tracedvar_;
 };
+
+#include "tclcl-mappings.h"
 
 /*
  * johnh xxx: delete this
