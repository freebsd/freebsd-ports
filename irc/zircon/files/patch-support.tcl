--- installer/support.tcl.orig	Wed Feb  2 11:09:16 2000
+++ installer/support.tcl	Sat Jul 26 18:54:54 2003
@@ -45,7 +45,7 @@
 	zinfo Done!!
 	if {[catch {open install.in w} fd]} {
 	} {
-	    foreach x {Type Lib Bin CC SCflag SLDflag CFlags Wish TIDir} {
+	    foreach x {Type Lib Bin CC SCflag SLDflag CFlags IWish TIDir} {
 		puts $fd "set $x {[uplevel #0 set $x]}"
 	    }
 	    close $fd
@@ -110,7 +110,7 @@
 }
 #
 proc doGlobals {argv} {
-    global Type types Lib Bin CC LD Version Patchlevel Wish types cflags\
+    global Type types Lib Bin CC LD Version Patchlevel IWish types cflags\
       libs share SCflag GCC SLDflag CFlags TIDir Prefix ExecPrefix SED go \
       pseudo
 #
@@ -124,7 +124,7 @@
     set SCflag {}
     set SLDflag {}
     set CFlags {}
-    set Wish {}
+    set IWish {}
     set TIDir {}
     set go 0
     set SED 0
@@ -144,7 +144,7 @@
 	-p {set pseudo $v}
 	-s {set SCflag $v}
 	-t {set Type $v }
-	-w {set Wish $v}
+	-w {set IWish $v}
 	-z {set SLDflag $v }
 	}
 	set argv [lrange $argv 2 end]
@@ -273,7 +273,7 @@
 #
 proc makeBinary {} {
     zinfo "Making zircon..."
-    global Bin Lib Version Patchlevel Wish Xtn
+    global Bin Lib Version Patchlevel IWish Xtn
     if {![file exists [pWrap [set Bin [fixPath $Bin]]]]} {
 	if {[catch {dirmake [pWrap $Bin]} msg]} {
 	    fail "Cannot create directory \"$Bin\" - $msg"
@@ -298,7 +298,7 @@
 	}
 	return 0
     }
-    puts $fd "#!$Wish
+    puts $fd "#!$IWish
 set zircon(lib) [whereLib]
 #
 proc zVersion {} {
