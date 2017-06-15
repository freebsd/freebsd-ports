--- lib/cadheader.h.orig	2016-08-24 13:25:41 UTC
+++ lib/cadheader.h
@@ -35,6 +35,7 @@
 #include <map>
 #include <string>
 #include <vector>
+#include <ctime>
 
 class OCAD_EXTERN CADHandle final
 {
@@ -64,12 +65,13 @@ public:
     CADVariant();
     CADVariant( const char * val );
     CADVariant( int val );
+    CADVariant( long val );
     CADVariant( short val );
     CADVariant( double val );
     CADVariant( double x, double y, double z = 0 );
     CADVariant( const CADHandle& val );
     CADVariant( const std::string& val );
-    CADVariant( time_t val );
+    CADVariant( time_t val, bool bIsTime );
 public:
     CADVariant( const CADVariant& orig );
     CADVariant& operator=( const CADVariant& orig );
