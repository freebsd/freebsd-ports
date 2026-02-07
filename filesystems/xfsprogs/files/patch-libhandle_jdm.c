--- libhandle/jdm.c.orig	2015-07-24 04:28:04 UTC
+++ libhandle/jdm.c
@@ -21,6 +21,8 @@
 #include <xfs/jdm.h>
 #include <xfs/parent.h>
 
+#define XATTR_LIST_MAX	65536
+
 /* internal fshandle - typecast to a void for external use */
 #define FSHANDLE_SZ		8
 typedef struct fshandle {
