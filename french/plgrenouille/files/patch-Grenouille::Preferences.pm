--- Grenouille/Preferences.pm.orig	Mon Mar 17 15:26:46 2003
+++ Grenouille/Preferences.pm	Thu Mar  4 03:55:34 2004
@@ -15,6 +15,7 @@
 %preferences = ();
 
 sub load_preferences() {
+    swap_privileges();
     eval {
 	if (open(CONFIG, "<$MYRC")) {
 	    while (<CONFIG>) {
@@ -25,6 +26,7 @@
 	    close(CONFIG);
 	}
     };
+    swap_privileges();
     die if $@;
 }
 
