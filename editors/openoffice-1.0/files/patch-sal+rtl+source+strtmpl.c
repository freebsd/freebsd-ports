--- sal/rtl/source/strtmpl.c.orig	Mon Mar 11 01:28:38 2002
+++ sal/rtl/source/strtmpl.c	Mon Mar 11 01:30:42 2002
@@ -1104,10 +1104,12 @@
         }
         else if ( *pStr == '+' )
         {
-            if ( bExp && (nExp != 0) )
-                break;
-            if ( fRet != 0.0 )
-                break;
+		if ( bExp ) {
+			if ( nExp != 0 )
+				break;
+			}
+		else if ( fRet != 0.0 )
+			break;
         }
         /* Exponent separator */
         else if ( (*pStr == 'e') || (*pStr == 'E') )
