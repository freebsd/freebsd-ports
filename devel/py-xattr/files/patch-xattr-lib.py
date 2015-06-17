--- xattr.orig/lib.py
+++ xattr/lib.py
@@ -48,6 +48,8 @@
 #define XATTR_XATTR_REPLACE 0x0004
 #define XATTR_XATTR_NOSECURITY 0x0008
 
+#define XATTR_CREATE 0x1
+#define XATTR_REPLACE 0x2
 
 /* Converts a freebsd format attribute list into a NULL terminated list.
  * While the man page on extattr_list_file says it is NULL terminated,
