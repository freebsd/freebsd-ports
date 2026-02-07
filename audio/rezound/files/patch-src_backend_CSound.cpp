--- src/backend/CSound.cpp.orig	2010-02-28 06:32:54 UTC
+++ src/backend/CSound.cpp
@@ -2289,7 +2289,7 @@ void CSound::setUserNotes(const string &
 
 
 // this is the explicit instantiation of the TPoolFile for CSound's purposes 
-#include <TPoolFile.cpp>
+// #include <TPoolFile.cpp>
 template class TPoolFile<sample_pos_t,uint64_t>;
 
 // Some explicit template method instantiations (not sure why some are necessary and some aren't)
