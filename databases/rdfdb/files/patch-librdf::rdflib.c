$FreeBSD$

--- librdf/rdflib.c.orig	Sat Jun  8 20:20:52 2002
+++ librdf/rdflib.c	Sat Jun  8 20:21:58 2002
@@ -196,9 +196,9 @@
 RDF_LoadFileAssert (RDF_Parser rdfp, RDF_DB db, RDF_Resource source, RDF_Resource arc, void* target, RDF_ValueType type) {
   if (gVerbose > 2) printAssertion("\nAsserting:", db, source, arc, target, type);  
   gAssertionCount++;
+  extern FILE *rdfpGetFile(RDF_Parser rdfp);
   if (!addRemoveTriple(db, source, arc, target, type, 
                        RDF_ASSERT, getFileCode(rdfp)) && (rdfpGetFile(rdfp))) {
-    extern FILE *rdfpGetFile(RDF_Parser rdfp);
     FILE *file = rdfpGetFile(rdfp);
     fprintf(file, "%s\t%s\t", arc, source);
     if (type == RDF_INT_TYPE) {
