--- midimountain/main.cpp.orig	Sat Dec 15 14:45:48 2001
+++ midimountain/main.cpp	Sat Dec 15 14:46:50 2001
@@ -30,11 +30,11 @@
   }
   else
   {
-    fp = fopen( "./midimountain.conf", "r");
+    fp = fopen( "%%PREFIX%%/etc/midimountain.conf", "r");
     if ( fp != 0 )
     {
       fclose( fp );
-    	mvcMain = new TMvcMain( "./midimountain.conf" );
+    	mvcMain = new TMvcMain( "%%PREFIX%%/etc/midimountain.conf" );
     }
     else
     {
