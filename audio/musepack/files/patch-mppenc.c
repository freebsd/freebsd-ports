--- mppenc.c.orig	Fri Dec 15 13:34:57 2006
+++ mppenc.c	Fri Dec 15 13:35:14 2006
@@ -1864,7 +1864,7 @@
 }
 
 
-static void
+void
 OverdriveReport ( void )
 {
     if ( Overflows > 0 ) {                                                // 
