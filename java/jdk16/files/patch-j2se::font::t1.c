$FreeBSD$

--- ../../j2se/src/share/native/sun/font/t2k/t1.c.orig	Tue Oct 19 15:00:39 2004
+++ ../../j2se/src/share/native/sun/font/t2k/t1.c	Tue Jul 18 21:42:18 2006
@@ -2035,9 +2035,10 @@
 
     if ( firstChar >= 'A' && firstChar <= 'Z' )
       lookupIndex = firstChar - 'A';
-    else
+    else if ( firstChar >= 'a' && firstChar <= 'z' )
       lookupIndex = firstChar - 'a' + 26;
-
+    else /* underscore is also valid but not handled */
+      return 0;
 
     startIndex = PSNAME_START_INDEX[ lookupIndex ];
     endIndex = PSNAME_START_INDEX[ lookupIndex + 1 ];
