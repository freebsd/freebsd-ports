--- interbase.c.orig	2016-12-16 10:59:02 UTC
+++ interbase.c
@@ -940,7 +940,7 @@ static void _php_ibase_connect(INTERNAL_
 		xlink = (zend_resource*) le->ptr;
 		if ((!persistent && xlink->type == le_link) || xlink->type == le_plink) {
 			if (IBG(default_link)) {
-				zend_list_close(IBG(default_link));
+				zend_list_delete(IBG(default_link));
 			}
 			xlink->gc.refcount++;
 			xlink->gc.refcount++;
