--- src/scim_uim_imengine.cpp.orig	2008-05-19 00:54:00.000000000 +0900
+++ src/scim_uim_imengine.cpp	2008-05-19 00:55:43.000000000 +0900
@@ -34,7 +34,8 @@
 
 #include <scim.h>
 #include "scim_uim_imengine.h"
-#include <uim/uim-compat-scm.h>
+#include <uim/uim-scm.h>
+#include <uim/uim-util.h>
 
 #define scim_module_init uim_LTX_scim_module_init
 #define scim_module_exit uim_LTX_scim_module_exit
