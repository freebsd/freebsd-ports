--- enforcer/src/daemon/time_leap_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/daemon/time_leap_cmd.h
@@ -29,6 +29,6 @@
 #ifndef _TIME_LEAP_CMD_H_
 #define _TIME_LEAP_CMD_H_
 
-struct cmd_func_block time_leap_funcblock;
+extern struct cmd_func_block time_leap_funcblock;
 
 #endif /* _TIME_LEAP_CMD_H_ */
