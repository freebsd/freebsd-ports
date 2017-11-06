Obtained from:	https://github.com/nextgis-borsch/lib_opencad/commit/f40ce46804f1612fbeb035d0be5a746105cfc17e

--- ogr/ogrsf_frmts/cad/libopencad/cadheader.cpp.orig	2017-04-28 16:07:33 UTC
+++ ogr/ogrsf_frmts/cad/libopencad/cadheader.cpp
@@ -310,14 +310,22 @@ CADVariant::CADVariant( const string& va
 {
 }
 
-CADVariant::CADVariant( time_t val ) :
+CADVariant::CADVariant( long julianday, long milliseconds ) :
     type        ( DataType::DATETIME ),
     decimalVal  ( 0 ),
     xVal        ( 0 ),
     yVal        ( 0 ),
-    zVal        ( 0 ),
-    dateTimeVal ( val )
+    zVal        ( 0 )
 {
+    // unix -> julian        return ( unixSecs / 86400.0 ) + 2440587.5;
+    // julian -> unix        return (julian - 2440587.5) * 86400.0
+
+    double dfSeconds = double( milliseconds ) / 1000;
+    double dfUnix = 0;
+    if(julianday != 0)
+        dfUnix = ( double( julianday ) - 2440587.5 ) * 86400.0;
+    dateTimeVal = static_cast<time_t>( dfUnix + dfSeconds );
+
     char str_buff[256];
     strftime(str_buff, 255, "%Y-%m-%d %H:%M:%S", localtime(&dateTimeVal));
     stringVal = str_buff;
@@ -335,33 +343,6 @@ CADVariant::CADVariant( const CADHandle&
 {
 }
 
-CADVariant::CADVariant( const CADVariant& orig ) :
-    type        ( orig.type ),
-    decimalVal  ( orig.decimalVal ),
-    xVal        ( orig.xVal ),
-    yVal        ( orig.yVal ),
-    zVal        ( orig.zVal ),
-    stringVal   ( orig.stringVal ),
-    handleVal   ( orig.handleVal ),
-    dateTimeVal ( orig.dateTimeVal )
-{
-}
-
-CADVariant& CADVariant::operator=( const CADVariant& orig )
-{
-    if( this == & orig )
-        return * this;
-    type        = orig.type;
-    stringVal   = orig.stringVal;
-    decimalVal  = orig.decimalVal;
-    xVal        = orig.xVal;
-    yVal        = orig.yVal;
-    zVal        = orig.zVal;
-    handleVal   = orig.handleVal;
-    dateTimeVal = orig.dateTimeVal;
-    return * this;
-}
-
 long CADVariant::getDecimal() const
 {
     return decimalVal;
@@ -461,15 +442,7 @@ int CADHeader::addValue( short code, dou
 
 int CADHeader::addValue( short code, long julianday, long milliseconds )
 {
-    // unix -> julian        return ( unixSecs / 86400.0 ) + 2440587.5;
-    // julian -> unix        return (julian - 2440587.5) * 86400.0
-
-    double dfSeconds = double( milliseconds ) / 1000;
-    double dfUnix = 0;
-    if(julianday != 0)
-        dfUnix = ( double( julianday ) - 2440587.5 ) * 86400.0;
-    time_t fullSeconds = static_cast<time_t>( dfUnix + dfSeconds );
-    return addValue( code, CADVariant( fullSeconds ) );
+    return addValue( code, CADVariant( julianday, milliseconds ) );
 }
 
 int CADHeader::getGroupCode( short code )
