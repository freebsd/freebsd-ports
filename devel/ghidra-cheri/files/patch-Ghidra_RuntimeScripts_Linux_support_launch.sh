--- Ghidra/RuntimeScripts/Linux/support/launch.sh.orig	2019-11-05 09:27:57 UTC
+++ Ghidra/RuntimeScripts/Linux/support/launch.sh
@@ -88,6 +88,7 @@ else
 	DEBUG_LOG4J="${INSTALL_DIR}/Ghidra/RuntimeScripts/Common/support/debug.log4j.xml"
 fi
 
+PATH="JAVA_HOME_PLACEHOLDER/bin:$PATH"
 # Make sure some kind of java is on the path.  It's required to run the LaunchSupport program.
 if ! [ -x "$(command -v java)" ] ; then
 	echo "Java runtime not found.  Please refer to the Ghidra Installation Guide's Troubleshooting section."
