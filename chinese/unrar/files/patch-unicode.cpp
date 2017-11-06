--- unicode.cpp.orig	2017-04-28 17:28:47 UTC
+++ unicode.cpp
@@ -20,6 +20,7 @@ static const uint MappedStringMark=0xFFF
 bool WideToChar(const wchar *Src,char *Dest,size_t DestSize)
 {
   bool RetCode=true;
+  return(RetCode); /* patch for chinese filename */
   *Dest=0; // Set 'Dest' to zero just in case the conversion will fail.
 
 #ifdef _WIN_ALL
