--- lib/cadheader.cpp.orig	2016-08-24 13:25:41 UTC
+++ lib/cadheader.cpp
@@ -243,6 +243,28 @@ CADVariant::CADVariant( const char * val )
     dateTimeVal = 0;
 }
 
+CADVariant::CADVariant( long val )
+{
+    type        = DataType ::DECIMAL;
+    decimalVal  = val;
+    stringVal   = to_string( decimalVal );
+    xVal        = 0;
+    yVal        = 0;
+    zVal        = 0;
+    dateTimeVal = 0;
+}
+
+CADVariant::CADVariant( long long val )
+{
+    type        = DataType ::DECIMAL;
+    decimalVal  = val;
+    stringVal   = to_string( decimalVal );
+    xVal        = 0;
+    yVal        = 0;
+    zVal        = 0;
+    dateTimeVal = 0;
+}
+
 CADVariant::CADVariant( int val )
 {
     type        = DataType::DECIMAL;
@@ -303,7 +325,7 @@ CADVariant::CADVariant( const string& val )
     dateTimeVal = 0;
 }
 
-CADVariant::CADVariant( time_t val )
+CADVariant::CADVariant( time_t val, bool bIsTime )
 {
     type        = DataType::DATETIME;
     dateTimeVal = val;
