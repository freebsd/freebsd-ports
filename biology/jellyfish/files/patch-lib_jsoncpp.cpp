--- lib/jsoncpp.cpp.orig	2018-04-16 12:46:09 UTC
+++ lib/jsoncpp.cpp
@@ -2300,7 +2300,7 @@ Value::asInt64() const
       JSON_ASSERT_MESSAGE( value_.uint_ <= UInt64(maxInt64), "unsigned integer out of Int64 range" );
       return value_.uint_;
    case realValue:
-      JSON_ASSERT_MESSAGE( value_.real_ >= minInt64  &&  value_.real_ <= maxInt64, "Real out of Int64 range" );
+      JSON_ASSERT_MESSAGE( value_.real_ >= minInt64  &&  value_.real_ < static_cast<double>(maxInt64), "Real out of Int64 range" );
       return Int( value_.real_ );
    case booleanValue:
       return value_.bool_ ? 1 : 0;
@@ -2328,7 +2328,7 @@ Value::asUInt64() const
    case uintValue:
       return value_.uint_;
    case realValue:
-      JSON_ASSERT_MESSAGE( value_.real_ >= 0  &&  value_.real_ <= maxUInt64,  "Real out of UInt64 range" );
+      JSON_ASSERT_MESSAGE( value_.real_ >= 0  &&  value_.real_ < static_cast<double>(maxUInt64),  "Real out of UInt64 range" );
       return UInt( value_.real_ );
    case booleanValue:
       return value_.bool_ ? 1 : 0;
