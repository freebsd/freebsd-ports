--- class/LKV/List.h	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/List.h	20 Feb 2006 11:08:10 -0000
@@ -12,7 +12,7 @@
 
 #include "AllocBuf.h"
 
-class ostream;
+#include "Bstream.h"
 
 template <class T>
 class List;
@@ -35,13 +35,13 @@
 	ListItem( void ) : T()
 #ifdef DEBUG
 	 , next((ListItem *)0), prev((ListItem *)0)
-#endif DEBUG
+#endif /* DEBUG */
 	  { };
 	  
 	ListItem( const T & val ) : T(val)
 #ifdef DEBUG
 	 , next((ListItem *)0), prev((ListItem *)0)
-#endif DEBUG
+#endif /* DEBUG */
 	  { };
 
 	ListItem * get_next(void) const {
@@ -59,6 +59,9 @@
 
 
 template <class T>
+BIstream & operator>> (BIstream & in, List<T> & list);
+
+template <class T>
 class List {
 	
 protected:
@@ -239,7 +242,7 @@
 		return last;
 	};
 	
-	friend BIstream & operator>> (BIstream & in, List<T> & list);			
+	friend BIstream & operator>><> (BIstream & in, List<T> & list);
 };
 
 template <class T>
@@ -306,4 +309,4 @@
 }
 
 
-#endif List_h
+#endif /* List_h */
