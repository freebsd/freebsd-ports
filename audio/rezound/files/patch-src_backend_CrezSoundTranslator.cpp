--- src/backend/CrezSoundTranslator.cpp.orig	2013-02-10 06:35:01 UTC
+++ src/backend/CrezSoundTranslator.cpp
@@ -43,7 +43,7 @@ CrezSoundTranslator::~CrezSoundTranslato
 
 // need to include this I use some of the template *methods* for types that are no where else
 // so the explicit instantation at the bottom of CSound.cpp doesn't instantiate everything
-#include <TPoolFile.cpp>
+// #include <TPoolFile.cpp>
 
 struct RFormatInfo1
 {
