--- gb.pdf/src/CPdfDocument.cpp.orig	2009-09-27 18:30:35.000000000 +0200
+++ gb.pdf/src/CPdfDocument.cpp	2009-09-27 20:10:45.000000000 +0200
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
 
