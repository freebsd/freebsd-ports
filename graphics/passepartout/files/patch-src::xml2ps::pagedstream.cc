--- src/xml2ps/pagedstream.cc.orig	Sun Nov  2 11:48:29 2003
+++ src/xml2ps/pagedstream.cc	Sun Nov  2 11:49:54 2003
@@ -3,6 +3,8 @@
 #include <fstream>
 #include <sstream>
 #include <iostream>
+#include <exception>
+#include <memory>
 
 xml2ps::PagedStream::PagedStream() 
   : current_part(0)
