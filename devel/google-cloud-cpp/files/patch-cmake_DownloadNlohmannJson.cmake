--- cmake/DownloadNlohmannJson.cmake.orig	2019-07-11 02:46:50 UTC
+++ cmake/DownloadNlohmannJson.cmake
@@ -37,6 +37,10 @@ function (_download_json_hpp)
             execute_process(COMMAND "${CMAKE_COMMAND}" -E sleep
                                     "${sleep_seconds}")
         endif ()
+        if (EXISTS "${DEST}/json.hpp")
+            set(download_error_code 0)
+            break()
+        endif ()
         file(DOWNLOAD "${JSON_URL}" "${DEST}/json.hpp" STATUS download_status)
         list(GET download_status 0 download_error_code)
         if (download_error_code EQUAL 0)
