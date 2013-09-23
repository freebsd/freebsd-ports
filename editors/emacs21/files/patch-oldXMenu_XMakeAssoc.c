
$FreeBSD$

--- oldXMenu/XMakeAssoc.c.orig
+++ oldXMenu/XMakeAssoc.c
@@ -37,7 +37,7 @@
  * meaningless (but cause no problems).  The queue in each association
  * bucket is sorted (lowest XId to highest XId).
  */
-XMakeAssoc(dpy, table, x_id, data)
+void XMakeAssoc(dpy, table, x_id, data)
 	register Display *dpy;
 	register XAssocTable *table;
 	register XID x_id;
