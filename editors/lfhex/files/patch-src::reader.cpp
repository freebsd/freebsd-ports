--- src/reader.cpp.orig	Sat Jul  7 04:16:01 2001
+++ src/reader.cpp	Sun Feb 23 00:46:53 2003
@@ -227,7 +227,7 @@
     // free the page which is the furthest away from the page we are loading
 
     // this could be trouble if off_t is unsigned!
-    if( abs(_firstPage - pageIdx) > abs(_lastPage - pageIdx) ) 
+    if( abs((long int)(_firstPage - pageIdx)) > abs((long int)(_lastPage - pageIdx)) ) 
       while(!freePage(_firstPage++));
     else
       while(!freePage(_lastPage--));
@@ -285,7 +285,7 @@
 #ifdef LFHEX_IOS_BASE_FMTFLAGS
 ostream& operator<< (ostream&out, const ReadBuffer& buff)
 {
-  ios_base::fmtflags old_flags = out.flags();
+  ios::fmtflags old_flags = out.flags();
   out.flags(old_flags | ios::hex | ios::showbase);
   for(size_t i = 0; i < buff.size(); i++)
     out << buff[i];
