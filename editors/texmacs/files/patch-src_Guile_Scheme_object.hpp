--- ./src/Guile/Scheme/object.hpp.orig	Sun Oct  3 13:26:27 2004
+++ ./src/Guile/Scheme/object.hpp	Sat Oct 23 17:39:48 2004
@@ -16,7 +16,7 @@
 #include "path.hpp"
 #include "command.hpp"
 #include "url.hpp"
-#include <libguile.h>
+#include "libguile.h"
 
 class object_rep: concrete_struct {
   SCM handle;
