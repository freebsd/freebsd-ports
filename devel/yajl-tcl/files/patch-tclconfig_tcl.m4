--- tclconfig/tcl.m4.orig	2018-05-07 16:24:46 UTC
+++ tclconfig/tcl.m4
@@ -1602,9 +1602,8 @@ dnl AC_CHECK_TOOL(AR, ar)
 	    UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.a'
 	    TCL_LIB_VERSIONS_OK=nodots
 	    ;;
-	NetBSD-*|FreeBSD-[[3-4]].*)
-	    # FreeBSD 3.* and greater have ELF.
-	    # NetBSD 2.* has ELF and can use 'cc -shared' to build shared libs
+	NetBSD-*)
+	    # NetBSD has ELF and can use 'cc -shared' to build shared libs
 	    SHLIB_CFLAGS="-fPIC"
 	    SHLIB_LD='${CC} -shared ${SHLIB_CFLAGS}'
 	    SHLIB_SUFFIX=".so"
@@ -1618,20 +1617,12 @@ dnl AC_CHECK_TOOL(AR, ar)
 		CFLAGS="$CFLAGS -pthread"
 	    	LDFLAGS="$LDFLAGS -pthread"
 	    ])
-	    case $system in
-	    FreeBSD-3.*)
-	    	# FreeBSD-3 doesn't handle version numbers with dots.
-	    	UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.a'
-	    	SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.so'
-	    	TCL_LIB_VERSIONS_OK=nodots
-		;;
-	    esac
 	    ;;
 	FreeBSD-*)
 	    # This configuration from FreeBSD Ports.
 	    SHLIB_CFLAGS="-fPIC"
 	    SHLIB_LD="${CC} -shared"
-	    TCL_SHLIB_LD_EXTRAS="-soname \$[@]"
+	    SHLIB_LD_LIBS="${SHLIB_LD_LIBS} -Wl,-soname,\$[@]"
 	    SHLIB_SUFFIX=".so"
 	    LDFLAGS=""
 	    AS_IF([test $doRpath = yes], [
