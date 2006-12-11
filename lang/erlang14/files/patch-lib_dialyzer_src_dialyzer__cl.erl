
$FreeBSD$

--- lib/dialyzer/src/dialyzer_cl.erl.orig
+++ lib/dialyzer/src/dialyzer_cl.erl
@@ -93,7 +93,7 @@
 check_if_installed() ->
   case filename:basename(code:lib_dir(dialyzer)) of
     "dialyzer" -> false;
-    "dialyzer-" ++ _Version -> true
+    "dialyzer-" ++ _Version -> false
   end.  
 
 create_init_plt(MD5, Libs, InitPlt, IncludeDirs) ->  
