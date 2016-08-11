--- src/libUnicorn/Settings.h.orig	2016-07-26 15:06:09 UTC
+++ src/libUnicorn/Settings.h
@@ -105,7 +105,7 @@ protected:
     public:
         MyQSettings( const UserSettings* const s )
         {
-            beginGroup( s->username() );
+            T::beginGroup( s->username() );
         }
     };
 
