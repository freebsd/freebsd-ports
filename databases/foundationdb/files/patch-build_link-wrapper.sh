--- build/link-wrapper.sh.orig	2018-04-25 15:16:53 UTC
+++ build/link-wrapper.sh
@@ -8,6 +8,9 @@ case $1 in
 
 	if [ "$1" = "DynamicLibrary" ]; then
 	    OPTIONS="-shared"
+	    if [ "$PLATFORM" = "freebsd" ]; then
+		OPTIONS="$OPTIONS -Wl,-z,noexecstack -Wl,-soname,$( basename $3 )"
+	    fi
 	    if [ "$PLATFORM" = "linux" ]; then
 		OPTIONS="$OPTIONS -Wl,-z,noexecstack -Wl,-soname,$( basename $3 )"
 	    fi
@@ -43,6 +46,11 @@ case $1 in
 	    case $1 in
 		Application)
 		    case $PLATFORM in
+			freebsd)
+			    objcopy --only-keep-debug $3 $3.debug
+			    if [ -z "${NOSTRIP}" ]; then strip --strip-debug --strip-unneeded $3; fi
+			    objcopy --add-gnu-debuglink=$3.debug $3
+			    ;;
 			linux)
 			    objcopy --only-keep-debug $3 $3.debug
 			    if [ -z "${NOSTRIP}" ]; then strip --strip-debug --strip-unneeded $3; fi
@@ -62,6 +70,9 @@ case $1 in
 		DynamicLibrary)
 		    cp $3 $3-debug
 		    case $PLATFORM in
+			freebsd)
+			    if [ -z "${NOSTRIP}" ]; then strip --strip-all $3; fi
+			    ;;
 			linux)
 			    if [ -z "${NOSTRIP}" ]; then strip --strip-all $3; fi
 			    ;;
