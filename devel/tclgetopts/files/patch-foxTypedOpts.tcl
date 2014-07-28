--- foxTypedOpts.tcl	Sat Feb 19 19:46:50 1994
+++ foxTypedOpts.tcl	Thu Mar 18 16:15:13 1999
@@ -80,9 +80,8 @@
 # typedopts several times with different <arg-list>s without losing the
 # information from previous calls.
 #
-# if typedopts can't parse its options for any reason, it will print an
-# error message to stderr and return a -1 without modifying any other
-# variables.
+# if typedopts can't parse its options for any reason, it return an
+# error message without modifying any other variables.
 #
 # EXAMPLE:
 #
@@ -157,8 +156,7 @@
 #   Initial revision
 #
 
-proc typedopts { args } {
-
+namespace eval foxOpts {
   proc abbr { s1 s2 } {
     if { [ set len [ string length $s1 ]] } then {
       if { ! [ string compare $s1 [ string range $s2 0 [ expr $len - 1 ]]] } then {
@@ -298,8 +296,7 @@
         return 1
       }
       default {
-        puts stderr "Eek!  Option type <$otype> not supported yet!"
-        set var "isn't a supported type."
+        set var "<$otype> isn't a supported type."
         return 0
       }
     }
@@ -320,32 +317,28 @@
       "floats" -
       "strings" {
         if { [ llength $optlist ] } then {
-          puts stderr "typedopts:  Type $type doesn't take arguments"
-          return ""
+          return -code error "typedopts:  Type $type doesn't take arguments"
         }
         return [ string index $type 0 ]
       }
       "one-of" {
         if { ! [ llength $optlist ] } then {
-          puts stderr "typedopts:  No arguments given to type $type"
-          return ""
+          return -code error "typedopts:  No arguments given to type $type"
         }
         return [ concat [ string index $type 0 ] $optlist ]
       }
       "list-of" -
       "multiple" {
         if { ! [ llength $optlist ] } then {
-          puts stderr "typedopts:  No arguments given to type $type"
-          return ""
+          return -code error "typedopts:  No arguments given to type $type"
         }
-        if { ! [ string length [ set subtype [ parseOption $optlist ]]] } then {
-          return ""
+        if {[catch {parseOption $optlist} subtype]} then {
+	  return -code error $subtype
         }
         return [ concat [ string index $type 0 ] $subtype ]
       }
       default {
-        puts stderr "typedopts:  Unknown option type $type"
-        return ""
+        return -code error "typedopts:  Unknown option type $type"
       }
     }
   }
@@ -354,6 +347,5 @@
 
   if { [ llength $args ] < 5 } then {
-    puts stderr "typedopts: bad number of arguments."
-    return -1
+    return -code error "typedopts: bad number of arguments."
   }
 
@@ -367,6 +359,5 @@
       }
       default {
-        puts stderr "typedopts: bad option \"$opt\": should be -noinitialize or --"
-        return -1
+        return -code error "typedopts: bad option \"$opt\": should be -noinitialize or --"
       }
     }
@@ -380,16 +375,15 @@
     if { [ string length $type ] } then {
       foreach arg $word {
         if { [ lsearch -exact $arg $allopts ] > -1 } then {
-          puts stderr "typedopts: option -$arg multiply declared."
-          return -1
+          return -code error "typedopts: option -$arg multiply declared."
         }
         lappend allopts $arg
         set opttype($arg) $type
       }
       set type ""
     } else {
-      if { ! [ string length [ set type [ parseOption $word ]]] } then {
-        return -1
+      if [catch {foxOpts::parseOption $word} type] then {
+	return -code error $type
       }
     }
   }
@@ -408,7 +402,7 @@
   while { [ llength $arglist ] } {
     switch -glob -- $arglist {
       -- {
-        shift arglist
+        foxOpts::shift arglist
         break
       }
       -* {
@@ -417,10 +411,10 @@
         break
       }
     }
-    set opt [ string range [ shift arglist ] 1 end ]
-    if { [ string length [ set fnd [ findabbr $allopts $opt ]]] } then {
+    set opt [ string range [ foxOpts::shift arglist ] 1 end ]
+    if { [ string length [set fnd [foxOpts::findabbr $allopts $opt]]] } then {
       set type $opttype($fnd)
-      if { [ parseOptionType $opttype($fnd) arglist arg ] } then {
+      if { [ foxOpts::parseOptionType $opttype($fnd) arglist arg ] } then {
         if { $_opts($fnd) && ! [ string match "m*" $type ] } then {
           set _args(_ERROR_) "Found multiple occurrences of option -$fnd"
           set retval 0
