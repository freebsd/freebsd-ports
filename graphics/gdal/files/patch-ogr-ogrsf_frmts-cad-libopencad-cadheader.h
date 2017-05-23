Obtained from:	https://github.com/nextgis-borsch/lib_opencad/commit/f40ce46804f1612fbeb035d0be5a746105cfc17e

--- ogr/ogrsf_frmts/cad/libopencad/cadheader.h.orig	2017-04-28 16:07:33 UTC
+++ ogr/ogrsf_frmts/cad/libopencad/cadheader.h
@@ -79,10 +79,8 @@ public:
     // cppcheck-suppress noExplicitConstructor
     CADVariant( const std::string& val );
     // cppcheck-suppress noExplicitConstructor
-    CADVariant( time_t val );
-public:
-    CADVariant( const CADVariant& orig );
-    CADVariant& operator=( const CADVariant& orig );
+    CADVariant( long julianday, long milliseconds );
+
 public:
     long                getDecimal() const;
     double              getReal() const;
