--- src/cong-location.c.orig	Thu Aug 14 17:24:36 2003
+++ src/cong-location.c	Sat Aug 30 18:50:41 2003
@@ -4,6 +4,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include "cong-document.h"
+#include "cong-dispspec.h"
 #include "cong-error-dialog.h"

 gboolean
@@ -328,7 +329,7 @@
 			else if (cong_node_type(n) == CONG_NODE_TYPE_ELEMENT)
 			{
 				if (!strcmp(cong_node_name(n), "table")) break;
-				if (cong_dispspec_element_structural(dispspec, xml_frag_name_nice(n)))
+				if (cong_dispspec_element_structural(dispspec, cong_node_get_xmlns(n), xml_frag_name_nice(n)))
 				{
 					n = n0 = 0;
 					break;
@@ -352,7 +353,7 @@

 		while (n)
 		{
-			if (cong_dispspec_element_structural(dispspec, xml_frag_name_nice(n))) { n = 0; break; }
+			if (cong_dispspec_element_structural(dispspec, cong_node_get_xmlns(n), xml_frag_name_nice(n))) { n = 0; break; }
 			if (!cong_node_prev(n)) n = n0 = cong_node_parent(n);
 			else break;
 		}
@@ -417,7 +418,7 @@
 			else if (cong_node_type(n) == CONG_NODE_TYPE_ELEMENT)
 			{
 				if (!strcmp(cong_node_name(n), "table")) break;
-				if (cong_dispspec_element_structural(dispspec, xml_frag_name_nice(n)))
+				if (cong_dispspec_element_structural(dispspec, cong_node_get_xmlns(n), xml_frag_name_nice(n)))
 				{
 					n = n0 = 0;
 					break;
@@ -441,7 +442,7 @@

 		while (n)
 		{
-			if (cong_dispspec_element_structural(dispspec, xml_frag_name_nice(n))) { n = 0; break; }
+			if (cong_dispspec_element_structural(dispspec, cong_node_get_xmlns(n), xml_frag_name_nice(n))) { n = 0; break; }
 			if (!cong_node_next(n)) n = n0 = cong_node_parent(n);
 			else break;
 		}
