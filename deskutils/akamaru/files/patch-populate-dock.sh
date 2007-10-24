--- populate-dock.sh.orig	Sun Jul 16 01:37:05 2006
+++ populate-dock.sh	Wed Oct 11 22:29:57 2006
@@ -3,18 +3,16 @@
 # Simple shell script to populate the dock by setting up some random
 # standard applications.
 
-make install-schemas
+GAPPs=/usr/local/share/applications
+APPs=/usr/local/share/applications
 
 while read n file; do
     key=/apps/kiba/launchers/$n/file
     gconftool-2 --set $key --type string $file
     gconftool-2 --apply-schema /schemas/apps/kiba/launchers/file $key
 done <<EOF
-    0 /usr/share/applications/gnome-terminal.desktop
-    1 /usr/share/applications/gimp-2.2.desktop
-    2 /usr/share/applications/epiphany.desktop
-    3 /usr/share/applications/gaim.desktop
-    4 /usr/share/applications/gnome-cd.desktop
-    5 /usr/share/applications/background.desktop
-    6 /usr/share/applications/gnome-file-roller.desktop
+    0 $GAPPs/gnome-terminal.desktop
+    1 $GAPPs/gedit.desktop
+    2 $APPs/firefox.desktop
+    3 $GAPPs/evolution-2.8.desktop
 EOF
