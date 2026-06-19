--- cmake/ETLPlatform.cmake	2026-05-29 23:41:13.657983000 -0700
+++ cmake/ETLPlatform.cmake	2026-05-29 23:41:33.676839000 -0700
@@ -100,7 +100,7 @@
 		target_link_libraries(os_libraries INTERFACE m pthread)
 		set(LIB_SUFFIX ".mp.obsd.")
 	elseif(CMAKE_SYSTEM MATCHES "FreeBSD")
-		target_link_libraries(os_libraries INTERFACE m pthread)
+		target_link_libraries(os_libraries INTERFACE m pthread execinfo)
 		set(LIB_SUFFIX ".mp.fbsd.")
 	elseif(CMAKE_SYSTEM MATCHES "NetBSD")
 		target_link_libraries(os_libraries INTERFACE m pthread)
