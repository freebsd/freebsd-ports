--- src/api/ruby/sqlrelay.C.orig	Tue Apr  2 12:46:18 2002
+++ src/api/ruby/sqlrelay.C	Mon Oct 28 02:51:20 2002
@@ -4,7 +4,8 @@
 #include <ruby.h>
 #include "../c++/include/sqlrelay/sqlrclient.h"
 
-#include "rubyincludes.h"
+#include "rubyincludes1.h"
+#include "rubyincludes2.h"
 
 extern "C" {
 
