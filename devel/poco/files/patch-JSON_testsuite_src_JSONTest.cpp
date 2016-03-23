Workaround for base GCC on 9.3-i386:
src/JSONTest.cpp:235: error: integer constant is too large for 'long' type
--- JSON/testsuite/src/JSONTest.cpp.orig	2016-02-25 11:53:58 UTC
+++ JSON/testsuite/src/JSONTest.cpp
@@ -232,23 +232,23 @@ void JSONTest::testNumber64Property()
 	Var test = object.get("test");
 	assert(test.isInteger());
 	Poco::Int64 value = test;
-	assert(value == -5000000000000000);
+	assert(value == -5000000000000000LL);
 
 	DynamicStruct ds = object;
 	assert (!ds["test"].isEmpty());
 	assert (ds["test"].isNumeric());
 	assert (ds["test"].isInteger());
-	assert (ds["test"] == -5000000000000000);
+	assert (ds["test"] == -5000000000000000LL);
 	value = ds["test"];
-	assert(value == -5000000000000000);
+	assert(value == -5000000000000000LL);
 
 	const DynamicStruct& rds = object;
 	assert (!rds["test"].isEmpty());
 	assert (rds["test"].isNumeric());
 	assert (rds["test"].isInteger());
-	assert (rds["test"] == -5000000000000000);
+	assert (rds["test"] == -5000000000000000LL);
 	value = rds["test"];
-	assert(value == -5000000000000000);
+	assert(value == -5000000000000000LL);
 }
 
 
