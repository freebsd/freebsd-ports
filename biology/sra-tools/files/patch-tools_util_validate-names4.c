--- tools/util/validate-names4.c.orig	2021-06-20 17:53:25 UTC
+++ tools/util/validate-names4.c
@@ -30,8 +30,8 @@
 #include <klib/rc.h> /* RC */
 #include <vfs/path.h> /* VPath */
 
-#include "../../../ncbi-vdb/libs/vfs/json-response.h" /* Response4Make4 */
-#include "../../../ncbi-vdb/libs/vfs/services-priv.h"/*KServiceGetKSrvResponse*/
+#include "../libs/vfs/json-response.h" /* Response4Make4 */
+#include "../libs/vfs/services-priv.h"/*KServiceGetKSrvResponse*/
 
 #define RELEASE(type, obj) do { rc_t rc2 = type##Release(obj); \
     if (rc2 && !rc) { rc = rc2; } obj = NULL; } while (false)
