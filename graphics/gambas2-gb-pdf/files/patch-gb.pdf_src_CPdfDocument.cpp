--- gb.pdf/src/CPdfDocument.cpp.orig	2009-07-25 21:33:49.000000000 +0000
+++ gb.pdf/src/CPdfDocument.cpp	2011-10-25 19:38:45.000000000 +0000
@@ -510,9 +510,15 @@ END_PROPERTY
 BEGIN_PROPERTY(PDFINFO_format)
 
 	char *ctx=NULL;
+	double version;
+	int major, minor;
+
+	major = THIS->doc->getPDFMajorVersion();
+	minor = THIS->doc->getPDFMinorVersion();
+        version = (double)(major + minor *0.1);
 
 	GB.Alloc(POINTER(&ctx),16*sizeof(char));
-	snprintf(ctx,16*sizeof(char),"%.2g",THIS->doc->getPDFVersion());
+	snprintf(ctx,16*sizeof(char),"%.2g", version);
 	GB.ReturnNewZeroString(ctx);
 	GB.Free(POINTER(&ctx));
 
@@ -946,10 +952,7 @@ END_METHOD
 ******************************************************************************/
 void aux_fill_links(void *_object)
 {
-	Object obj;
-	
-	THIS->links = new Links (THIS->page->getAnnots (&obj),THIS->doc->getCatalog()->getBaseURI ());
-	obj.free();
+	THIS->links = new Links (THIS->page->getAnnots(THIS->doc->getCatalog()));
 }
 
 BEGIN_PROPERTY (PDFPAGELINKS_count)
