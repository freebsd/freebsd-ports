--- include/cllazyfile/judyS2Array.h.orig	2024-11-21 19:04:57 UTC
+++ include/cllazyfile/judyS2Array.h
@@ -51,7 +51,7 @@ class judyS2Array {
         explicit judyS2Array( const judyS2Array< JudyValue > & other ): _maxKeyLen( other._maxKeyLen ), _success( other._success ) {
             _judyarray = judy_clone( other._judyarray );
             _buff = new unsigned char[_maxKeyLen];
-            strncpy( _buff, other._buff, _maxKeyLen );
+            strncpy( (char*)_buff, (char*)other._buff, _maxKeyLen );
             _buff[ _maxKeyLen ] = '\0'; //ensure that _buff is null-terminated, since strncpy won't necessarily do so
             find( _buff ); //set _lastSlot
         }
