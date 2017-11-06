--- defs.pxd.orig	2017-03-30 01:24:59 UTC
+++ defs.pxd
@@ -490,7 +490,7 @@ cdef extern from "sys/extattr.h" nogil:
     char *EXTATTR_NAMESPACE_SYSTEM_STRING
     
     ssize_t extattr_get_fd(int fd, int attrnamespace, const char *attrname, void *data, size_t nbytes)
-    ssize_t exattr_set_fd(int fd, int attrnamespace, const char *attrname, const void *data, size_t nbytes)
+    ssize_t extattr_set_fd(int fd, int attrnamespace, const char *attrname, const void *data, size_t nbytes)
     int extattr_delete_fd(int fd, int attrnamespace, const char *attrname)
     ssize_t extattr_list_fd(int fd, int attrnamespace, void *data, size_t nbytes)
 
