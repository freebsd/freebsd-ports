--- libhandle/handle.c.orig	2015-07-24 04:28:04 UTC
+++ libhandle/handle.c
@@ -23,6 +23,7 @@
 
 /* just pick a value we know is more than big enough */
 #define	MAXHANSIZ	64
+#define	XATTR_LIST_MAX	65536
 
 /*
  *  The actual content of a handle is supposed to be opaque here.
