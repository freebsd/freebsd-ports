Send redundancy configuration to storage node redundant manager on 
synchronization after the node restart.

--- deps/leo_manager/src/leo_manager_cluster_monitor.erl.orig	2014-05-09 12:36:43.000000000 +0300
+++ deps/leo_manager/src/leo_manager_cluster_monitor.erl	2014-07-22 20:31:37.000000000 +0300
@@ -466,6 +466,7 @@
     %% synchronize member and ring
     catch leo_manager_api:synchronize(?CHECKSUM_MEMBER, Node),
     catch leo_manager_api:synchronize(?CHECKSUM_RING,   Node),
+    catch leo_manager_api:recover(?RECOVER_BY_RING, Node, true),
     ok;
 
 register_fun_2({ok, [#node_state{state = ?STATE_DETACHED}|_]}, #registration{node = Node,
