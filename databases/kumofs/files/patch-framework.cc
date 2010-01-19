--- src/logic/manager/framework.cc.orig	2010-01-19 12:35:26.982220174 +0900
+++ src/logic/manager/framework.cc	2010-01-19 12:35:39.546813770 +0900
@@ -66,7 +66,7 @@
 
 void framework::new_node(address addr, role_type id, shared_node n)
 {
-	LOG_WARN("new node ",id," ",addr);
+	LOG_WARN("new node ",(uint16_t)id," ",addr);
 	if(id == ROLE_MANAGER) {
 		if(addr != share->partner()) {
 			TLOGPACK("eP",3,
