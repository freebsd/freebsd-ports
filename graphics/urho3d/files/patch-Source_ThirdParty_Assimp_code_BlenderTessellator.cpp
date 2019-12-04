--- Source/ThirdParty/Assimp/code/BlenderTessellator.cpp.orig	2019-06-19 03:39:32 UTC
+++ Source/ThirdParty/Assimp/code/BlenderTessellator.cpp
@@ -374,8 +374,8 @@ void BlenderTessellatorP2T::ReferencePoints( std::vect
 // ------------------------------------------------------------------------------------------------
 // Yes this is filthy... but we have no choice
 #define OffsetOf( Class, Member ) ( static_cast< unsigned int >( \
-    reinterpret_cast<uint8_t*>(&( reinterpret_cast< Class* >( NULL )->*( &Class::Member ) )) - \
-    static_cast<uint8_t*>(NULL) ) )
+    reinterpret_cast<uint8_t*>(&( reinterpret_cast< Class* >( 0 )->*( &Class::Member ) )) - \
+    static_cast<uint8_t*>(0) ) )
 
 inline PointP2T& BlenderTessellatorP2T::GetActualPointStructure( p2t::Point& point ) const
 {
