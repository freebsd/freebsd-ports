--- server/file.c.orig	2020-10-25 09:54:42.043906000 +0000
+++ server/file.c	2020-10-25 10:46:07.706926000 +0000
@@ -65,10 +65,27 @@
 #ifndef XATTR_USER_PREFIX
 #define XATTR_USER_PREFIX "user."
 #endif
+
+#ifndef XATTR_USER_PREFIX_LEN
+#define XATTR_USER_PREFIX_LEN (sizeof(XATTR_USER_PREFIX) - 1)
+#endif
+
 #ifndef XATTR_SIZE_MAX
 #define XATTR_SIZE_MAX    65536
 #endif
 
+#ifdef HAVE_SYS_EXTATTR_H
+static inline int xattr_valid_namespace( const char *name )
+{
+    if (strncmp( XATTR_USER_PREFIX, name, XATTR_USER_PREFIX_LEN ) != 0)
+    {
+        errno = EPERM;
+        return 0;
+    }
+    return 1;
+}
+#endif
+
 /* We intentionally do not match the Samba 4 extended attribute for NT security descriptors (SDs):
  *  1) Samba stores this information using an internal data structure (we use a flat NT SD).
  *  2) Samba uses the attribute "security.NTACL".  This attribute is within a namespace that only
