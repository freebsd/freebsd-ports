--- src/score.cpp.orig	Sat Jan 22 01:59:45 2005
+++ src/score.cpp	Sat Jan 22 01:59:56 2005
@@ -449,7 +449,7 @@
     }
     close(_iHandle);
   }
-  if(_pMemoire)
+  if(_pMemoire && sDescriptionFichier.st_size > 0)
   {
     char                   *_pBufferC = _pMemoire;
     int                    *_pBufferL;
