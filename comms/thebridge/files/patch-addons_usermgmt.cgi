--- addons/usermgmt.cgi.orig	2011-02-21 10:51:53.000000000 +0900
+++ addons/usermgmt.cgi	2011-02-21 10:55:12.000000000 +0900
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!%%LOCALBASE%%/bin/bash
 #-------------------------------------------------------------------
 #  TheBridge Echolink Conference Server User Management Utility
 #
@@ -15,7 +15,7 @@
 admin=                        # admin's callsign or quoted name
 qrz=yes                       # leave blank to disable QRZ lookups
 chginfo=no                    # enable/disable Info/Location changes
-tbdcmd=/usr/local/bin/tbdcmd  # path to "tbdcmd" executable
+tbdcmd=%%PREFIX%%/bin/tbdcmd  # path to "tbdcmd" executable
 #-------------------------------------------------------------------
 echo 'Content-type: text/html'
 echo ''
