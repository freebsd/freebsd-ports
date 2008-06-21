--- src/njml.sml.orig	Fri Mar 30 23:39:14 2001
+++ src/njml.sml	Sun Jan 13 12:35:29 2008
@@ -44,8 +44,8 @@
 	  
       end
 
-    fun setPrintDepth n = (Compiler.Control.Print.printDepth := n div 2;
-			   Compiler.Control.Print.printLength := n)
+    fun setPrintDepth n = (Control.Print.printDepth := n div 2;
+			   Control.Print.printLength := n)
 
    (* Set the terminal to a state suitable for sml_tk. Disables INTR
     * s.t. we can use it to abort functions called from bindings, and 
@@ -60,11 +60,11 @@
 	if Posix.ProcEnv.isatty (Posix.FileSys.stdin) then
 	 let (* configure TTY driver to have ^\ generate sigQUIT *)
 	     val {iflag, oflag, cflag, lflag, cc, ispeed, ospeed} = 
-	                 fieldsOf (getattr Posix.FileSys.stdin)
+	                 fieldsOf (Posix.TTY.TC.getattr Posix.FileSys.stdin)
 	     val nuattr= termios {iflag=iflag, oflag=oflag, cflag=cflag, 
 				  lflag=lflag, ispeed=ispeed, ospeed=ospeed,
 				  cc=V.update(cc, [(V.quit, Char.chr 28)])}
-	 in  setattr(Posix.FileSys.stdin, TC.sanow, nuattr);
+	 in  Posix.TTY.TC.setattr(Posix.FileSys.stdin, TC.sanow, nuattr);
 	     (* install the top level continuation as QUIT signal handler *)
 	     setHandler(UnixSignals.sigQUIT, 
 			HANDLER (fn _ => (abort();
@@ -106,7 +106,7 @@
     fun exec (s,sl) = 
 	let
 	    val pr = Unix.execute (s,sl)
-	in  case (Unix.reap pr) of 
+	in  case Posix.Process.fromStatus (Unix.reap pr) of 
 	     Posix.Process.W_EXITED => true
 	   | _                      => false
 	end
