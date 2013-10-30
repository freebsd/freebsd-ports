--- ./utils/pxattr.cpp.orig	2013-09-30 18:45:06.000000000 +0200
+++ ./utils/pxattr.cpp	2013-10-29 15:57:51.000000000 +0100
@@ -326,6 +326,7 @@
 	return false;
     if (!buf.alloc(ret+1)) // NEEDED on FreeBSD (no ending null)
 	return false;
+    buf.buf[ret] = 0;
     if (fd < 0) {
 	if (flags & PXATTR_NOFOLLOW) {
 	    ret = extattr_list_link(path.c_str(), EXTATTR_NAMESPACE_USER, 
