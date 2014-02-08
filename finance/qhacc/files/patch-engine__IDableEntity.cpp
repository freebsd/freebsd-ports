--- engine/IDableEntity.cpp.orig
+++ engine/IDableEntity.cpp
@@ -21,7 +21,7 @@
 
 const int IDableEntity::NOID = -1;
 
-IDableEntity::IDableEntity( int _id = NOID ) {
+IDableEntity::IDableEntity( int _id ) {
   setId( _id );
 }
 
