--- scripts/printer-setup.sh.orig	Thu Jul  8 23:54:42 2004
+++ scripts/printer-setup.sh	Fri Jul  9 00:05:00 2004
@@ -7,15 +7,15 @@
 # Install all the printer profiles
 if [ $1 == "--install" ]; then
 	# Install GNOME-1.x printer files.
-	if [ -d /usr/share/gnome-print ]; then
-		cp -f /usr/share/gfax/fax-g3.profile /usr/share/gnome-print/profiles
+	if [ -d /usr/share/gnome/gnome-print ]; then
+		cp -f /usr/share/gnome/gfax/fax-g3.profile /usr/share/gnome/gnome-print/profiles
 	fi
 
 	# Install GNOME-2.x printer files.
-	for i in /usr/share/libgnomeprint/*
+	for i in /usr/share/gnome/libgnomeprint/*
 	do
-		cp -f /usr/share/gfax/GFAX.xml $i/printers
-		cp -f /usr/share/gfax/GNOME-GFAX-PS.xml $i/models
+		cp -f /usr/share/gnome/gfax/GFAX.xml $i/printers
+		cp -f /usr/share/gnome/gfax/GNOME-GFAX-PS.xml $i/models
 	done
 fi
 
@@ -23,12 +23,12 @@
 # Remove all the printer profiles
 if [ $1 == "--remove" ]; then
 	# Remove GNOME-1.x printer files.
-	if [ -d /usr/share/gnome-print ]; then
-		rm -f /usr/share/gnome-print/profiles/fax-g3.profile
+	if [ -d /usr/share/gnome/gnome-print ]; then
+		rm -f /usr/share/gnome/gnome-print/profiles/fax-g3.profile
 	fi
 
 	# Remove GNOME-2.x printer files.
-	for i in /usr/share/libgnomeprint/*
+	for i in /usr/share/gnome/libgnomeprint/*
 	do
 		rm -f $i/printers/GFAX.xml
 		rm -f $i/models/GNOME-GFAX-PS.xml
