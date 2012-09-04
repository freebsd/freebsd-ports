--- upnp/src/inc/uuid.h.orig	2012-02-23 18:48:42.000000000 +0100
+++ upnp/src/inc/uuid.h	2012-09-04 20:09:52.000000000 +0200
@@ -22,6 +22,14 @@
 
 #include "sysdep.h"
 
+#ifdef __FreeBSD__
+/* Workaround to avoid picking up different uuid_* fns from FreeBSD's libc */
+#define uuid_create		libupnp_uuid_create
+#define uuid_unpack		libupnp_uuid_unpack
+#define uuid_create_from_name	libupnp_uuid_create_from_name
+#define uuid_compare		libupnp_uuid_compare
+#endif
+
 /*! . */
 typedef struct _uuid_upnp {
 	/*! . */
