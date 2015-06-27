--- include/eredis.hrl.orig	2015-06-24 19:38:51 UTC
+++ include/eredis.hrl
@@ -18,11 +18,7 @@
 -type parser_state() :: status_continue | bulk_continue | multibulk_continue.
 
 %% Internal types
--ifdef(namespaced_types).
 -type eredis_queue() :: queue:queue().
--else.
--type eredis_queue() :: queue().
--endif.
 
 %% Internal parser state. Is returned from parse/2 and must be
 %% included on the next calls to parse/2.
