
$FreeBSD$

--- lib/typer/src/typer_info.erl.orig
+++ lib/typer/src/typer_info.erl
@@ -123,6 +123,5 @@
 	     dialyzerObj=NewDialyzerObj}.
 
 get_dialyzer_plt() ->
-  DialyzerDir = code:lib_dir(dialyzer),
-  Dialyzer_Init_Plt = filename:join([DialyzerDir,"plt","dialyzer_init_plt"]),
+  Dialyzer_Init_Plt = filename:join([os:getenv ("HOME"), ".dialyzer_init_plt"]),
   dialyzer_plt:from_file(typer_plt, Dialyzer_Init_Plt).
