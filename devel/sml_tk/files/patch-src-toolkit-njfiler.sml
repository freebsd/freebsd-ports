--- ./src/toolkit/njfiler.sml.orig	Fri Mar 30 23:39:40 2001
+++ src/toolkit/njfiler.sml	Sun Jan 13 11:03:51 2008
@@ -335,11 +335,12 @@
 				handle NoAcc => false) then
 				if (!SHOW_HIDDEN orelse
 				    not(hd(explode new) = #".")) then
-				    new :: read (OS.FileSys.readDir dirstream)
-				else read (OS.FileSys.readDir dirstream)
-			    else read (OS.FileSys.readDir dirstream)
+				    new :: read (valOf (OS.FileSys.readDir
+				    			dirstream))
+				else read (valOf (OS.FileSys.readDir dirstream))
+			    else read (valOf (OS.FileSys.readDir dirstream))
 		    in
-			(sort (read (OS.FileSys.readDir dirstream))
+			(sort (read (valOf (OS.FileSys.readDir dirstream)))
 			      (fn x => fn y => String.<(x, y)) before
 			 OS.FileSys.closeDir dirstream)
 		    end
@@ -618,7 +619,7 @@
 		    if (OS.FileSys.isDir(OS.Path.concat(!CURRENT_DIRECTORY,
 							new))
 			handle NoAcc => false) then
-			read (OS.FileSys.readDir dirstream)
+			read (valOf (OS.FileSys.readDir dirstream))
 		    else
 			if (!SHOW_HIDDEN orelse
 			    not(hd(explode new) = #".")) then
@@ -628,10 +629,10 @@
 			    in
 				if isSome dtp then
 				    (new, valOf dtp) ::
-				    read (OS.FileSys.readDir dirstream)
-				else read (OS.FileSys.readDir dirstream)
+				    read (valOf (OS.FileSys.readDir dirstream))
+				else read (valOf (OS.FileSys.readDir dirstream))
 			    end
-			else read (OS.FileSys.readDir dirstream)
+			else read (valOf (OS.FileSys.readDir dirstream))
 
 		fun type_ord e1 e2 ((ft : Filetype) :: fts) =
 		    if (not(e1 = "") andalso
@@ -659,7 +660,7 @@
 		    else if !SORT_NAMES then String.<(#1 e1, #1 e2)
 			 else true
 	    in
-		sort (read (OS.FileSys.readDir dirstream)) ord before
+		sort (read (valOf (OS.FileSys.readDir dirstream))) ord before
 		OS.FileSys.closeDir dirstream
 	    end
 
@@ -755,8 +756,8 @@
 					      !CURRENT_DIRECTORY
 					  else
 					      OS.Path.mkRelative
-					        (!CURRENT_DIRECTORY,
-						 root_dir()),
+					        {path = !CURRENT_DIRECTORY,
+						 relativeTo = root_dir()},
 					  file = nm}) ev (fn () => ())
 				else ()
 			    end
@@ -770,8 +771,8 @@
 					     !CURRENT_DIRECTORY
 					 else
 					     OS.Path.mkRelative
-					       (!CURRENT_DIRECTORY,
-						root_dir()),
+					       {path = !CURRENT_DIRECTORY,
+						relativeTo = root_dir()},
 				       file = #1 f}
 				else
 				    addConf file_statusID
