--- kpdf/xpdf/xpdf/PDFDoc.cc.orig	Tue Aug  2 19:37:37 2005
+++ kpdf/xpdf/xpdf/PDFDoc.cc	Tue Aug  2 19:43:32 2005
@@ -115,24 +115,20 @@
 GBool PDFDoc::setup(GString *ownerPassword, GString *userPassword) {
   str->reset();
   
-  char eof[8];
+  char *eof = new char[1025];
   int pos = str->getPos();
-  str->setPos(7, -1);
-  eof[0] = str->getChar();
-  eof[1] = str->getChar();
-  eof[2] = str->getChar();
-  eof[3] = str->getChar();
-  eof[4] = str->getChar();
-  eof[5] = str->getChar();
-  eof[6] = str->getChar();
-  eof[7] = '\0';
+  str->setPos(1024, -1);
+  for (int i = 0; i < 1024; i++) eof[i] = str->getChar();
+  eof[1024] = '\0';
   if (strstr(eof, "%%EOF") == NULL)
   {
     error(-1, "Document does not have ending %%EOF");	      
     errCode = errDamaged;
+    delete[] eof;
     return gFalse;
   }
-  
+  delete[] eof;
+
   str->setPos(pos);
   
   // check header
