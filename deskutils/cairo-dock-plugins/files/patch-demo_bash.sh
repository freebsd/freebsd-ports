--- Dbus/demos/demo_bash/demo_bash.sh.orig	2012-03-10 14:49:47.073972280 +0200
+++ Dbus/demos/demo_bash/demo_bash.sh	2012-03-10 14:51:40.554027497 +0200
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/local/bin/bash
 
 # This is a part of the external demo applets for Cairo-Dock
 #
@@ -24,7 +24,7 @@
 ### Contact : nochka85@glx-dock.org
 ### Rev : 09/02/2011
 
-. /usr/share/cairo-dock/plug-ins/Dbus/CDBashApplet.sh $*
+. /usr/local/share/cairo-dock/plug-ins/Dbus/CDBashApplet.sh $*
 
 #############################################################################################################
 
