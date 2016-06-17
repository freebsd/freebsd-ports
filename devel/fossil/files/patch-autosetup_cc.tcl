--- autosetup/cc.tcl.orig	2016-06-14 11:10:39 UTC
+++ autosetup/cc.tcl
@@ -501,6 +501,8 @@ proc cctest {args} {
 	if {!$opts(-link)} {
 		set tmp conftest__.o
 		lappend cmdline -c
+	} else {
+		lappend cmdline {*}[get-define LDFLAGS]
 	}
 	lappend cmdline {*}$opts(-cflags) {*}[get-define cc-default-debug ""]
 
