$FreeBSD$

--- instance_owners.c.orig	Wed Jul 21 12:09:53 2004
+++ instance_owners.c	Wed Oct 20 02:01:44 2004
@@ -14,6 +14,10 @@
 #include <jmp-config.h>
 #include <inttypes.h>
 
+#ifndef PRId32
+#define PRId32 "d"
+#endif
+
 enum {
     INFO,
     OO_PARENT,
