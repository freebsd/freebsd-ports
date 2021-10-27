--- src/aclhelpers_p.h.orig	2021-10-02 14:28:47 UTC
+++ src/aclhelpers_p.h
@@ -14,10 +14,10 @@
  *************************************/
 
 #include <KIO/UDSEntry>
+#if HAVE_POSIX_ACL
+#include "acl_portability.h"
+#endif
 
-#include <acl/libacl.h>
-#include <sys/acl.h>
-
 static QString aclToText(acl_t acl)
 {
     ssize_t size = 0;
@@ -33,7 +33,7 @@ static QString aclToText(acl_t acl)
 static void appendACLAtoms(const QByteArray &path, KIO::UDSEntry &entry, mode_t type)
 {
     // first check for a noop
-    if (acl_extended_file(path.data()) == 0) {
+    if (KIO::ACLPortability::acl_extended_file(path.data()) == 0) {
         return;
     }
 
@@ -46,7 +46,7 @@ static void appendACLAtoms(const QByteArray &path, KIO
      * ACL separately. Since a directory can have both, we need to check again. */
     if (isDir) {
         if (acl) {
-            if (acl_equiv_mode(acl, nullptr) == 0) {
+            if (KIO::ACLPortability::acl_equiv_mode(acl, nullptr) == 0) {
                 acl_free(acl);
                 acl = nullptr;
             }
