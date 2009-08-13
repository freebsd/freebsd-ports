--- dependencies/ogrenew/OgreMain/include/OgreAxisAlignedBox.h.orig	2009-02-09 02:40:02.000000000 +0300
+++ dependencies/ogrenew/OgreMain/include/OgreAxisAlignedBox.h	2009-08-13 04:16:09.000000000 +0400
@@ -235,9 +235,6 @@
 		*/
 		inline void setExtents( const Vector3& min, const Vector3& max )
 		{
-            assert( (min.x <= max.x && min.y <= max.y && min.z <= max.z) &&
-                "The minimum corner of the box must be less than or equal to maximum corner" );
-
 			mExtent = EXTENT_FINITE;
 			mMinimum = min;
 			mMaximum = max;
