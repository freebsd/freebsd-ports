--- plugins_src/import_export/wpc_lwo.erl.orig	2015-08-06 10:38:19 UTC
+++ plugins_src/import_export/wpc_lwo.erl
@@ -13,7 +13,7 @@
 
 -module(wpc_lwo).
 -export([init/0, menu/2, command/2, export/1]).
--include_lib("wings/e3d/e3d.hrl").
+-include_lib("e3d.hrl").
 
 init() ->
     true.
