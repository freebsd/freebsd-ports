--- mtasc/main.ml.orig	2008-08-31 11:14:17 UTC
+++ mtasc/main.ml
@@ -112,8 +112,8 @@ let report ?(do_exit=true) (msg,p) etype printer =
 	if do_exit then exit 1
 ;;
 try	
-	let usage = "Motion-Twin ActionScript2 Compiler 1.14 - (c)2004-2008 Motion-Twin\n Usage : mtasc.exe [options] <files...>\n Options :" in
-	let base_path = normalize_path (try Extc.executable_path() with _ -> ".") in
+	let usage = "Motion-Twin ActionScript2 Compiler 1.14 - (c)2004-2008 Motion-Twin\n Usage : mtasc [options] <files...>\n Options :" in
+	let base_path = normalize_path (try Extc.executable_path() ^ "/.." with _ -> "..") in
 	let files = ref [] in
 	let time = Sys.time() in
 	Plugin.class_path := [base_path;"";"/"];
@@ -132,8 +132,8 @@ try	
 		),": use precompiled mx package");
 	] @ !Plugin.options in
 	Arg.parse args_spec (fun file -> files := file :: !files) usage;
-	Plugin.class_path := (base_path ^ "std/") :: !Plugin.class_path;
-	if (match !GenSwf.version with Some x -> x >= 8 | None -> false) then Plugin.class_path := (base_path ^ "std8/") :: !Plugin.class_path;
+	Plugin.class_path := (base_path ^ "share/mtasc/std/") :: !Plugin.class_path;
+	if (match !GenSwf.version with Some x -> x >= 8 | None -> false) then Plugin.class_path := (base_path ^ "share/mtasc/std8/") :: !Plugin.class_path;
 	Hashtbl.remove Lexer.keywords "add";
 	Parser.warning := (fun msg pos -> report ~do_exit:false (msg,pos) "Warning" (fun msg -> msg));
 	if !files = [] then begin
