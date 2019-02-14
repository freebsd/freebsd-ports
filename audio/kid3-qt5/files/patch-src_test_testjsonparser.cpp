The QDateTime object used to create the test value contains milliseconds, so
the test fails because the returned value did not match the expected value.

--- src/test/testjsonparser.cpp.orig	2018-12-21 05:40:14 UTC
+++ src/test/testjsonparser.cpp
@@ -103,7 +103,7 @@ void TestJsonParser::serializeAndDeserializeTypes()
 
   QString str = JsonParser::serialize(map);
   QCOMPARE(str, QString(QLatin1String(
-             "{\"val00\": \"2011-08-18T14:02:07\", \"val01\": -7654321, "
+             "{\"val00\": \"2011-08-18T14:02:07.000\", \"val01\": -7654321, "
              "\"val02\": 1234567890123456789, "
              "\"val03\": false, \"val04\": true, \"val05\": null, \"val06\": "
              "\"String with \\\"'\\\\{}[]\", \"val07\": 3.141592653, "
