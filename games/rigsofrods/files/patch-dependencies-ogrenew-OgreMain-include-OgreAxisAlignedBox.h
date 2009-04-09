--- dependencies/ogrenew/OgreMain/include/OgreAxisAlignedBox.h.orig	2009-02-22 20:59:55.000000000 +0300
+++ dependencies/ogrenew/OgreMain/include/OgreAxisAlignedBox.h	2009-04-08 05:57:39.000000000 +0400
@@ -235,8 +235,8 @@
 		*/
 		inline void setExtents( const Vector3& min, const Vector3& max )
 		{
-            assert( (min.x <= max.x && min.y <= max.y && min.z <= max.z) &&
-                "The minimum corner of the box must be less than or equal to maximum corner" );
+//            assert( (min.x <= max.x && min.y <= max.y && min.z <= max.z) &&
+//                "The minimum corner of the box must be less than or equal to maximum corner" );
 
 			mExtent = EXTENT_FINITE;
 			mMinimum = min;
