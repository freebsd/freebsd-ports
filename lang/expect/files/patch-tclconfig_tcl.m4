--- tclconfig/tcl.m4.orig	2018-02-04 13:55:43 UTC
+++ tclconfig/tcl.m4
@@ -8,14 +8,12 @@
 #
 # See the file "license.terms" for information on usage and redistribution
 # of this file, and for a DISCLAIMER OF ALL WARRANTIES.
-#
-# RCS: @(#) $Id: tcl.m4,v 1.6 2010/09/16 20:46:47 hobbs Exp $
 
 AC_PREREQ(2.57)
 
 dnl TEA extensions pass us the version of TEA they think they
 dnl are compatible with (must be set in TEA_INIT below)
-dnl TEA_VERSION="3.9"
+dnl TEA_VERSION="3.10"
 
 # Possible values for key variables defined:
 #
@@ -140,6 +138,8 @@ AC_DEFUN([TEA_PATH_TCLCONFIG], [
 			`ls -d /usr/contrib/lib 2>/dev/null` \
 			`ls -d /usr/lib 2>/dev/null` \
 			`ls -d /usr/lib64 2>/dev/null` \
+			`ls -d /usr/lib/tcl8.6 2>/dev/null` \
+			`ls -d /usr/lib/tcl8.5 2>/dev/null` \
 			; do
 		    if test -f "$i/tclConfig.sh" ; then
 			ac_cv_c_tclconfig="`(cd $i; pwd)`"
@@ -170,7 +170,7 @@ AC_DEFUN([TEA_PATH_TCLCONFIG], [
 
 	if test x"${ac_cv_c_tclconfig}" = x ; then
 	    TCL_BIN_DIR="# no Tcl configs found"
-	    AC_MSG_ERROR([Can't find Tcl configuration definitions])
+	    AC_MSG_ERROR([Can't find Tcl configuration definitions. Use --with-tcl to specify a directory containing tclConfig.sh])
 	else
 	    no_tcl=
 	    TCL_BIN_DIR="${ac_cv_c_tclconfig}"
@@ -323,7 +323,7 @@ AC_DEFUN([TEA_PATH_TKCONFIG], [
 
 	if test x"${ac_cv_c_tkconfig}" = x ; then
 	    TK_BIN_DIR="# no Tk configs found"
-	    AC_MSG_ERROR([Can't find Tk configuration definitions])
+	    AC_MSG_ERROR([Can't find Tk configuration definitions. Use --with-tk to specify a directory containing tkConfig.sh])
 	else
 	    no_tk=
 	    TK_BIN_DIR="${ac_cv_c_tkconfig}"
@@ -344,11 +344,10 @@ AC_DEFUN([TEA_PATH_TKCONFIG], [
 #
 # Results:
 #
-#	Subst the following vars:
+#	Substitutes the following vars:
 #		TCL_BIN_DIR
 #		TCL_SRC_DIR
 #		TCL_LIB_FILE
-#
 #------------------------------------------------------------------------
 
 AC_DEFUN([TEA_LOAD_TCLCONFIG], [
@@ -417,25 +416,21 @@ AC_DEFUN([TEA_LOAD_TCLCONFIG], [
     AC_SUBST(TCL_STUB_LIB_FLAG)
     AC_SUBST(TCL_STUB_LIB_SPEC)
 
-    case "`uname -s`" in
-	*CYGWIN_*)
-	    AC_MSG_CHECKING([for cygwin variant])
-	    case ${TCL_EXTRA_CFLAGS} in
-		*-mwin32*|*-mno-cygwin*)
-		    TEA_PLATFORM="windows"
-		    CFLAGS="$CFLAGS -mwin32"
-		    AC_MSG_RESULT([win32])
-		    ;;
-		*)
-		    TEA_PLATFORM="unix"
-		    AC_MSG_RESULT([unix])
-		    ;;
-	    esac
-	    EXEEXT=".exe"
-	    ;;
-	*)
-	    ;;
-    esac
+    AC_MSG_CHECKING([platform])
+    hold_cc=$CC; CC="$TCL_CC"
+    AC_TRY_COMPILE(,[
+	    #ifdef _WIN32
+		#error win32
+	    #endif
+	], [
+	    TEA_PLATFORM="unix"
+	    CYGPATH=echo
+	], [
+	    TEA_PLATFORM="windows"
+	    AC_CHECK_PROG(CYGPATH, cygpath, cygpath -m, echo)	]
+    )
+    CC=$hold_cc
+    AC_MSG_RESULT($TEA_PLATFORM)
 
     # The BUILD_$pkg is to define the correct extern storage class
     # handling when making this package
@@ -443,6 +438,7 @@ AC_DEFUN([TEA_LOAD_TCLCONFIG], [
 	    [Building extension source?])
     # Do this here as we have fully defined TEA_PLATFORM now
     if test "${TEA_PLATFORM}" = "windows" ; then
+	EXEEXT=".exe"
 	CLEANFILES="$CLEANFILES *.lib *.dll *.pdb *.exp"
     fi
 
@@ -567,11 +563,11 @@ AC_DEFUN([TEA_LOAD_TKCONFIG], [
 #	only for running extension test cases. It should never be
 #	or generation of files (like pkgIndex.tcl) at build time.
 #
-# Arguments
+# Arguments:
 #	none
 #
-# Results
-#	Subst's the following values:
+# Results:
+#	Substitutes the following vars:
 #		TCLSH_PROG
 #------------------------------------------------------------------------
 
@@ -580,7 +576,15 @@ AC_DEFUN([TEA_PROG_TCLSH], [
     if test -f "${TCL_BIN_DIR}/Makefile" ; then
         # tclConfig.sh is in Tcl build directory
         if test "${TEA_PLATFORM}" = "windows"; then
+          if test -f "${TCL_BIN_DIR}/tclsh${TCL_MAJOR_VERSION}${TCL_MINOR_VERSION}${TCL_DBGX}${EXEEXT}" ; then
             TCLSH_PROG="${TCL_BIN_DIR}/tclsh${TCL_MAJOR_VERSION}${TCL_MINOR_VERSION}${TCL_DBGX}${EXEEXT}"
+          elif test -f "${TCL_BIN_DIR}/tclsh${TCL_MAJOR_VERSION}${TCL_MINOR_VERSION}${TCL_DBGX}s${EXEEXT}" ; then
+            TCLSH_PROG="${TCL_BIN_DIR}/tclsh${TCL_MAJOR_VERSION}${TCL_MINOR_VERSION}${TCL_DBGX}s${EXEEXT}"
+          elif test -f "${TCL_BIN_DIR}/tclsh${TCL_MAJOR_VERSION}${TCL_MINOR_VERSION}${TCL_DBGX}t${EXEEXT}" ; then
+            TCLSH_PROG="${TCL_BIN_DIR}/tclsh${TCL_MAJOR_VERSION}${TCL_MINOR_VERSION}${TCL_DBGX}t${EXEEXT}"
+          elif test -f "${TCL_BIN_DIR}/tclsh${TCL_MAJOR_VERSION}${TCL_MINOR_VERSION}${TCL_DBGX}st${EXEEXT}" ; then
+            TCLSH_PROG="${TCL_BIN_DIR}/tclsh${TCL_MAJOR_VERSION}${TCL_MINOR_VERSION}${TCL_DBGX}st${EXEEXT}"
+          fi
         else
             TCLSH_PROG="${TCL_BIN_DIR}/tclsh"
         fi
@@ -617,11 +621,11 @@ AC_DEFUN([TEA_PROG_TCLSH], [
 #	only for running extension test cases. It should never be
 #	or generation of files (like pkgIndex.tcl) at build time.
 #
-# Arguments
+# Arguments:
 #	none
 #
-# Results
-#	Subst's the following values:
+# Results:
+#	Substitutes the following vars:
 #		WISH_PROG
 #------------------------------------------------------------------------
 
@@ -630,9 +634,17 @@ AC_DEFUN([TEA_PROG_WISH], [
     if test -f "${TK_BIN_DIR}/Makefile" ; then
         # tkConfig.sh is in Tk build directory
         if test "${TEA_PLATFORM}" = "windows"; then
+          if test -f "${TK_BIN_DIR}/wish${TK_MAJOR_VERSION}${TK_MINOR_VERSION}${TK_DBGX}${EXEEXT}" ; then
             WISH_PROG="${TK_BIN_DIR}/wish${TK_MAJOR_VERSION}${TK_MINOR_VERSION}${TK_DBGX}${EXEEXT}"
+          elif test -f "${TK_BIN_DIR}/wish${TK_MAJOR_VERSION}${TK_MINOR_VERSION}${TK_DBGX}s${EXEEXT}" ; then
+            WISH_PROG="${TK_BIN_DIR}/wish${TK_MAJOR_VERSION}${TK_MINOR_VERSION}${TK_DBGX}$s{EXEEXT}"
+          elif test -f "${TK_BIN_DIR}/wish${TK_MAJOR_VERSION}${TK_MINOR_VERSION}${TK_DBGX}t${EXEEXT}" ; then
+            WISH_PROG="${TK_BIN_DIR}/wish${TK_MAJOR_VERSION}${TK_MINOR_VERSION}${TK_DBGX}t${EXEEXT}"
+          elif test -f "${TK_BIN_DIR}/wish${TK_MAJOR_VERSION}${TK_MINOR_VERSION}${TK_DBGX}st${EXEEXT}" ; then
+            WISH_PROG="${TK_BIN_DIR}/wish${TK_MAJOR_VERSION}${TK_MINOR_VERSION}${TK_DBGX}st${EXEEXT}"
+          fi
         else
-            WISH_PROG="${TK_BIN_DIR}/wish"
+          WISH_PROG="${TK_BIN_DIR}/wish"
         fi
     else
         # tkConfig.sh is in install location
@@ -732,7 +744,6 @@ AC_DEFUN([TEA_ENABLE_SHARED], [
 #		TCL_THREADS
 #		_REENTRANT
 #		_THREAD_SAFE
-#
 #------------------------------------------------------------------------
 
 AC_DEFUN([TEA_ENABLE_THREADS], [
@@ -856,12 +867,11 @@ AC_DEFUN([TEA_ENABLE_THREADS], [
 #
 #	Defines the following vars:
 #		CFLAGS_DEFAULT	Sets to $(CFLAGS_DEBUG) if true
-#				Sets to $(CFLAGS_OPTIMIZE) if false
+#				Sets to "$(CFLAGS_OPTIMIZE) -DNDEBUG" if false
 #		LDFLAGS_DEFAULT	Sets to $(LDFLAGS_DEBUG) if true
 #				Sets to $(LDFLAGS_OPTIMIZE) if false
 #		DBGX		Formerly used as debug library extension;
 #				always blank now.
-#
 #------------------------------------------------------------------------
 
 AC_DEFUN([TEA_ENABLE_SYMBOLS], [
@@ -874,7 +884,7 @@ AC_DEFUN([TEA_ENABLE_SYMBOLS], [
 	[tcl_ok=$enableval], [tcl_ok=no])
     DBGX=""
     if test "$tcl_ok" = "no"; then
-	CFLAGS_DEFAULT="${CFLAGS_OPTIMIZE}"
+	CFLAGS_DEFAULT="${CFLAGS_OPTIMIZE} -DNDEBUG"
 	LDFLAGS_DEFAULT="${LDFLAGS_OPTIMIZE}"
 	AC_MSG_RESULT([no])
     else
@@ -921,7 +931,6 @@ AC_DEFUN([TEA_ENABLE_SYMBOLS], [
 #
 #	Defines the following vars:
 #		HAVE_LANGINFO	Triggers use of nl_langinfo if defined.
-#
 #------------------------------------------------------------------------
 
 AC_DEFUN([TEA_ENABLE_LANGINFO], [
@@ -962,7 +971,6 @@ AC_DEFUN([TEA_ENABLE_LANGINFO], [
 #	Defines the following var:
 #
 #	system -	System/platform/version identification code.
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_CONFIG_SYSTEM], [
@@ -1031,21 +1039,20 @@ AC_DEFUN([TEA_CONFIG_SYSTEM], [
 #                       extensions.  An empty string means we don't know how
 #                       to use shared libraries on this platform.
 #       LIB_SUFFIX -    Specifies everything that comes after the "libfoo"
-#                       in a static or shared library name, using the $VERSION variable
+#                       in a static or shared library name, using the $PACKAGE_VERSION variable
 #                       to put the version in the right place.  This is used
 #                       by platforms that need non-standard library names.
-#                       Examples:  ${VERSION}.so.1.1 on NetBSD, since it needs
-#                       to have a version after the .so, and ${VERSION}.a
+#                       Examples:  ${PACKAGE_VERSION}.so.1.1 on NetBSD, since it needs
+#                       to have a version after the .so, and ${PACKAGE_VERSION}.a
 #                       on AIX, since a shared library needs to have
 #                       a .a extension whereas shared objects for loadable
 #                       extensions have a .so extension.  Defaults to
-#                       ${VERSION}${SHLIB_SUFFIX}.
+#                       ${PACKAGE_VERSION}${SHLIB_SUFFIX}.
 #	CFLAGS_DEBUG -
 #			Flags used when running the compiler in debug mode
 #	CFLAGS_OPTIMIZE -
 #			Flags used when running the compiler in optimize mode
 #	CFLAGS -	Additional CFLAGS added as necessary (usually 64-bit)
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_CONFIG_CFLAGS], [
@@ -1087,6 +1094,7 @@ AC_DEFUN([TEA_CONFIG_CFLAGS], [
 	AC_DEFINE(MODULE_SCOPE,
 	    [extern __attribute__((__visibility__("hidden")))],
 	    [Compiler support for module scope symbols])
+	AC_DEFINE(HAVE_HIDDEN, [1], [Compiler support for module scope symbols])
     ])
 
     # Step 0.d: Disable -rpath support?
@@ -1135,18 +1143,17 @@ AC_DEFUN([TEA_CONFIG_CFLAGS], [
     ECHO_VERSION='`echo ${PACKAGE_VERSION}`'
     TCL_LIB_VERSIONS_OK=ok
     CFLAGS_DEBUG=-g
-    CFLAGS_OPTIMIZE=-O
     AS_IF([test "$GCC" = yes], [
-	# TEA specific:
 	CFLAGS_OPTIMIZE=-O2
 	CFLAGS_WARNING="-Wall"
-    ], [CFLAGS_WARNING=""])
-dnl FIXME: Replace AC_CHECK_PROG with AC_CHECK_TOOL once cross compiling is fixed.
-dnl AC_CHECK_TOOL(AR, ar)
-    AC_CHECK_PROG(AR, ar, ar)
+    ], [
+	CFLAGS_OPTIMIZE=-O
+	CFLAGS_WARNING=""
+    ])
+    AC_CHECK_TOOL(AR, ar)
     STLIB_LD='${AR} cr'
     LD_LIBRARY_PATH_VAR="LD_LIBRARY_PATH"
-    AS_IF([test "x$SHLIB_VERSION" = x],[SHLIB_VERSION="1.0"])
+    AS_IF([test "x$SHLIB_VERSION" = x],[SHLIB_VERSION=""],[SHLIB_VERSION=".$SHLIB_VERSION"])
     case $system in
 	# TEA specific:
 	windows)
@@ -1172,7 +1179,7 @@ dnl AC_CHECK_TOOL(AR, ar)
 			PATH64="${MSSDK}/Bin/Win64"
 			;;
 		esac
-		if test ! -d "${PATH64}" ; then
+		if test "$GCC" != "yes" -a ! -d "${PATH64}" ; then
 		    AC_MSG_WARN([Could not find 64-bit $MACHINE SDK to enable 64bit mode])
 		    AC_MSG_WARN([Ensure latest Platform SDK is installed])
 		    do64bit="no"
@@ -1247,13 +1254,21 @@ dnl AC_CHECK_TOOL(AR, ar)
 	        else
 		    runtime=-MD
 	        fi
+	        case "x`echo \${VisualStudioVersion}`" in
+	            x1[[4-9]]*)
+		        lflags="${lflags} -nodefaultlib:libucrt.lib"
+		        TEA_ADD_LIBS([ucrt.lib])
+	            ;;
+	            *)
+	            ;;
+	        esac
 
                 if test "$do64bit" != "no" ; then
 		    # All this magic is necessary for the Win64 SDK RC1 - hobbs
 		    CC="\"${PATH64}/cl.exe\""
 		    CFLAGS="${CFLAGS} -I\"${MSSDK}/Include\" -I\"${MSSDK}/Include/crt\" -I\"${MSSDK}/Include/crt/sys\""
 		    RC="\"${MSSDK}/bin/rc.exe\""
-		    lflags="-nologo -MACHINE:${MACHINE} -LIBPATH:\"${MSSDK}/Lib/${MACHINE}\""
+		    lflags="${lflags} -nologo -MACHINE:${MACHINE} -LIBPATH:\"${MSSDK}/Lib/${MACHINE}\""
 		    LINKBIN="\"${PATH64}/link.exe\""
 		    CFLAGS_DEBUG="-nologo -Zi -Od -W3 ${runtime}d"
 		    CFLAGS_OPTIMIZE="-nologo -O2 -W2 ${runtime}"
@@ -1283,13 +1298,13 @@ dnl AC_CHECK_TOOL(AR, ar)
 		    CFLAGS_DEBUG="-nologo -Zi -Od"
 		    CFLAGS_OPTIMIZE="-nologo -Ox"
 		    lversion=`echo ${CEVERSION} | sed -e 's/\(.\)\(..\)/\1\.\2/'`
-		    lflags="-MACHINE:${ARCH} -LIBPATH:\"${CELIBPATH}\" -subsystem:windowsce,${lversion} -nologo"
+		    lflags="${lflags} -MACHINE:${ARCH} -LIBPATH:\"${CELIBPATH}\" -subsystem:windowsce,${lversion} -nologo"
 		    LINKBIN="\"${CEBINROOT}/link.exe\""
 		    AC_SUBST(CELIB_DIR)
 		else
 		    RC="rc"
-		    lflags="-nologo"
-    		    LINKBIN="link"
+		    lflags="${lflags} -nologo"
+		    LINKBIN="link"
 		    CFLAGS_DEBUG="-nologo -Z7 -Od -W3 -WX ${runtime}d"
 		    CFLAGS_OPTIMIZE="-nologo -O2 -W2 ${runtime}"
 		fi
@@ -1297,13 +1312,45 @@ dnl AC_CHECK_TOOL(AR, ar)
 
 	    if test "$GCC" = "yes"; then
 		# mingw gcc mode
-		RC="windres"
+		AC_CHECK_TOOL(RC, windres)
 		CFLAGS_DEBUG="-g"
 		CFLAGS_OPTIMIZE="-O2 -fomit-frame-pointer"
-		SHLIB_LD="$CC -shared"
+		SHLIB_LD='${CC} -shared'
 		UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.a'
+  	PRACTCL_UNSHARED_LIB_SUFFIX='.a'
+
 		LDFLAGS_CONSOLE="-wl,--subsystem,console ${lflags}"
 		LDFLAGS_WINDOW="-wl,--subsystem,windows ${lflags}"
+
+		AC_CACHE_CHECK(for cross-compile version of gcc,
+			ac_cv_cross,
+			AC_TRY_COMPILE([
+			    #ifdef _WIN32
+				#error cross-compiler
+			    #endif
+			], [],
+			ac_cv_cross=yes,
+			ac_cv_cross=no)
+		      )
+		      if test "$ac_cv_cross" = "yes"; then
+			case "$do64bit" in
+			    amd64|x64|yes)
+				CC="x86_64-w64-mingw32-gcc"
+				LD="x86_64-w64-mingw32-ld"
+				AR="x86_64-w64-mingw32-ar"
+				RANLIB="x86_64-w64-mingw32-ranlib"
+				RC="x86_64-w64-mingw32-windres"
+			    ;;
+			    *)
+				CC="i686-w64-mingw32-gcc"
+				LD="i686-w64-mingw32-ld"
+				AR="i686-w64-mingw32-ar"
+				RANLIB="i686-w64-mingw32-ranlib"
+				RC="i686-w64-mingw32-windres"
+			    ;;
+			esac
+		fi
+
 	    else
 		SHLIB_LD="${LINKBIN} -dll ${lflags}"
 		# link -lib only works when -lib is the first arg
@@ -1409,8 +1456,10 @@ dnl AC_CHECK_TOOL(AR, ar)
 	CYGWIN_*)
 	    SHLIB_CFLAGS=""
 	    SHLIB_LD='${CC} -shared'
+	    SHLIB_LD_LIBS="${SHLIB_LD_LIBS} -Wl,--out-implib,\$[@].a"
 	    SHLIB_SUFFIX=".dll"
-	    EXE_SUFFIX=".exe"
+	    EXEEXT=".exe"
+	    do64bit_ok=yes
 	    CC_SEARCH_FLAGS=""
 	    LD_SEARCH_FLAGS=""
 	    ;;
@@ -1521,7 +1570,7 @@ dnl AC_CHECK_TOOL(AR, ar)
 	        ])
 	    ])
 	    ;;
-	Linux*)
+	Linux*|GNU*|NetBSD-Debian)
 	    SHLIB_CFLAGS="-fPIC"
 	    SHLIB_SUFFIX=".so"
 
@@ -1554,17 +1603,6 @@ dnl AC_CHECK_TOOL(AR, ar)
 	    # files in compat/*.c is being linked in.
 
 	    AS_IF([test x"${USE_COMPAT}" != x],[CFLAGS="$CFLAGS -fno-inline"])
-
-	    ;;
-	GNU*)
-	    SHLIB_CFLAGS="-fPIC"
-	    SHLIB_SUFFIX=".so"
-
-	    SHLIB_LD='${CC} -shared'
-	    LDFLAGS="$LDFLAGS -Wl,--export-dynamic"
-	    CC_SEARCH_FLAGS=""
-	    LD_SEARCH_FLAGS=""
-	    AS_IF([test "`uname -m`" = "alpha"], [CFLAGS="$CFLAGS -mieee"])
 	    ;;
 	Lynx*)
 	    SHLIB_CFLAGS="-fPIC"
@@ -1577,35 +1615,51 @@ dnl AC_CHECK_TOOL(AR, ar)
 		LD_SEARCH_FLAGS='-Wl,-rpath,${LIB_RUNTIME_DIR}'])
 	    ;;
 	OpenBSD-*)
-	    SHLIB_CFLAGS="-fPIC"
-	    SHLIB_LD='${CC} -shared ${SHLIB_CFLAGS}'
-	    SHLIB_SUFFIX=".so"
-	    AS_IF([test $doRpath = yes], [
-		CC_SEARCH_FLAGS='-Wl,-rpath,${LIB_RUNTIME_DIR}'])
-	    LD_SEARCH_FLAGS=${CC_SEARCH_FLAGS}
-	    SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.so.${SHLIB_VERSION}'
-	    AC_CACHE_CHECK([for ELF], tcl_cv_ld_elf, [
-		AC_EGREP_CPP(yes, [
-#ifdef __ELF__
-	yes
-#endif
-		], tcl_cv_ld_elf=yes, tcl_cv_ld_elf=no)])
-	    AS_IF([test $tcl_cv_ld_elf = yes], [
-		LDFLAGS=-Wl,-export-dynamic
-	    ], [LDFLAGS=""])
+	    arch=`arch -s`
+	    case "$arch" in
+	    vax)
+		SHLIB_SUFFIX=""
+		SHARED_LIB_SUFFIX=""
+		LDFLAGS=""
+		;;
+	    *)
+		case "$arch" in
+		alpha|sparc64)
+		    SHLIB_CFLAGS="-fPIC"
+		    ;;
+		*)
+		    SHLIB_CFLAGS="-fpic"
+		    ;;
+		esac
+		SHLIB_LD='${CC} -shared ${SHLIB_CFLAGS}'
+		SHLIB_SUFFIX=".so"
+		AS_IF([test $doRpath = yes], [
+		    CC_SEARCH_FLAGS='-Wl,-rpath,${LIB_RUNTIME_DIR}'])
+		LD_SEARCH_FLAGS=${CC_SEARCH_FLAGS}
+		SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.so${SHLIB_VERSION}'
+		LDFLAGS="-Wl,-export-dynamic"
+		;;
+	    esac
+	    case "$arch" in
+	    vax)
+		CFLAGS_OPTIMIZE="-O1"
+		;;
+	    *)
+		CFLAGS_OPTIMIZE="-O2"
+		;;
+	    esac
 	    AS_IF([test "${TCL_THREADS}" = "1"], [
-		# OpenBSD builds and links with -pthread, never -lpthread.
+		# On OpenBSD:	Compile with -pthread
+		#		Don't link with -lpthread
 		LIBS=`echo $LIBS | sed s/-lpthread//`
 		CFLAGS="$CFLAGS -pthread"
-		SHLIB_CFLAGS="$SHLIB_CFLAGS -pthread"
 	    ])
 	    # OpenBSD doesn't do version numbers with dots.
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
@@ -1619,35 +1673,31 @@ dnl AC_CHECK_TOOL(AR, ar)
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
 		CC_SEARCH_FLAGS='-Wl,-rpath,${LIB_RUNTIME_DIR}'
-		LD_SEARCH_FLAGS='-rpath ${LIB_RUNTIME_DIR}'])
+		LD_SEARCH_FLAGS='-Wl,-rpath,${LIB_RUNTIME_DIR}'])
 	    AS_IF([test "${TCL_THREADS}" = "1"], [
 		# The -pthread needs to go in the LDFLAGS, not LIBS
 		LIBS=`echo $LIBS | sed s/-pthread//`
 		CFLAGS="$CFLAGS $PTHREAD_CFLAGS"
 		LDFLAGS="$LDFLAGS $PTHREAD_LIBS"])
-	    # Version numbers are dot-stripped by system policy.
-	    TCL_TRIM_DOTS=`echo ${VERSION} | tr -d .`
-	    UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.a'
-	    SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.so.1'
-	    TCL_LIB_VERSIONS_OK=nodots
+	    case $system in
+	    FreeBSD-3.*)
+		# Version numbers are dot-stripped by system policy.
+		TCL_TRIM_DOTS=`echo ${PACKAGE_VERSION} | tr -d .`
+		UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}.a'
+		SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.so.1'
+		TCL_LIB_VERSIONS_OK=nodots
+		;;
+	    esac
 	    ;;
 	Darwin-*)
 	    CFLAGS_OPTIMIZE="-Os"
@@ -1706,7 +1756,7 @@ dnl AC_CHECK_TOOL(AR, ar)
 	    AS_IF([test $tcl_cv_ld_single_module = yes], [
 		SHLIB_LD="${SHLIB_LD} -Wl,-single_module"
 	    ])
-	    # TEA specific: link shlib with current and compatiblity version flags
+	    # TEA specific: link shlib with current and compatibility version flags
 	    vers=`echo ${PACKAGE_VERSION} | sed -e 's/^\([[0-9]]\{1,5\}\)\(\(\.[[0-9]]\{1,3\}\)\{0,2\}\).*$/\1\2/p' -e d`
 	    SHLIB_LD="${SHLIB_LD} -current_version ${vers:-0} -compatibility_version ${vers:-0}"
 	    SHLIB_SUFFIX=".dylib"
@@ -1818,8 +1868,8 @@ dnl AC_CHECK_TOOL(AR, ar)
 		SHLIB_CFLAGS="-fPIC -melf"
 		LDFLAGS="$LDFLAGS -melf -Wl,-Bexport"
 	    ], [
-	       SHLIB_CFLAGS="-Kpic -belf"
-	       LDFLAGS="$LDFLAGS -belf -Wl,-Bexport"
+		SHLIB_CFLAGS="-Kpic -belf"
+		LDFLAGS="$LDFLAGS -belf -Wl,-Bexport"
 	    ])
 	    SHLIB_LD="ld -G"
 	    SHLIB_LD_LIBS=""
@@ -1942,6 +1992,24 @@ dnl AC_CHECK_TOOL(AR, ar)
 		LD_SEARCH_FLAGS='-R ${LIB_RUNTIME_DIR}'
 	    ])
 	    ;;
+	UNIX_SV* | UnixWare-5*)
+	    SHLIB_CFLAGS="-KPIC"
+	    SHLIB_LD='${CC} -G'
+	    SHLIB_LD_LIBS=""
+	    SHLIB_SUFFIX=".so"
+	    # Some UNIX_SV* systems (unixware 1.1.2 for example) have linkers
+	    # that don't grok the -Bexport option.  Test that it does.
+	    AC_CACHE_CHECK([for ld accepts -Bexport flag], tcl_cv_ld_Bexport, [
+		hold_ldflags=$LDFLAGS
+		LDFLAGS="$LDFLAGS -Wl,-Bexport"
+		AC_TRY_LINK(, [int i;], tcl_cv_ld_Bexport=yes, tcl_cv_ld_Bexport=no)
+	        LDFLAGS=$hold_ldflags])
+	    AS_IF([test $tcl_cv_ld_Bexport = yes], [
+		LDFLAGS="$LDFLAGS -Wl,-Bexport"
+	    ])
+	    CC_SEARCH_FLAGS=""
+	    LD_SEARCH_FLAGS=""
+	    ;;
     esac
 
     AS_IF([test "$do64bit" = yes -a "$do64bit_ok" = no], [
@@ -1966,7 +2034,7 @@ dnl # preprocessing tests use only CPPFL
 	case $system in
 	    AIX-*) ;;
 	    BSD/OS*) ;;
-	    CYGWIN_*) ;;
+	    CYGWIN_*|MINGW32_*) ;;
 	    IRIX*) ;;
 	    NetBSD-*|FreeBSD-*|OpenBSD-*) ;;
 	    Darwin-*) ;;
@@ -1978,15 +2046,111 @@ dnl # preprocessing tests use only CPPFL
     AS_IF([test "$tcl_cv_cc_visibility_hidden" != yes], [
 	AC_DEFINE(MODULE_SCOPE, [extern],
 	    [No Compiler support for module scope symbols])
-	AC_DEFINE(NO_VIZ, [], [No visibility hidden passed to zlib?])
     ])
 
     AS_IF([test "$SHARED_LIB_SUFFIX" = ""], [
-	# TEA specific: use PACKAGE_VERSION instead of VERSION
-	SHARED_LIB_SUFFIX='${PACKAGE_VERSION}${SHLIB_SUFFIX}'])
+    # TEA specific: use PACKAGE_VERSION instead of VERSION
+    SHARED_LIB_SUFFIX='${PACKAGE_VERSION}${SHLIB_SUFFIX}'
+		])
     AS_IF([test "$UNSHARED_LIB_SUFFIX" = ""], [
-	# TEA specific: use PACKAGE_VERSION instead of VERSION
-	UNSHARED_LIB_SUFFIX='${PACKAGE_VERSION}.a'])
+    # TEA specific: use PACKAGE_VERSION instead of VERSION
+    UNSHARED_LIB_SUFFIX='${PACKAGE_VERSION}.a'
+		])
+
+    if test "${GCC}" = "yes" -a ${SHLIB_SUFFIX} = ".dll"; then
+	AC_CACHE_CHECK(for SEH support in compiler,
+	    tcl_cv_seh,
+	AC_TRY_RUN([
+#define WIN32_LEAN_AND_MEAN
+#include <windows.h>
+#undef WIN32_LEAN_AND_MEAN
+
+	    int main(int argc, char** argv) {
+		int a, b = 0;
+		__try {
+		    a = 666 / b;
+		}
+		__except (EXCEPTION_EXECUTE_HANDLER) {
+		    return 0;
+		}
+		return 1;
+	    }
+	],
+	    tcl_cv_seh=yes,
+	    tcl_cv_seh=no,
+	    tcl_cv_seh=no)
+	)
+	if test "$tcl_cv_seh" = "no" ; then
+	    AC_DEFINE(HAVE_NO_SEH, 1,
+		    [Defined when mingw does not support SEH])
+	fi
+
+	#
+	# Check to see if the excpt.h include file provided contains the
+	# definition for EXCEPTION_DISPOSITION; if not, which is the case
+	# with Cygwin's version as of 2002-04-10, define it to be int,
+	# sufficient for getting the current code to work.
+	#
+	AC_CACHE_CHECK(for EXCEPTION_DISPOSITION support in include files,
+	    tcl_cv_eh_disposition,
+	    AC_TRY_COMPILE([
+#	    define WIN32_LEAN_AND_MEAN
+#	    include <windows.h>
+#	    undef WIN32_LEAN_AND_MEAN
+	    ],[
+		EXCEPTION_DISPOSITION x;
+	    ],
+		tcl_cv_eh_disposition=yes,
+		tcl_cv_eh_disposition=no)
+	)
+	if test "$tcl_cv_eh_disposition" = "no" ; then
+	AC_DEFINE(EXCEPTION_DISPOSITION, int,
+		[Defined when cygwin/mingw does not support EXCEPTION DISPOSITION])
+	fi
+
+	# Check to see if winnt.h defines CHAR, SHORT, and LONG
+	# even if VOID has already been #defined. The win32api
+	# used by mingw and cygwin is known to do this.
+
+	AC_CACHE_CHECK(for winnt.h that ignores VOID define,
+	    tcl_cv_winnt_ignore_void,
+	    AC_TRY_COMPILE([
+#define VOID void
+#define WIN32_LEAN_AND_MEAN
+#include <windows.h>
+#undef WIN32_LEAN_AND_MEAN
+	    ], [
+		CHAR c;
+		SHORT s;
+		LONG l;
+	    ],
+        tcl_cv_winnt_ignore_void=yes,
+        tcl_cv_winnt_ignore_void=no)
+	)
+	if test "$tcl_cv_winnt_ignore_void" = "yes" ; then
+	    AC_DEFINE(HAVE_WINNT_IGNORE_VOID, 1,
+		    [Defined when cygwin/mingw ignores VOID define in winnt.h])
+	fi
+    fi
+
+	# See if the compiler supports casting to a union type.
+	# This is used to stop gcc from printing a compiler
+	# warning when initializing a union member.
+
+	AC_CACHE_CHECK(for cast to union support,
+	    tcl_cv_cast_to_union,
+	    AC_TRY_COMPILE([],
+	    [
+		  union foo { int i; double d; };
+		  union foo f = (union foo) (int) 0;
+	    ],
+	    tcl_cv_cast_to_union=yes,
+	    tcl_cv_cast_to_union=no)
+	)
+	if test "$tcl_cv_cast_to_union" = "yes"; then
+	    AC_DEFINE(HAVE_CAST_TO_UNION, 1,
+		    [Defined when compiler supports casting to union type.])
+	fi
 
     AC_SUBST(CFLAGS_DEBUG)
     AC_SUBST(CFLAGS_OPTIMIZE)
@@ -1994,6 +2158,7 @@ dnl # preprocessing tests use only CPPFL
 
     AC_SUBST(STLIB_LD)
     AC_SUBST(SHLIB_LD)
+		AC_SUBST(SHLIB_SUFFIX)
 
     AC_SUBST(SHLIB_LD_LIBS)
     AC_SUBST(SHLIB_CFLAGS)
@@ -2025,7 +2190,6 @@ dnl # preprocessing tests use only CPPFL
 #		USE_TERMIOS
 #		USE_TERMIO
 #		USE_SGTTY
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_SERIAL_PORT], [
@@ -2237,7 +2401,6 @@ closedir(d);
 #		XINCLUDES
 #		XLIBSW
 #		PKG_LIBS (appends to)
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_PATH_X], [
@@ -2251,9 +2414,9 @@ AC_DEFUN([TEA_PATH_UNIX_X], [
     not_really_there=""
     if test "$no_x" = ""; then
 	if test "$x_includes" = ""; then
-	    AC_TRY_CPP([#include <X11/XIntrinsic.h>], , not_really_there="yes")
+	    AC_TRY_CPP([#include <X11/Xlib.h>], , not_really_there="yes")
 	else
-	    if test ! -r $x_includes/X11/Intrinsic.h; then
+	    if test ! -r $x_includes/X11/Xlib.h; then
 		not_really_there="yes"
 	    fi
 	fi
@@ -2261,11 +2424,11 @@ AC_DEFUN([TEA_PATH_UNIX_X], [
     if test "$no_x" = "yes" -o "$not_really_there" = "yes"; then
 	AC_MSG_CHECKING([for X11 header files])
 	found_xincludes="no"
-	AC_TRY_CPP([#include <X11/Intrinsic.h>], found_xincludes="yes", found_xincludes="no")
+	AC_TRY_CPP([#include <X11/Xlib.h>], found_xincludes="yes", found_xincludes="no")
 	if test "$found_xincludes" = "no"; then
 	    dirs="/usr/unsupported/include /usr/local/include /usr/X386/include /usr/X11R6/include /usr/X11R5/include /usr/include/X11R5 /usr/include/X11R4 /usr/openwin/include /usr/X11/include /usr/sww/include"
 	    for i in $dirs ; do
-		if test -r $i/X11/Intrinsic.h; then
+		if test -r $i/X11/Xlib.h; then
 		    AC_MSG_RESULT([$i])
 		    XINCLUDES=" -I$i"
 		    found_xincludes="yes"
@@ -2333,7 +2496,6 @@ AC_DEFUN([TEA_PATH_UNIX_X], [
 #		HAVE_SYS_FILIO_H
 #		USE_FIONBIO
 #		O_NONBLOCK
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_BLOCKING_STYLE], [
@@ -2368,7 +2530,6 @@ AC_DEFUN([TEA_BLOCKING_STYLE], [
 #		HAVE_TM_GMTOFF
 #		HAVE_TM_TZADJ
 #		HAVE_TIMEZONE_VAR
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_TIME_HANDLER], [
@@ -2437,7 +2598,6 @@ AC_DEFUN([TEA_TIME_HANDLER], [
 #
 #	Might defines some of the following vars:
 #		strtod (=fixstrtod)
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_BUGGY_STRTOD], [
@@ -2488,7 +2648,7 @@ AC_DEFUN([TEA_BUGGY_STRTOD], [
 #
 # Results:
 #
-#	Subst's the following var:
+#	Substitutes the following vars:
 #		TCL_LIBS
 #		MATH_LIBS
 #
@@ -2497,7 +2657,6 @@ AC_DEFUN([TEA_BUGGY_STRTOD], [
 #
 #	Might define the following vars:
 #		HAVE_NET_ERRNO_H
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_TCL_LINK_LIBS], [
@@ -2575,7 +2734,6 @@ AC_DEFUN([TEA_TCL_LINK_LIBS], [
 #		_ISOC99_SOURCE
 #		_LARGEFILE64_SOURCE
 #		_LARGEFILE_SOURCE64
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_TCL_EARLY_FLAG],[
@@ -2623,7 +2781,6 @@ AC_DEFUN([TEA_TCL_EARLY_FLAGS],[
 #		HAVE_STRUCT_DIRENT64
 #		HAVE_STRUCT_STAT64
 #		HAVE_TYPE_OFF64_T
-#
 #--------------------------------------------------------------------
 
 AC_DEFUN([TEA_TCL_64BIT_FLAGS], [
@@ -2655,7 +2812,7 @@ AC_DEFUN([TEA_TCL_64BIT_FLAGS], [
 	# Now check for auxiliary declarations
 	AC_CACHE_CHECK([for struct dirent64], tcl_cv_struct_dirent64,[
 	    AC_TRY_COMPILE([#include <sys/types.h>
-#include <sys/dirent.h>],[struct dirent64 p;],
+#include <dirent.h>],[struct dirent64 p;],
 		tcl_cv_struct_dirent64=yes,tcl_cv_struct_dirent64=no)])
 	if test "x${tcl_cv_struct_dirent64}" = "xyes" ; then
 	    AC_DEFINE(HAVE_STRUCT_DIRENT64, 1, [Is 'struct dirent64' in <sys/types.h>?])
@@ -2725,12 +2882,12 @@ AC_DEFUN([TEA_TCL_64BIT_FLAGS], [
 AC_DEFUN([TEA_INIT], [
     # TEA extensions pass this us the version of TEA they think they
     # are compatible with.
-    TEA_VERSION="3.9"
+    TEA_VERSION="3.10"
 
     AC_MSG_CHECKING([for correct TEA configuration])
     if test x"${PACKAGE_NAME}" = x ; then
 	AC_MSG_ERROR([
-The PACKAGE_NAME variable must be defined by your TEA configure.in])
+The PACKAGE_NAME variable must be defined by your TEA configure.ac])
     fi
     if test x"$1" = x ; then
 	AC_MSG_ERROR([
@@ -2740,21 +2897,36 @@ TEA version not specified.])
     else
 	AC_MSG_RESULT([ok (TEA ${TEA_VERSION})])
     fi
+
+    # If the user did not set CFLAGS, set it now to keep macros
+    # like AC_PROG_CC and AC_TRY_COMPILE from adding "-g -O2".
+    if test "${CFLAGS+set}" != "set" ; then
+	CFLAGS=""
+    fi
+
     case "`uname -s`" in
 	*win32*|*WIN32*|*MINGW32_*)
-	    AC_CHECK_PROG(CYGPATH, cygpath, cygpath -w, echo)
+	    AC_CHECK_PROG(CYGPATH, cygpath, cygpath -m, echo)
 	    EXEEXT=".exe"
 	    TEA_PLATFORM="windows"
 	    ;;
 	*CYGWIN_*)
-	    CYGPATH=echo
 	    EXEEXT=".exe"
-	    # TEA_PLATFORM is determined later in LOAD_TCLCONFIG
+	    # CYGPATH and TEA_PLATFORM are determined later in LOAD_TCLCONFIG
 	    ;;
 	*)
 	    CYGPATH=echo
-	    EXEEXT=""
-	    TEA_PLATFORM="unix"
+	    # Maybe we are cross-compiling....
+	    case ${host_alias} in
+		*mingw32*)
+		EXEEXT=".exe"
+		TEA_PLATFORM="windows"
+		;;
+	    *)
+		EXEEXT=""
+		TEA_PLATFORM="unix"
+		;;
+	    esac
 	    ;;
     esac
 
@@ -3061,7 +3233,7 @@ AC_DEFUN([TEA_PREFIX], [
 # TEA_SETUP_COMPILER_CC --
 #
 #	Do compiler checks the way we want.  This is just a replacement
-#	for AC_PROG_CC in TEA configure.in files to make them cleaner.
+#	for AC_PROG_CC in TEA configure.ac files to make them cleaner.
 #
 # Arguments:
 #	none
@@ -3074,16 +3246,22 @@ AC_DEFUN([TEA_SETUP_COMPILER_CC], [
     # Don't put any macros that use the compiler (e.g. AC_TRY_COMPILE)
     # in this macro, they need to go into TEA_SETUP_COMPILER instead.
 
-    # If the user did not set CFLAGS, set it now to keep
-    # the AC_PROG_CC macro from adding "-g -O2".
-    if test "${CFLAGS+set}" != "set" ; then
-	CFLAGS=""
-    fi
-
     AC_PROG_CC
     AC_PROG_CPP
 
-    AC_PROG_INSTALL
+    INSTALL='$(SHELL) $(srcdir)/tclconfig/install-sh -c'
+    INSTALL_DATA_DIR='${INSTALL} -d -m 755'
+    INSTALL_DATA='${INSTALL} -m 644'
+    INSTALL_PROGRAM='${INSTALL} -m 755 -s'
+    INSTALL_SCRIPT='${INSTALL} -m 755'
+    INSTALL_LIBRARY='${INSTALL_DATA}'
+
+    AC_SUBST(INSTALL)
+    AC_SUBST(INSTALL_DATA_DIR)
+    AC_SUBST(INSTALL_DATA)
+    AC_SUBST(INSTALL_PROGRAM)
+    AC_SUBST(INSTALL_SCRIPT)
+    AC_SUBST(INSTALL_LIBRARY)
 
     #--------------------------------------------------------------------
     # Checks to see if the make program sets the $MAKE variable.
@@ -3095,7 +3273,7 @@ AC_DEFUN([TEA_SETUP_COMPILER_CC], [
     # Find ranlib
     #--------------------------------------------------------------------
 
-    AC_PROG_RANLIB
+    AC_CHECK_TOOL(RANLIB, ranlib)
 
     #--------------------------------------------------------------------
     # Determines the correct binary file extension (.o, .obj, .exe etc.)
@@ -3176,92 +3354,128 @@ AC_DEFUN([TEA_SETUP_COMPILER], [
 #	MAKE_STUB_LIB	Makefile rule for building a stub library
 #	VC_MANIFEST_EMBED_DLL Makefile rule for embedded VC manifest in DLL
 #	VC_MANIFEST_EMBED_EXE Makefile rule for embedded VC manifest in EXE
+#
+# PRACTCL_TOOLSET     What toolset is in use (gcc or msvc)
+#	PRACTCL_SHARED_LIB	Template rule for building a shared library
+#	PRACTCL_STATIC_LIB	Template rule for building a static library
+#	PRACTCL_STUB_LIB	  Template rule for building a stub library
+# PRACTCL_VC_MANIFEST_EMBED_DLL Template rule for embedded VC manifest in DLL
+# PRACTCL_VC_MANIFEST_EMBED_EXE Template rule for embedded VC manifest in EXE
+# PRACTCL_NAME_LIBRARY Template rule for naming libraries
+# 
 #------------------------------------------------------------------------
 
 AC_DEFUN([TEA_MAKE_LIB], [
-    if test "${TEA_PLATFORM}" = "windows" -a "$GCC" != "yes"; then
-	MAKE_STATIC_LIB="\${STLIB_LD} -out:\[$]@ \$(PKG_OBJECTS)"
-	MAKE_SHARED_LIB="\${SHLIB_LD} \${SHLIB_LD_LIBS} \${LDFLAGS_DEFAULT} -out:\[$]@ \$(PKG_OBJECTS)"
-	AC_EGREP_CPP([manifest needed], [
+  PRACTCL_TOOLSET="gcc"
+	PRACTCL_VC_MANIFEST_EMBED_DLL=:
+	PRACTCL_VC_MANIFEST_EMBED_EXE=:
+  if test "${TEA_PLATFORM}" = "windows" -a "$GCC" != "yes"; then
+	  PRACTCL_TOOLSET="msvc"
+	  PRACTCL_STATIC_LIB="%STLIB_LD% -out:%OUTFILE% %LIBRARY_OBJECTS%"
+	  PRACTCL_SHARED_LIB="%SHLIB_LD% %SHLIB_LD_LIBS% %LDFLAGS_DEFAULT% -out:%OUTFILE% %LIBRARY_OBJECTS%"
+	  MAKE_STATIC_LIB="\${STLIB_LD} -out:\[$]@ \$(PKG_OBJECTS)"
+	  MAKE_SHARED_LIB="\${SHLIB_LD} \${SHLIB_LD_LIBS} \${LDFLAGS_DEFAULT} -out:\[$]@ \$(PKG_OBJECTS)"
+	  AC_EGREP_CPP([manifest needed], [
 #if defined(_MSC_VER) && _MSC_VER >= 1400
 print("manifest needed")
 #endif
-	], [
-	# Could do a CHECK_PROG for mt, but should always be with MSVC8+
-	VC_MANIFEST_EMBED_DLL="if test -f \[$]@.manifest ; then mt.exe -nologo -manifest \[$]@.manifest -outputresource:\[$]@\;2 ; fi"
-	VC_MANIFEST_EMBED_EXE="if test -f \[$]@.manifest ; then mt.exe -nologo -manifest \[$]@.manifest -outputresource:\[$]@\;1 ; fi"
-	MAKE_SHARED_LIB="${MAKE_SHARED_LIB} ; ${VC_MANIFEST_EMBED_DLL}"
-	TEA_ADD_CLEANFILES([*.manifest])
-	])
-	MAKE_STUB_LIB="\${STLIB_LD} -out:\[$]@ \$(PKG_STUB_OBJECTS)"
-    else
-	MAKE_STATIC_LIB="\${STLIB_LD} \[$]@ \$(PKG_OBJECTS)"
-	MAKE_SHARED_LIB="\${SHLIB_LD} -o \[$]@ \$(PKG_OBJECTS) \${SHLIB_LD_LIBS}"
-	MAKE_STUB_LIB="\${STLIB_LD} \[$]@ \$(PKG_STUB_OBJECTS)"
-    fi
-
-    if test "${SHARED_BUILD}" = "1" ; then
-	MAKE_LIB="${MAKE_SHARED_LIB} "
-    else
-	MAKE_LIB="${MAKE_STATIC_LIB} "
-    fi
+	  ], [
+	    # Could do a CHECK_PROG for mt, but should always be with MSVC8+
+	    PRACTCL_VC_MANIFEST_EMBED_DLL="mt.exe -nologo -manifest %OUTFILE%.manifest -outputresource:%OUTFILE%\;2"
+	    PRACTCL_VC_MANIFEST_EMBED_EXE="mt.exe -nologo -manifest %OUTFILE%.manifest -outputresource:%OUTFILE%\;1"
+	    VC_MANIFEST_EMBED_DLL="if test -f \[$]@.manifest ; then mt.exe -nologo -manifest \[$]@.manifest -outputresource:\[$]@\;2 ; fi"
+	    VC_MANIFEST_EMBED_EXE="if test -f \[$]@.manifest ; then mt.exe -nologo -manifest \[$]@.manifest -outputresource:\[$]@\;1 ; fi"
+	    MAKE_SHARED_LIB="${MAKE_SHARED_LIB} ; ${VC_MANIFEST_EMBED_DLL}"
+	    TEA_ADD_CLEANFILES([*.manifest])
+	  ])
+		PRACTCL_STUB_LIB="%STLIB_LD% -nodefaultlib -out:%OUTFILE% %LIBRARY_OBJECTS%"
+	  MAKE_STUB_LIB="\${STLIB_LD} -nodefaultlib -out:\[$]@ \$(PKG_STUB_OBJECTS)"
+  else
+	  MAKE_STATIC_LIB="\${STLIB_LD} \[$]@ \$(PKG_OBJECTS)"
+	  MAKE_SHARED_LIB="\${SHLIB_LD} -o \[$]@ \$(PKG_OBJECTS) \${SHLIB_LD_LIBS}"
+	  MAKE_STUB_LIB="\${STLIB_LD} \[$]@ \$(PKG_STUB_OBJECTS)"
+	
+	  PRACTCL_STATIC_LIB="%STLIB_LD% %OUTFILE% %LIBRARY_OBJECTS%"
+	  PRACTCL_SHARED_LIB="%SHLIB_LD% -o %OUTFILE% %LIBRARY_OBJECTS% %SHLIB_LD_LIBS%"
+    PRACTCL_STUB_LIB="%STLIB_LD% %OUTFILE% %LIBRARY_OBJECTS%"
+  fi
 
-    #--------------------------------------------------------------------
-    # Shared libraries and static libraries have different names.
-    # Use the double eval to make sure any variables in the suffix is
-    # substituted. (@@@ Might not be necessary anymore)
-    #--------------------------------------------------------------------
+  if test "${SHARED_BUILD}" = "1" ; then
+	  MAKE_LIB="${MAKE_SHARED_LIB} "
+  else
+	  MAKE_LIB="${MAKE_STATIC_LIB} "
+  fi
 
-    if test "${TEA_PLATFORM}" = "windows" ; then
-	if test "${SHARED_BUILD}" = "1" ; then
+  #--------------------------------------------------------------------
+  # Shared libraries and static libraries have different names.
+  # Use the double eval to make sure any variables in the suffix is
+  # substituted. (@@@ Might not be necessary anymore)
+  #--------------------------------------------------------------------
+  if test "${TEA_PLATFORM}" = "windows" ; then
+	  PRACTCL_NAME_LIBRARY="%LIBRARY_PREFIX%%LIBRARY_NAME%%LIBRARY_VERSION_NODOTS%"
+	  if test "${SHARED_BUILD}" = "1" ; then
 	    # We force the unresolved linking of symbols that are really in
 	    # the private libraries of Tcl and Tk.
-	    SHLIB_LD_LIBS="${SHLIB_LD_LIBS} \"`${CYGPATH} ${TCL_BIN_DIR}/${TCL_STUB_LIB_FILE}`\""
 	    if test x"${TK_BIN_DIR}" != x ; then
-		SHLIB_LD_LIBS="${SHLIB_LD_LIBS} \"`${CYGPATH} ${TK_BIN_DIR}/${TK_STUB_LIB_FILE}`\""
+			  SHLIB_LD_LIBS="${SHLIB_LD_LIBS} \"`${CYGPATH} ${TK_BIN_DIR}/${TK_STUB_LIB_FILE}`\""
 	    fi
-	    eval eval "PKG_LIB_FILE=${PACKAGE_NAME}${SHARED_LIB_SUFFIX}"
-	else
-	    eval eval "PKG_LIB_FILE=${PACKAGE_NAME}${UNSHARED_LIB_SUFFIX}"
-	fi
-	# Some packages build their own stubs libraries
-	eval eval "PKG_STUB_LIB_FILE=${PACKAGE_NAME}stub${UNSHARED_LIB_SUFFIX}"
-	if test "$GCC" = "yes"; then
-	    PKG_STUB_LIB_FILE=lib${PKG_STUB_LIB_FILE}
-	fi
-	# These aren't needed on Windows (either MSVC or gcc)
-	RANLIB=:
-	RANLIB_STUB=:
-    else
-	RANLIB_STUB="${RANLIB}"
-	if test "${SHARED_BUILD}" = "1" ; then
-	    SHLIB_LD_LIBS="${SHLIB_LD_LIBS} ${TCL_STUB_LIB_SPEC}"
-	    if test x"${TK_BIN_DIR}" != x ; then
-		SHLIB_LD_LIBS="${SHLIB_LD_LIBS} ${TK_STUB_LIB_SPEC}"
+	    SHLIB_LD_LIBS="${SHLIB_LD_LIBS} \"`${CYGPATH} ${TCL_BIN_DIR}/${TCL_STUB_LIB_FILE}`\""
+	    if test "$GCC" = "yes"; then
+        SHLIB_LD_LIBS="${SHLIB_LD_LIBS} -static-libgcc"
 	    fi
-	    eval eval "PKG_LIB_FILE=lib${PACKAGE_NAME}${SHARED_LIB_SUFFIX}"
-	    RANLIB=:
-	else
-	    eval eval "PKG_LIB_FILE=lib${PACKAGE_NAME}${UNSHARED_LIB_SUFFIX}"
-	fi
-	# Some packages build their own stubs libraries
-	eval eval "PKG_STUB_LIB_FILE=lib${PACKAGE_NAME}stub${UNSHARED_LIB_SUFFIX}"
+	    eval eval "PKG_LIB_FILE=${PACKAGE_LIB_PREFIX}${PACKAGE_NAME}${SHARED_LIB_SUFFIX}"
+	  else
+	    eval eval "PKG_LIB_FILE=${PACKAGE_LIB_PREFIX}${PACKAGE_NAME}${UNSHARED_LIB_SUFFIX}"
+	    if test "$GCC" = "yes"; then
+        PKG_LIB_FILE=lib${PKG_LIB_FILE}
+	    fi
+	  fi
+	  # Some packages build their own stubs libraries
+	  eval eval "PKG_STUB_LIB_FILE=${PACKAGE_LIB_PREFIX}${PACKAGE_NAME}stub${UNSHARED_LIB_SUFFIX}"
+    if test "$GCC" = "yes"; then
+      PKG_STUB_LIB_FILE=lib${PKG_STUB_LIB_FILE}
     fi
-
-    # These are escaped so that only CFLAGS is picked up at configure time.
-    # The other values will be substituted at make time.
-    CFLAGS="${CFLAGS} \${CFLAGS_DEFAULT} \${CFLAGS_WARNING}"
-    if test "${SHARED_BUILD}" = "1" ; then
-	CFLAGS="${CFLAGS} \${SHLIB_CFLAGS}"
+	  # These aren't needed on Windows (either MSVC or gcc)
+	  RANLIB=:
+	  RANLIB_STUB=:
+  else
+	  PRACTCL_NAME_LIBRARY="lib%LIBRARY_PREFIX%%LIBRARY_NAME%%LIBRARY_VERSION%"
+	  RANLIB_STUB="${RANLIB}"
+	  if test "${SHARED_BUILD}" = "1" ; then
+      SHLIB_LD_LIBS="${SHLIB_LD_LIBS} ${TCL_STUB_LIB_SPEC}"
+      if test x"${TK_BIN_DIR}" != x ; then
+        SHLIB_LD_LIBS="${SHLIB_LD_LIBS} ${TK_STUB_LIB_SPEC}"
+      fi
+      eval eval "PKG_LIB_FILE=lib${PACKAGE_LIB_PREFIX}${PACKAGE_NAME}${SHARED_LIB_SUFFIX}"
+      RANLIB=:
+    else
+      eval eval "PKG_LIB_FILE=lib${PACKAGE_LIB_PREFIX}${PACKAGE_NAME}${UNSHARED_LIB_SUFFIX}"
     fi
+    # Some packages build their own stubs libraries
+    eval eval "PKG_STUB_LIB_FILE=lib${PACKAGE_LIB_PREFIX}${PACKAGE_NAME}stub${UNSHARED_LIB_SUFFIX}"
+  fi
 
-    AC_SUBST(MAKE_LIB)
-    AC_SUBST(MAKE_SHARED_LIB)
-    AC_SUBST(MAKE_STATIC_LIB)
-    AC_SUBST(MAKE_STUB_LIB)
-    AC_SUBST(RANLIB_STUB)
-    AC_SUBST(VC_MANIFEST_EMBED_DLL)
-    AC_SUBST(VC_MANIFEST_EMBED_EXE)
+  # These are escaped so that only CFLAGS is picked up at configure time.
+  # The other values will be substituted at make time.
+  CFLAGS="${CFLAGS} \${CFLAGS_DEFAULT} \${CFLAGS_WARNING}"
+  if test "${SHARED_BUILD}" = "1" ; then
+    CFLAGS="${CFLAGS} \${SHLIB_CFLAGS}"
+  fi
+
+  AC_SUBST(MAKE_LIB)
+  AC_SUBST(MAKE_SHARED_LIB)
+  AC_SUBST(MAKE_STATIC_LIB)
+  AC_SUBST(MAKE_STUB_LIB)
+  AC_SUBST(RANLIB_STUB)
+  AC_SUBST(VC_MANIFEST_EMBED_DLL)
+  AC_SUBST(VC_MANIFEST_EMBED_EXE)
+  AC_SUBST(PRACTCL_TOOLSET)
+  AC_SUBST(PRACTCL_SHARED_LIB)
+  AC_SUBST(PRACTCL_STATIC_LIB)
+  AC_SUBST(PRACTCL_STUB_LIB)
+  AC_SUBST(PRACTCL_VC_MANIFEST_EMBED_DLL)
+  AC_SUBST(PRACTCL_VC_MANIFEST_EMBED_EXE)
+	AC_SUBST(PRACTCL_NAME_LIBRARY)
 ])
 
 #------------------------------------------------------------------------
@@ -3350,7 +3564,7 @@ AC_DEFUN([TEA_LIB_SPEC], [
 #
 # Results:
 #
-#	Substs the following vars:
+#	Substitutes the following vars:
 #		TCL_TOP_DIR_NATIVE
 #		TCL_INCLUDES
 #------------------------------------------------------------------------
@@ -3389,12 +3603,9 @@ AC_DEFUN([TEA_PRIVATE_TCL_HEADERS], [
             # the framework's Headers and PrivateHeaders directories
             case ${TCL_DEFS} in
 	    	*TCL_FRAMEWORK*)
-		    if test -d "${TCL_BIN_DIR}/Headers"; then
-			if test -d "${TCL_BIN_DIR}/PrivateHeaders"; then
-			    TCL_INCLUDES="-I\"${TCL_BIN_DIR}/Headers\" -I\"${TCL_BIN_DIR}/PrivateHeaders\" ${TCL_INCLUDES}"
-			elif test -d "${TCL_BIN_DIR}/Headers/tcl-private"; then
-			    TCL_INCLUDES="-I\"${TCL_BIN_DIR}/Headers\" -I\"${TCL_BIN_DIR}/Headers/tcl-private\" ${TCL_INCLUDES}"
-			fi
+		    if test -d "${TCL_BIN_DIR}/Headers" -a \
+			    -d "${TCL_BIN_DIR}/PrivateHeaders"; then
+			TCL_INCLUDES="-I\"${TCL_BIN_DIR}/Headers\" -I\"${TCL_BIN_DIR}/PrivateHeaders\" ${TCL_INCLUDES}"
 		    else
 			TCL_INCLUDES="${TCL_INCLUDES} ${TCL_INCLUDE_SPEC} `echo "${TCL_INCLUDE_SPEC}" | sed -e 's/Headers/PrivateHeaders/'`"
 		    fi
@@ -3431,7 +3642,7 @@ AC_DEFUN([TEA_PRIVATE_TCL_HEADERS], [
 #	Adds a --with-tclinclude switch to configure.
 #	Result is cached.
 #
-#	Substs the following vars:
+#	Substitutes the following vars:
 #		TCL_INCLUDES
 #------------------------------------------------------------------------
 
@@ -3521,7 +3732,7 @@ AC_DEFUN([TEA_PUBLIC_TCL_HEADERS], [
 #
 # Results:
 #
-#	Substs the following vars:
+#	Substitutes the following vars:
 #		TK_INCLUDES
 #------------------------------------------------------------------------
 
@@ -3610,7 +3821,7 @@ AC_DEFUN([TEA_PRIVATE_TK_HEADERS], [
 #	Adds a --with-tkinclude switch to configure.
 #	Result is cached.
 #
-#	Substs the following vars:
+#	Substitutes the following vars:
 #		TK_INCLUDES
 #------------------------------------------------------------------------
 
@@ -3828,11 +4039,10 @@ AC_DEFUN([TEA_PATH_CONFIG], [
 #
 # Results:
 #
-#	Subst the following vars:
+#	Substitutes the following vars:
 #		$1_SRC_DIR
 #		$1_LIB_FILE
 #		$1_LIB_SPEC
-#
 #------------------------------------------------------------------------
 
 AC_DEFUN([TEA_LOAD_CONFIG], [
@@ -3893,7 +4103,6 @@ AC_DEFUN([TEA_LOAD_CONFIG], [
 #
 # Results:
 #	Adds to LIBS the appropriate extension library
-#
 #------------------------------------------------------------------------
 AC_DEFUN([TEA_LOAD_CONFIG_LIB], [
     AC_MSG_CHECKING([For $1 library for LIBS])
@@ -3925,8 +4134,7 @@ AC_DEFUN([TEA_LOAD_CONFIG_LIB], [
 #		$1
 #
 # Results:
-#	Subst the following vars:
-#
+#	Substitutes the following vars:
 #------------------------------------------------------------------------
 
 AC_DEFUN([TEA_EXPORT_CONFIG], [
@@ -3943,12 +4151,12 @@ AC_DEFUN([TEA_EXPORT_CONFIG], [
 	eval $1_LIB_FLAG="-l$1`echo ${PACKAGE_VERSION} | tr -d .`${DBGX}"
 	eval $1_STUB_LIB_FLAG="-l$1stub`echo ${PACKAGE_VERSION} | tr -d .`${DBGX}"
     fi
-    $1_BUILD_LIB_SPEC="-L`pwd` ${$1_LIB_FLAG}"
-    $1_LIB_SPEC="-L${pkglibdir} ${$1_LIB_FLAG}"
-    $1_BUILD_STUB_LIB_SPEC="-L`pwd` [$]{$1_STUB_LIB_FLAG}"
-    $1_STUB_LIB_SPEC="-L${pkglibdir} [$]{$1_STUB_LIB_FLAG}"
-    $1_BUILD_STUB_LIB_PATH="`pwd`/[$]{PKG_STUB_LIB_FILE}"
-    $1_STUB_LIB_PATH="${pkglibdir}/[$]{PKG_STUB_LIB_FILE}"
+    $1_BUILD_LIB_SPEC="-L`$CYGPATH $(pwd)` ${$1_LIB_FLAG}"
+    $1_LIB_SPEC="-L`$CYGPATH ${pkglibdir}` ${$1_LIB_FLAG}"
+    $1_BUILD_STUB_LIB_SPEC="-L`$CYGPATH $(pwd)` [$]{$1_STUB_LIB_FLAG}"
+    $1_STUB_LIB_SPEC="-L`$CYGPATH ${pkglibdir}` [$]{$1_STUB_LIB_FLAG}"
+    $1_BUILD_STUB_LIB_PATH="`$CYGPATH $(pwd)`/[$]{PKG_STUB_LIB_FILE}"
+    $1_STUB_LIB_PATH="`$CYGPATH ${pkglibdir}`/[$]{PKG_STUB_LIB_FILE}"
 
     AC_SUBST($1_BUILD_LIB_SPEC)
     AC_SUBST($1_LIB_SPEC)
@@ -4029,8 +4237,6 @@ AC_DEFUN([TEA_PATH_CELIB], [
 	fi
     fi
 ])
-
-
 # Local Variables:
 # mode: autoconf
 # End:
