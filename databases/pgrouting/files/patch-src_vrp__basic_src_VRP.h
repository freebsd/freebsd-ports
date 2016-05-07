--- src/vrp_basic/src/VRP.h.orig	2016-04-19 16:40:04 UTC
+++ src/vrp_basic/src/VRP.h
@@ -70,7 +70,7 @@ typedef struct vrp_result_element
 
 
 #ifdef __cplusplus
-extern "C"
+extern "C" {
 #endif
 
 int find_vrp_solution(vrp_vehicles_t *vehicles, size_t vehicle_count, 
@@ -80,7 +80,7 @@ int find_vrp_solution(vrp_vehicles_t *ve
 					  vrp_result_element_t **result, size_t *result_count, char **err_msg);
 
 #ifdef __cplusplus
-extern "C"
+}
 #endif
 
 #endif
