--- installer/unix.tcl.orig	Wed Jun 13 09:20:29 2001
+++ installer/unix.tcl	Sat Jul 26 18:50:45 2003
@@ -16,7 +16,7 @@
     package require support
     package require -exact unixfile 1.18.[info tclversion]
 #
-    global Type types Lib Bin CC LD Version Patchlevel Wish types cflags\
+    global Type types Lib Bin CC LD Version Patchlevel WishCmd types cflags\
       libs share SCflag GCC SLDflag CFlags TIDir v7 SED go NoGUI Xtn
 #
     set types {AIX Alpha BSDI FreeBSD HP-UX IRIX Linux OSF1 {SunOS 4} {SunOS 5} UNIX_SV}
@@ -81,7 +81,7 @@
 #
 # Wish
 #
-    makeEntry $w wish {Tcl/Tk Interpreter} Wish [incr i] getWish
+    makeEntry $w wish {Tcl/Tk Interpreter} WishCmd [incr i] getWish
 #
 # Info
 #
@@ -153,12 +153,12 @@
 }
 #
 proc getWish {} {
-    global Wish
-    switch {} $Wish {set Wish [findWish]}
+    global WishCmd
+    switch {} $WishCmd {set WishCmd [findWish]}
 }
 #
 proc getBin {} {
-    global Bin env Lib Wish
+    global Bin env Lib WishCmd
     switch {} $Bin {} default return
     foreach x [split $env(PATH) :] {
 	set z [file join $x zircon]
@@ -167,7 +167,7 @@
 	    set Bin $x
 	    if {![catch {open $z r} fd]} {
 		gets $fd wish
-		set Wish [string range $wish 2 end]
+		set WishCmd [string range $wish 2 end]
 		gets $fd lib
 		close $fd
 		set Lib [lindex $lib 2]	
@@ -181,7 +181,7 @@
 proc getCC {} {
     global CC GCC SCflag CFlags Type SLDflag share scflags
     switch {} $CC {} default return
-    set CFlags -O
+    set CFlags {-O -I%%TCL_INCLUDE%%}
     catch {set CFlags $cflags($Type)}
     switch BSDI $Type {
 	set CC gcc2
@@ -220,7 +220,7 @@
 proc findWish {} {
     global env
     foreach x [split $env(PATH) :] {
-	foreach y {wish8.3 wish8.2 wish8.1 wish8.0 wish4.2 wish4.1 wish wishx} {
+	foreach y {%%WISH%%} {
 	    if {[file exists [set f [file join $x $y]]]} {
 		return $f
 	    }
