--- src/system/smlnj/installer/libinstall.sml.orig	Tue Jul 13 20:49:54 2004
+++ src/system/smlnj/installer/libinstall.sml	Thu Aug 12 01:23:08 2004
@@ -78,9 +78,40 @@
     fun mkdir "" = ()
       | mkdir d = if fexists d then () else (mkdir (P.dir d); F.mkDir d)
 
+    (* hack for cross-device moves *)
+    val move = if isUnix
+	then fn args as { old : string, new : string } =>
+		let val xdev_exnName = "SysErr\000"
+		    val xdev_exnMessage_substring = "xdev"
+		in F.rename args
+		   handle exn =>
+			if exnName exn = xdev_exnName
+			then if String.isSubstring xdev_exnMessage_substring
+						   (exnMessage exn)
+			     then if OS.Process.system
+					("mv '" ^ old ^ "' '" ^ new ^ "'")
+				     = OS.Process.success
+				  then print ("(* cross device mv of \"" ^ old
+						^ "\" to \"" ^ new
+						^ "\" done. *)\n")
+				  else fail ["move: mv " ^ old ^ " " ^ new
+						 ^ " failed.\n"]
+			      else ( print ("(* move: \""
+						^ xdev_exnMessage_substring
+						^ "\" not found in \""
+						^ (exnMessage exn)
+						^ "\". *)\n") ;
+				     raise exn )
+			else ( print ("(* move: \"" ^ xdev_exnName
+					^ "\" != \""
+					^ (exnName exn) ^ "\". *)\n") ;
+			       raise exn )
+		end
+	else F.rename
+
     (* move a stable library file to its final location *)
     fun movelib src dst () =
-	(mkdir (P.dir dst); F.rename { old = src, new = dst })
+	(mkdir (P.dir dst); move { old = src, new = dst })
 
     (* register a temporary anchor-value binding *)
     fun localanchor { anchor, path } =
@@ -325,7 +356,7 @@
 		 F.chDir treedir;
 		 if OS.Process.system buildcmd = OS.Process.success then
 		     if fexists targetheaploc then
-			 (F.rename { old = targetheaploc,
+			 (move { old = targetheaploc,
 				     new = finalheaploc };
 			  instcmd target;
 			  #set (CM.Anchor.anchor target) (SOME bindir))
