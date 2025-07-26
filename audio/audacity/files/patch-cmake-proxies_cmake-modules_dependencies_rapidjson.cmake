--- cmake-proxies/cmake-modules/dependencies/rapidjson.cmake.orig	2025-06-10 12:52:05 UTC
+++ cmake-proxies/cmake-modules/dependencies/rapidjson.cmake
@@ -3,7 +3,7 @@ if(NOT ${_OPT}use_rapidjson STREQUAL "off")
 if(NOT ${_OPT}use_rapidjson STREQUAL "off")
    if(NOT TARGET rapidjson::rapidjson)
       if(TARGET rapidjson)
-         add_library( rapidjson::rapidjson ALIAS rapidjson )
+         add_library( rapidjson::rapidjson ALIAS RapidJSON )
       else()
          # At least on Arch RapidJSONConfig.cmake does not define a target at all
          # so we have to do it ourselves
