--- include/gpb.hrl.orig	2015-07-14 11:05:17 UTC
+++ include/gpb.hrl
@@ -39,7 +39,7 @@
 -define(gpb_rpc, rpc). %% odd definition is due to backwards compatibility
 -endif.
 
--record(?gpb_field, % NB: record name is (currently) `field' (not `gpb_field')!
+-record(field, % NB: record name is (currently) `field' (not `gpb_field')!
         {name               :: atom(),
          fnum               :: integer(),
          rnum               :: pos_integer(), %% field number in the record
