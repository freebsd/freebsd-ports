
$FreeBSD$

--- svrv_object.c
+++ svrv_object.c
@@ -18,6 +18,9 @@
 #include "lang_map.h"
 #include "try_perlapi.h"
 
+#define PERL_CORE
+#include <embed.h>
+
 #ifdef MULTI_PERL
 static int
 owned_by(PySVRV *self, refcounted_perl *my_perl)
