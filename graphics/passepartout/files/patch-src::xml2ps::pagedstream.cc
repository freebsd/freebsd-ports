--- src/xml2ps/pagedstream.cc.orig	Thu Nov 20 04:13:54 2003
+++ src/xml2ps/pagedstream.cc	Fri Nov 21 16:32:48 2003
@@ -7,6 +7,8 @@
 #include <sstream>
 #include <iostream>
 #include <vector>
+#include <exception>
+#include <memory>
 
 xml2ps::PagedStream::PagedStream() 
   : current_part(0)
