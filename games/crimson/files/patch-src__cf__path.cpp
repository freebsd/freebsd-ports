--- ./src/cf/path.cpp.orig	2013-10-31 19:17:06.000000000 -0200
+++ ./src/cf/path.cpp	2013-10-31 19:17:43.000000000 -0200
@@ -212,7 +212,7 @@
 // RETURNS    : estimated cost to destination
 ////////////////////////////////////////////////////////////////////////
 
-inline unsigned short Path::ETA( const Point &p ) const {
+unsigned short Path::ETA( const Point &p ) const {
   return Distance( p, end ) * quality;
 }
 
@@ -249,7 +249,7 @@
 // RETURNS    : TRUE if search aborted, FALSE otherwise
 ////////////////////////////////////////////////////////////////////////
 
-inline bool Path::StopSearch( const PathNode &next ) const {
+bool Path::StopSearch( const PathNode &next ) const {
   return Distance( next.pos, end ) <= deviation;
 }
 
