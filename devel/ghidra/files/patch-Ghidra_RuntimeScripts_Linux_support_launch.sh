--- Ghidra/RuntimeScripts/Linux/support/launch.sh.orig	2019-04-10 09:13:14 UTC
+++ Ghidra/RuntimeScripts/Linux/support/launch.sh
@@ -88,6 +88,7 @@ else
 	DEBUG_LOG4J="${INSTALL_DIR}/Ghidra/RuntimeScripts/Common/support/debug.log4j.xml"
 fi
 
+PATH="/usr/local/openjdk12/bin:/usr/local/openjdk11:"$PATH
 # Make sure some kind of java is on the path.  It's required to run the LaunchSupport program.
 if ! [ -x "$(command -v java)" ] ; then
 	echo "Java runtime not found.  Please refer to the Ghidra Installation Guide's Troubleshooting section."
