--- xbase/xbstring.h.orig	Sat Jan 27 06:00:32 2001
+++ xbase/xbstring.h	Sat Nov 22 22:30:42 2003
@@ -56,7 +56,11 @@
 #endif
 
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
+
+using std::endl;
+using std::cin;
+using std::cout;
 
 /*! \file xbstring.h
 */
@@ -119,7 +123,7 @@
   bool operator <= ( const xbString& ) const;
   bool operator >= ( const xbString& ) const;
 
-  friend ostream& operator << ( ostream&, const xbString& );
+  friend std::ostream& operator << ( std::ostream&, const xbString& );
 
   xbString &remove(size_t pos = 0, int n = npos);
   xbString mid(size_t pos = 0, int n = npos) const;
