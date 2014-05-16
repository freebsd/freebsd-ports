--- librdf/rdflib.c.orig	Wed Oct  4 02:00:07 2000
+++ librdf/rdflib.c	Thu Aug 22 02:05:39 2002
@@ -194,2 +194,4 @@
 
+extern FILE *rdfpGetFile(RDF_Parser rdfp);
+
 RDF_Result 
@@ -200,3 +202,2 @@
                        RDF_ASSERT, getFileCode(rdfp)) && (rdfpGetFile(rdfp))) {
-    extern FILE *rdfpGetFile(RDF_Parser rdfp);
     FILE *file = rdfpGetFile(rdfp);
