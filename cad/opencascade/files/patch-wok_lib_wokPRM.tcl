--- wok/lib/wokPRM.tcl.orig	Fri Sep 21 10:08:40 2001
+++ wok/lib/wokPRM.tcl	Thu Aug 10 16:29:46 2006
@@ -188,7 +188,7 @@
     tixForm $IWOK_GLOBALS(PRM,Modify,wrkst,but,all) -top 2
     
     set prev {} ; set curr {} ;set curwrkst [wokprofile -s]
-    foreach x [list sun sil ao1 hp wnt lin] {
+    foreach x [list sun bsd sil ao1 hp wnt lin] {
 	set curr [string tolower ${wrkst}.${x}]
 	
 	checkbutton $curr -text $x -variable IWOK_GLOBALS(PRM,Modify,wrkst,$x) -command wokPRM:wrkst
