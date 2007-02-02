
$FreeBSD$

--- lib/dialyzer/src/dialyzer_cl_parse.erl.orig
+++ lib/dialyzer/src/dialyzer_cl_parse.erl
@@ -159,7 +159,7 @@
   throw({dialyzer_cl_parse_error, Msg}).
 
 init() ->
-  InitPlt = filename:join([code:lib_dir(dialyzer), "plt","dialyzer_init_plt"]),
+  InitPlt = filename:join([os:getenv ("HOME"), "plt","dialyzer_init_plt"]),
   put(dialyzer_init_plt, InitPlt),
   put(dialyzer_only_check_init_plt, false),
   put(dialyzer_options_gui, true),
