--- dmucs_db.cc.orig	2008-07-07 23:02:33.000000000 +0700
+++ dmucs_db.cc	2008-07-07 23:12:12.000000000 +0700
@@ -63,7 +63,7 @@
 void
 DmucsDb::assignCpuToClient(const unsigned int clientIp,
                            const DmucsDprop dprop,
-                           const unsigned int sock)
+                           const void *sock)
 {
     MutexMonitor m(&mutex_);
 
@@ -74,7 +74,7 @@
 
 
 void
-DmucsDb::releaseCpu(const unsigned int sock)
+DmucsDb::releaseCpu(const void *sock)
 {
     /* Get the dprop so that we can release the cpu back into the
        correct sub-db in the DmucsDb. */
@@ -146,7 +146,7 @@
 
 void
 DmucsDpropDb::assignCpuToClient(const unsigned int hostIp,
-                                const unsigned int sock)
+                                const void *sock)
 {
     struct in_addr t2;
     t2.s_addr = hostIp;
@@ -164,13 +164,13 @@
 
 
 void
-DmucsDpropDb::releaseCpu(const unsigned int sock)
+DmucsDpropDb::releaseCpu(const void *sock)
 {
-    DMUCS_DEBUG((stderr, "releaseCpu for socket 0x%x\n", sock));
+    DMUCS_DEBUG((stderr, "releaseCpu for socket %p\n", sock));
 
     dmucs_assigned_cpus_iter_t itr = assignedCpus_.find(sock);
     if (itr == assignedCpus_.end()) {
-	DMUCS_DEBUG((stderr, "No cpu found in assignedCpus for sock 0x%x\n",
+	DMUCS_DEBUG((stderr, "No cpu found in assignedCpus for sock %p\n",
 		     sock));
 	return;
     }
