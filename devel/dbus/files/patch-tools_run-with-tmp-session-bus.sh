--- tools/run-with-tmp-session-bus.sh.orig	Fri Mar 18 02:48:29 2005
+++ tools/run-with-tmp-session-bus.sh	Tue Apr  4 20:40:12 2006
@@ -1,10 +1,10 @@
-#! /bin/bash
+#! /bin/sh
 
 SCRIPTNAME=$0
 WRAPPED_SCRIPT=$1
 shift
 
-function die() 
+die() 
 {
     if ! test -z "$DBUS_SESSION_BUS_PID" ; then
         echo "killing message bus "$DBUS_SESSION_BUS_PID >&2
