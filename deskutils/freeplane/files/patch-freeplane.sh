--- freeplane.sh.orig	2022-07-04 06:07:42 UTC
+++ freeplane.sh
@@ -57,7 +57,7 @@ findjava() {
 		fi
 	fi
 
-	JAVA_VERSION=$(${JAVACMD} -version |& grep -E "[[:alnum:]]+ version" | awk '{print $3}' | tr -d '"')
+	JAVA_VERSION=$(${JAVACMD} -version | grep -E "[[:alnum:]]+ version" | awk '{print $3}' | tr -d '"')
 	JAVA_MAJOR_VERSION=$(echo $JAVA_VERSION | sed -e 's/^1\.//' | awk -F. '{print $1}')
 	if [ $JAVA_MAJOR_VERSION -lt 8 ] || [ $JAVA_MAJOR_VERSION -gt 17 ] || [ $JAVA_MAJOR_VERSION -eq 10 ]; then
 		if [ -z "${FREEPLANE_USE_UNSUPPORTED_JAVA_VERSION}" ]; then
@@ -142,15 +142,7 @@ fi
 
 output_debug_info
 
-if [ -x $(which readlink) ] && [ "`echo $OSTYPE | cut -b1-6`" != "darwin" ]; then
-	# if we have 'readlink' we can use it to get an absolute path
-	# -m should be faster and link does always resolve, else this script
-	# wouldn't be called, would it?
-	freefile=$(readlink -mn "$0")
-	_debug "Link '$0' resolved to '${freefile}'."
-else
-	freefile="$0"
-fi
+freefile="$0"
 
 if [ "`echo $OSTYPE | cut -b1-6`" == "darwin" ]; then
 	xdockname='-Xdock:name=Freeplane'
