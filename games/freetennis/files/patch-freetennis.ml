--- freetennis.ml.orig	2005-11-21 21:20:33 UTC
+++ freetennis.ml
@@ -764,13 +764,9 @@ module StringMap = Map.Make (String)
 module StringMap = Map.Make (String)
 
 (* "bool IntMap.t" is a map  int -> bool *)
-module IntMap = Map.Make (struct
-			      type t = int
-			      let compare = compare
-			  end )
+module IntMap = Map.Make(Int)
 
 
-
 type leftOrRight = Right | Left
 
 let oppositeDir d = match d with Right -> Left | Left -> Right
@@ -2317,7 +2313,7 @@ let setAnim ~animName  ~o ~restartIfSameAnimation = 
 let setAnim ~animName  ~o ~restartIfSameAnimation = 
 
     let an , fr, st = 
-	if 0 != (compare animName o.o3d_curAnimName) then
+	if 0 != (String.compare animName o.o3d_curAnimName) then
 	    animName, 0, Animated 0.0
 	else
 	    if restartIfSameAnimation then
@@ -6641,6 +6637,7 @@ let _ = 
 	else if  !realisticPar &&  !newbiePar then
 	    ArgumentError ("You cannot speficy both -realistic and -newbie. These are mutually exclusive flags.")
 	else
+	    let compare = String.compare in
 	    let translateName n =
 		if 0 = compare  n  "mats" then Some Mats 
 		else if 0 = compare n  "pete" then Some Pete
@@ -6714,7 +6711,7 @@ let _ = 
 			  Server ( (soc, clientSocket), Unix.in_channel_of_descr clientSocket, Unix.out_channel_of_descr clientSocket)
 		      )
 
-		  else  if 0 != compare !client  ""  then
+		  else  if 0 != String.compare !client  ""  then
 		      let soc = Unix.socket Unix.PF_INET Unix.SOCK_STREAM 0 in
 		      let inet_a = Unix.inet_addr_of_string !client in
 		      print_endline "Connecting to server...";
@@ -6913,7 +6910,7 @@ let _ = 
 			  assert (not (mem "CVS" l));
     			  List.map (fun x -> dir ^ "/" ^ x) l in
 		      let notCVS x =
-			  0 != (compare x  "CVS") in
+			  0 != (String.compare x  "CVS") in
     		      addPath (filter notCVS  (Array.to_list (Sys.readdir dir))) in
     		  accumulate ~list:allFilesInDir ~f:makeTextureOfFile ~state:(handleOfTexture, nextFreeTextureIndex)
 
@@ -7226,8 +7223,8 @@ let _ = 
 				      let filesWithIndices =
 					  let files =
 					      let notCVS x =
-						  0 != (compare x "CVS") in
-					      List.sort compare (filter notCVS (Array.to_list  (Sys.readdir d))) in
+						  0 != (String.compare x "CVS") in
+					      List.sort String.compare (filter notCVS (Array.to_list  (Sys.readdir d))) in
 					  if  List.length files != Array.length times then
 					      (print_endline (d);
 					       assert(false))
