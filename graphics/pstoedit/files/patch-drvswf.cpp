--- drvswf.cpp.orig	Mon Dec 31 05:35:23 2001
+++ drvswf.cpp	Sat Mar  9 05:54:59 2002
@@ -415,7 +415,7 @@
 
 	// if the fontnames ends with .fdb, then the file is read, otherwise browser fonts are used.
 
-	SWFFont *f = new SWFFont(fontfilename.value());
+	SWFFont *f = new SWFFont((char *)fontfilename.value());
 	if ((f == NULL) || (f->font == NULL)) {
 		errf << "Loading font " << fontfilename.value() << " failed !" << endl;
 		return;
