This is a workaround for this bug:
https://github.com/philsquared/Catch/blob/master/docs/limitations.md#clangg----skipping-leaf-sections-after-an-exception
--- json_container/tests/json_container_test.cc.orig	2017-08-25 18:32:21 UTC
+++ json_container/tests/json_container_test.cc
@@ -80,7 +80,7 @@ TEST_CASE("JsonContainer::JsonContainer 
             json_value = "null";
         }
 
-        REQUIRE_NOTHROW(JsonContainer { json_value });
+        REQUIRE_NOTHROW(if (json_value != "") { JsonContainer { json_value };});
     }
 
     SECTION("it should throw a data_parse_error in case of empty string") {
