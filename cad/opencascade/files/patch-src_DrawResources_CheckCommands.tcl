--- src/DrawResources/CheckCommands.tcl.orig	2017-08-30 13:28:11 UTC
+++ src/DrawResources/CheckCommands.tcl
@@ -1038,6 +1038,7 @@ help checkplatform {
     -windows : return 1 if current platform is 'Windows', overwise return 0
     -linux   : return 1 if current platform is 'Linux', overwise return 0
     -osx     : return 1 if current platform is 'MacOS X', overwise return 0
+    -freebsd : return 1 if current platform is 'FreeBSD', overwise return 0
 
   Only one option can be used at once.
   If no option is given, procedure will return the name of current platform.
@@ -1046,9 +1047,11 @@ proc checkplatform {args} {
     set check_for_windows false
     set check_for_linux false
     set check_for_macosx false
+    set check_for_freebsd false
 
     set options {{"-windows" check_for_windows 0}
                  {"-linux" check_for_linux 0}
+                 {"-freebsd" check_for_freebsd 0}
                  {"-osx" check_for_macosx 0}}
 
     _check_args ${args} ${options} "checkplatform"
@@ -1057,17 +1060,19 @@ proc checkplatform {args} {
         set current_platform Windows
     } elseif { $::tcl_platform(os) == "Linux" } {
         set current_platform Linux
+    } elseif { $::tcl_platform(os) == "FreeBSD" } {
+        set current_platform FreeBSD
     } elseif { $::tcl_platform(os) == "Darwin" } {
         set current_platform MacOS
     }
 
     # no args are given
-    if { !${check_for_windows} && !${check_for_linux} && !${check_for_macosx}} {
+    if { !${check_for_windows} && !${check_for_linux} && !${check_for_macosx} && !${check_for_freebsd}} {
         return ${current_platform}
     }
 
     # check usage of proc checkplatform
-    if { [expr [string is true ${check_for_windows}] + [string is true ${check_for_linux}] + [string is true ${check_for_macosx}] ] > 1} {
+    if { [expr [string is true ${check_for_windows}] + [string is true ${check_for_linux}] + [string is true ${check_for_macosx}] + [string is true ${check_for_freebsd}] ] > 1} {
         error "Error: wrong usage of command checkplatform, only single option can be used at once"
     }
 
@@ -1076,11 +1081,16 @@ proc checkplatform {args} {
         return 1
     }
 
-    # checking for Mac OS X platforms
+    # checking for Linux platforms
     if { ${check_for_linux} && ${current_platform} == "Linux" } {
         return 1
     }
 
+    # checking for FreeBSD platforms
+    if { ${check_for_freebsd} && ${current_platform} == "FreeBSD" } {
+        return 1
+    }
+
     # checking for Mac OS X platforms
     if { ${check_for_macosx} && ${current_platform} == "MacOS" } {
         return 1
