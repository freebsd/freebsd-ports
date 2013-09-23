
$FreeBSD$

--- oldXMenu/XDelAssoc.c.orig
+++ oldXMenu/XDelAssoc.c
@@ -27,7 +27,7 @@
  * an XId.  An association may be removed only once.  Redundant
  * deletes are meaningless (but cause no problems).
  */
-XDeleteAssoc(dpy, table, x_id)
+void XDeleteAssoc(dpy, table, x_id)
         register Display *dpy;
 	register XAssocTable *table;
 	register XID x_id;
