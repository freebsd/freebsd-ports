--- ros/src/OS/OS.tcl.orig	Mon Dec  6 14:30:50 2004
+++ ros/src/OS/OS.tcl	Tue Aug  1 08:39:43 2006
@@ -1163,7 +1163,11 @@
 	    SunOS {
 		set litm  [list sun wsn]
 	    }
-	    
+
+	    FreeBSD {
+		set litm  [list bsd wfb]
+	    }
+
 	    Linux {
 		set litm  [list lin wln]
 	    }
@@ -2308,6 +2312,7 @@
     set do_nothing_here [list IRIX AIX HP-UX] ;# ne pas toucher aux .lnk de pop ici
     ;#puts "plat $plat"
     if { "$plat" == "SunOS"} { set OsName "solaris" }
+    if { "$plat" == "FreeBSD"} { set OsName "freebsd" }
     if { "$plat" == "Linux"} { set OsName "linux" }
     if { "$plat" == "WindowsNT"} {set OsName "win32"}
     ;#puts [OS:procs $module $plat]
@@ -2480,7 +2485,15 @@
 	    }
 	    if [regexp -- {/cc} $compiler all find] {
 		set compstring "\${CCOMP} "
-	    } 
+	    }
+	}
+        if {$plat == "FreeBSD"} {
+	    if [regexp -- {/CC} $compiler all find] {
+		set compstring "\${CXXCOMP} "
+	    }
+	    if [regexp -- {/cc} $compiler all find] {
+		set compstring "\${CCOMP} "
+	    }
 	}
 	if {$plat == "Linux"} {
 	    if [regexp -- {/gcc} $compiler all find] {
@@ -2568,6 +2581,11 @@
 		set compstring "\${CXXCOMP} "
 	    }
 	}
+        if {$plat == "FreeBSD"} {
+	    if [regexp -- {/CC} $compiler all find] {
+		set compstring "\${CXXCOMP} "
+	    }
+	}
 	if {$plat == "Linux"} {
 	    if [regexp -- {/g} $compiler all find] {
 		set compstring "\${CXXCOMP} "
@@ -2643,6 +2661,11 @@
 		set compstring "\${CXXCOMP} "
 	    }
 	}
+        if {$plat == "FreeBSD"} {
+	    if [regexp -- {/CC} $compiler all find] {
+		set compstring "\${CXXCOMP} "
+	    }
+	}
 	if {$plat == "Linux"} {
 	    if [regexp -- {/g} $compiler all find] {
 		set compstring "\${CXXCOMP} "
@@ -3166,6 +3189,8 @@
     ;#
     set A(runtime,Linux) lin
     set A(wokadm,Linux)  wln ;# au lieu de LIN
+    set A(runtime,FreeBSD) bsd
+    set A(wokadm,FreeBSD)  wfb ;# au lieu de FREEBSD
     set A(runtime,SunOS) sun
     set A(wokadm,SunOS)  wsn ;# au lieu de SUN
     set A(runtime,IRIX)  sil
@@ -3539,10 +3564,12 @@
 ;#
 ;# ce qui suit veut dire que:
 ;# on substitue /adv_11/KAS/C30/ref par TOSUBSTITUTE ET /adv_11/KAS/C30/UpdateC31 par TOSUBSTITUTE etc..
-;# sur la plateforme correspondante.
+;# sur la plate-forme correspondante.
 ;#
     set TOTRIM(wokadm,WindowsNT) nothing,nothing
     set TOTRIM(wokadm,SunOS)     \
+	    /dn01/KAS/dev/roc,TOSUBSTITUTE,/adv_11/KAS/C30/UpdateC31,TOSUBSTITUTE,/adv_10/KAS/C30/UpdateC31,TOSUBSTITUTE
+    set TOTRIM(wokadm,FreeBSD)     \
 	    /dn01/KAS/dev/roc,TOSUBSTITUTE,/adv_11/KAS/C30/UpdateC31,TOSUBSTITUTE,/adv_10/KAS/C30/UpdateC31,TOSUBSTITUTE
     set TOTRIM(wokadm,IRIX)      \
 	    /dn01/KAS/dev/ros,TOSUBSTITUTE,/adv_11/KAS/C30/UpdateC31,TOSUBSTITUTE,/adv_10/KAS/C30/UpdateC31,TOSUBSTITUTE
