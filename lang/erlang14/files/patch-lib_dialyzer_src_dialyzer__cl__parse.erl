
$FreeBSD$

--- lib/dialyzer/src/dialyzer_cl_parse.erl.orig
+++ lib/dialyzer/src/dialyzer_cl_parse.erl
@@ -155,8 +155,7 @@
   put(dialyzer_options_from, byte_code),
   put(dialyzer_options_libs, ?DEFAULT_LIBS),
 
-  InitPltDir = filename:join([code:lib_dir(dialyzer),
-			      "plt","dialyzer_init_plt"]),
+  InitPltDir = filename:join([os:getenv ("HOME"), ".dialyzer_init_plt"]),
   put(dialyzer_init_plt, InitPltDir),
   put(dialyzer_warnings, []).
 
