--- tools/run-with-tmp-session-bus.sh.orig	Sat Oct  7 16:18:50 2006
+++ tools/run-with-tmp-session-bus.sh	Sat Oct  7 16:19:24 2006
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
