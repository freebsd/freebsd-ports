--- src/Guile/Scheme/object.hpp.orig	Mon Nov  3 01:07:27 2003
+++ src/Guile/Scheme/object.hpp	Mon Nov  3 01:06:19 2003
@@ -16,7 +16,7 @@
 #include "path.hpp"
 #include "command.hpp"
 #include "url.hpp"
-#include <libguile.h>
+#include "libguile.h"
 
 class object_rep: concrete_struct {
   SCM handle;
