--- sql/sys_vars.cc.orig	2017-04-30 11:09:31 UTC
+++ sql/sys_vars.cc
@@ -826,7 +826,7 @@ static Sys_var_ulong Sys_interactive_tim
        "connection before closing it",
        SESSION_VAR(net_interactive_timeout),
        CMD_LINE(REQUIRED_ARG),
-       VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
+       VALID_RANGE(1, INT_MAX32/1000), DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
 
 static Sys_var_ulonglong Sys_join_buffer_size(
        "join_buffer_size",
@@ -1356,7 +1356,7 @@ static Sys_var_ulong Sys_net_read_timeou
        "Number of seconds to wait for more data from a connection before "
        "aborting the read",
        SESSION_VAR(net_read_timeout), CMD_LINE(REQUIRED_ARG),
-       VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_READ_TIMEOUT), BLOCK_SIZE(1),
+       VALID_RANGE(1, INT_MAX32/1000), DEFAULT(NET_READ_TIMEOUT), BLOCK_SIZE(1),
        NO_MUTEX_GUARD, NOT_IN_BINLOG, ON_CHECK(0),
        ON_UPDATE(fix_net_read_timeout));
 
@@ -1371,7 +1371,7 @@ static Sys_var_ulong Sys_net_write_timeo
        "Number of seconds to wait for a block to be written to a connection "
        "before aborting the write",
        SESSION_VAR(net_write_timeout), CMD_LINE(REQUIRED_ARG),
-       VALID_RANGE(1, LONG_TIMEOUT), DEFAULT(NET_WRITE_TIMEOUT), BLOCK_SIZE(1),
+       VALID_RANGE(1, INT_MAX32/1000), DEFAULT(NET_WRITE_TIMEOUT), BLOCK_SIZE(1),
        NO_MUTEX_GUARD, NOT_IN_BINLOG, ON_CHECK(0),
        ON_UPDATE(fix_net_write_timeout));
 
@@ -2480,7 +2480,7 @@ static Sys_var_ulong Sys_net_wait_timeou
        "The number of seconds the server waits for activity on a "
        "connection before closing it",
        SESSION_VAR(net_wait_timeout), CMD_LINE(REQUIRED_ARG),
-       VALID_RANGE(1, IF_WIN(INT_MAX32/1000, LONG_TIMEOUT)),
+       VALID_RANGE(1, INT_MAX32/1000),
        DEFAULT(NET_WAIT_TIMEOUT), BLOCK_SIZE(1));
 
 /** propagates changes to the relevant flag of @@optimizer_switch */
