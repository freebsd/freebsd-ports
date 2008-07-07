--- dmucs_msg.cc.orig	2008-07-07 23:02:45.000000000 +0700
+++ dmucs_msg.cc	2008-07-07 23:10:25.000000000 +0700
@@ -130,7 +130,7 @@
 
 	fprintf(stderr, "Giving out %s\n", resolved_name.c_str());
 
-	db->assignCpuToClient(cpuIpAddr, dprop_, (unsigned int) sock);
+	db->assignCpuToClient(cpuIpAddr, dprop_, (unsigned long) sock);
 #if 0
 	fprintf(stderr, "The databases are now:\n");
 	db->dump();
