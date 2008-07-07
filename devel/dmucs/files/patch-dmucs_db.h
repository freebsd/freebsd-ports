--- dmucs_db.h.orig	2008-07-07 23:02:38.000000000 +0700
+++ dmucs_db.h	2008-07-07 23:10:18.000000000 +0700
@@ -56,7 +56,7 @@
     /* This is a mapping from sock address to host ip address -- the socket
        of the connection from the "gethost" application to the dmucs server,
        and the hostip of the cpu assigned to the "gethost" application. */
-    typedef std::map<const unsigned int, const unsigned int>
+    typedef std::map<const unsigned long, const unsigned int>
     		dmucs_assigned_cpus_t;
     typedef dmucs_assigned_cpus_t::iterator dmucs_assigned_cpus_iter_t;
 
@@ -98,12 +98,12 @@
     bool 	haveHost(const struct in_addr &ipAddr);
     unsigned int getBestAvailCpu();
     void	assignCpuToClient(const unsigned int clientIp,
-				  const unsigned int cpuIp);
+				  const unsigned long cpuIp);
     void 	moveCpus(DmucsHost *host, int oldTier, int newTier);
     int 	delCpusFromTier(int tier, unsigned int ipAddr);
 
     void 	addNewHost(DmucsHost *host);
-    void	releaseCpu(const unsigned int sock);
+    void	releaseCpu(const unsigned long sock);
 
     void 	addToHostSet(dmucs_host_set_t *theSet, DmucsHost *host);
     void 	delFromHostSet(dmucs_host_set_t *theSet, DmucsHost *host);
@@ -154,7 +154,7 @@
     /* A mapping of socket to distinguishing property -- so that when a
        host is released and all we have is the socket information, we can
        figure out which DpropDb to put the host back into. */
-    typedef std::map<int, DmucsDprop> dmucs_sock_dprop_db_t;
+    typedef std::map<long, DmucsDprop> dmucs_sock_dprop_db_t;
     typedef dmucs_sock_dprop_db_t::iterator dmucs_sock_dprop_db_iter_t;
 
     dmucs_sock_dprop_db_t sock2DpropDb_;
@@ -197,7 +197,7 @@
     }
     void assignCpuToClient(const unsigned int clientIp,
                            const DmucsDprop dprop,
-                           const unsigned int sock);
+                           const unsigned long sock);
     void moveCpus(DmucsHost *host, int oldTier, int newTier) {
 	MutexMonitor m(&mutex_);
 	// Assume the DmucsDpropDb is definitely there.
@@ -261,7 +261,7 @@
 	return dbDb_.find(host->getDprop())->second.delFromUnavailDb(host);
     }
 
-    void releaseCpu(const unsigned int sock);
+    void releaseCpu(const unsigned long sock);
 
     void handleSilentHosts() {
 	MutexMonitor m(&mutex_);
