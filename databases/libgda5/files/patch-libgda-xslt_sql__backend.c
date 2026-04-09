--- libgda-xslt/sql_backend.c.orig	2020-11-08 20:23:19 UTC
+++ libgda-xslt/sql_backend.c
@@ -146,8 +146,8 @@ _gda_xslt_bk_section (GdaXsltExCont * exec, GdaXsltInt
 		     cur_node = cur_node->next) {
 			if (IS_XSLT_ELEM (cur_node)) {
 				if (IS_XSLT_NAME (cur_node, "call-template")) {
-					xsltStylePreCompPtr info =
-						(xsltStylePreCompPtr)
+					xsltElemPreCompPtr info =
+						(xsltElemPreCompPtr)
 						cur_node->psvi;
 					if (info != NULL) {
 						xsltCallTemplate
