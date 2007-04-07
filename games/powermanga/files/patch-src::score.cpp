--- src/score.cpp.orig	Mon Jan 31 17:44:33 2005
+++ src/score.cpp	Sat Apr  7 18:00:49 2007
@@ -749,7 +749,7 @@
   //##############################################################
   // copy data file into memory structure
   //##############################################################
-  if (_pMemoire)
+  if(_pMemoire && sDescriptionFichier.st_size > 0)
     {
       char *_pBufferC = _pMemoire;
       Sint32 *_pBufferL;
