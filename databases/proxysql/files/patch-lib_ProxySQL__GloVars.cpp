--- lib/ProxySQL_GloVars.cpp.orig	2025-11-05 18:21:29 UTC
+++ lib/ProxySQL_GloVars.cpp
@@ -334,7 +334,10 @@ void update_ulong_var_if_set(uint64_t& cur_val, ez::ez
 
 void update_ulong_var_if_set(uint64_t& cur_val, ez::ezOptionParser* opt, const char* cmd_opt) {
 	if (opt->isSet(cmd_opt)) {
-		opt->get(cmd_opt)->getULong(cur_val);
+		unsigned long new_val = cur_val;
+
+		opt->get(cmd_opt)->getULong(new_val);
+		cur_val = new_val;
 	}
 }
 
