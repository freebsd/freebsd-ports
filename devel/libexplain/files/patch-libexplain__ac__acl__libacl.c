--- libexplain/ac/acl/libacl.c.orig
+++ libexplain/ac/acl/libacl.c
@@ -18,10 +18,14 @@
  */
 
 #include <libexplain/ac/acl/libacl.h>
+#include <libexplain/ac/sys/acl.h>
+
+#include <libexplain/gcc_attributes.h>
 
 #ifndef HAVE_ACL_ENTRIES
 
-static int
+LIBEXPLAIN_LINKAGE_HIDDEN
+int
 acl_entries(acl_t acl)
 {
     int result = 0;
