--- syslog.ml.orig	2006-02-23 06:34:35 UTC
+++ syslog.ml
@@ -142,18 +142,18 @@ let syslog ?fac lev str =
     let realmsg = ref (Buffer.contents msg) in
       if String.length !realmsg > 1024 then begin
 	realmsg := String.sub !realmsg 0 1024;
-	String.blit "<truncated>\000" 0 !realmsg 1012 12
+	String.blit "<truncated>\000" 0 (Bytes.unsafe_of_string !realmsg) 1012 12
       end;
       begin try
-	ignore (Unix.write loginfo.fd !realmsg 0 (String.length !realmsg))
+	ignore (Unix.write_substring loginfo.fd !realmsg 0 (String.length !realmsg))
       with 
 	| Unix.Unix_error(_,_,_) ->
 	if List.mem `LOG_CONS loginfo.flags then
 	  log_console !realmsg
       end;
       if List.mem `LOG_PERROR loginfo.flags then begin
-	ignore (Unix.write Unix.stderr !realmsg 0 (String.length !realmsg));
-	ignore (Unix.write Unix.stderr "\n" 0 1)
+	ignore (Unix.write_substring Unix.stderr !realmsg 0 (String.length !realmsg));
+	ignore (Unix.write_substring Unix.stderr "\n" 0 1)
       end
 
 let closelog () =
