
$FreeBSD$

--- lib/kernel/src/application_controller.erl.orig
+++ lib/kernel/src/application_controller.erl
@@ -1398,7 +1398,7 @@
     FName = atom_to_list(Name) ++ ".app",
     case code:where_is_file(FName) of
 	non_existing ->
-	    {error, {file:format_error({error,enoent}), FName}};
+	    {error, {file:format_error(enoent), FName}};
 	FullName ->
 	    case file:consult(FullName) of
 		{ok, [Application]} ->
