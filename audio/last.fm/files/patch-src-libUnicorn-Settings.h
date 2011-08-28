--- src/libUnicorn/Settings.h.orig	2011-08-28 17:30:32.000000000 +0200
+++ src/libUnicorn/Settings.h	2011-08-28 17:31:03.000000000 +0200
@@ -105,7 +105,7 @@
     public:
         MyQSettings( const UserSettings* const s )
         {
-            beginGroup( s->username() );
+            T::beginGroup( s->username() );
         }
     };
 
