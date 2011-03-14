--- src/atom_parser.c.orig	2010-06-20 20:26:34.000000000 +0200
+++ src/atom_parser.c	2011-02-24 12:28:51.710766352 +0100
@@ -282,7 +282,8 @@ static int extract_and_check_multi(xmlDo
 		if (attr2) {
 			if (xmlHasProp(node->nodeTab[i], attr2)) {
 				tmp = xmlGetProp(node->nodeTab[i], attr2);
-				(*types)[i] = strdup(strchr(tmp,'#') + 1);
+				if (strchr(tmp,'#'))
+					(*types)[i] = strdup(strchr(tmp,'#') + 1);
 				xmlFree(tmp);
 			}
 			else
@@ -292,7 +293,8 @@ static int extract_and_check_multi(xmlDo
 		if (attr3) {
 			if (xmlHasProp(node->nodeTab[i], attr3)) {
 				tmp = xmlGetProp(node->nodeTab[i], attr3);
-				(*protocols)[i] = strdup(strchr(tmp,'#') + 1);
+				if (strchr(tmp,'#'))
+					(*protocols)[i] = strdup(strchr(tmp,'#') + 1);
 				xmlFree(tmp);
 			}
 			else
@@ -383,7 +385,8 @@ static int extract_and_check_multisub(xm
 		if (attr1) {
 			if (xmlHasProp(node->nodeTab[i], attr1)) {
 				tmp = xmlGetProp(node->nodeTab[i], attr1);
-				(*types)[i] = strdup(strchr(tmp,'#') + 1);
+				if (strchr(tmp,'#'))
+					(*types)[i] = strdup(strchr(tmp,'#') + 1);
 				xmlFree(tmp);
 			} else
 				(*types)[i] = strdup("");
