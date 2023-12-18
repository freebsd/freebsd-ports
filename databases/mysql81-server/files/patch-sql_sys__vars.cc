--- sql/sys_vars.cc.orig	2023-06-21 07:52:10 UTC
+++ sql/sys_vars.cc
@@ -2045,7 +2045,7 @@ static Sys_var_ulong Sys_connect_timeout(
     "The number of seconds the mysqld server is waiting for a connect "
     "packet before responding with 'Bad handshake'",
     GLOBAL_VAR(connect_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(2, LONG_TIMEOUT), DEFAULT(CONNECT_TIMEOUT), BLOCK_SIZE(1));
+    VALID_RANGE(2, INT_MAX32 / 1000), DEFAULT(CONNECT_TIMEOUT), BLOCK_SIZE(1));
 
 static Sys_var_ulong Sys_information_schema_stats_expiry(
     "information_schema_stats_expiry",
@@ -3201,7 +3201,7 @@ static Sys_var_ulong Sys_net_read_timeout(
     "Number of seconds to wait for more data from a connection before "
     "aborting the read",
     SESSION_VAR(net_read_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_READ_TIMEOUT), BLOCK_SIZE(1),
+    VALID_RANGE(1, INT_MAX32 / 1000), DEFAULT(NET_READ_TIMEOUT), BLOCK_SIZE(1),
     NO_MUTEX_GUARD, NOT_IN_BINLOG, ON_CHECK(nullptr),
     ON_UPDATE(fix_net_read_timeout));
 
@@ -3222,7 +3222,7 @@ static Sys_var_ulong Sys_net_write_timeout(
     "Number of seconds to wait for a block to be written to a connection "
     "before aborting the write",
     SESSION_VAR(net_write_timeout), CMD_LINE(REQUIRED_ARG),
-    VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_WRITE_TIMEOUT), BLOCK_SIZE(1),
+    VALID_RANGE(1, INT_MAX32 / 1000), DEFAULT(NET_WRITE_TIMEOUT), BLOCK_SIZE(1),
     NO_MUTEX_GUARD, NOT_IN_BINLOG, ON_CHECK(nullptr),
     ON_UPDATE(fix_net_write_timeout));
 
