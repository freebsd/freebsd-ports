--- include/cllazyfile/judySArray.h.orig	2024-11-21 18:30:49 UTC
+++ include/cllazyfile/judySArray.h
@@ -39,7 +39,7 @@ class judySArray {
         explicit judySArray( const judySArray< JudyValue > & other ): _maxKeyLen( other._maxKeyLen ), _success( other._success ) {
             _judyarray = judy_clone( other._judyarray );
             _buff = new unsigned char[_maxKeyLen];
-            strncpy( _buff, other._buff, _maxKeyLen );
+            strncpy( (char*)_buff, (char*)other._buff, _maxKeyLen );
             _buff[ _maxKeyLen ] = '\0'; //ensure that _buff is null-terminated, since strncpy won't necessarily do so
             find( _buff ); //set _lastSlot
         }
