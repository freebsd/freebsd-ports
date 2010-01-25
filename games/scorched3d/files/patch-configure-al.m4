--- configure-al.m4.orig	2009-12-26 18:48:59.000000000 +0100
+++ configure-al.m4	2009-12-26 18:50:56.000000000 +0100
@@ -7,25 +7,9 @@
 	[  --disable-openaltest    Do not try to compile and run a test OpenAL program],
 		    , enable_openaltest=yes)
 AC_MSG_CHECKING(for OpenAL support)
-AC_PATH_PROG(OPENAL_CONFIG, openal-config, no)
-if test x$OPENAL_CONFIG = xno; then
-	echo "*** The openal-config script installed by OpenAL could not be found"
-	echo "*** Make sure openal-config is in your path, or set the OPENAL_CONFIG"
-	echo "*** environment variable to the full path to openal-config."
-
-	AC_MSG_ERROR([*** Can't find the openal library. Try: http://www.openal.org/])
-else
-
-	if test x"$use_static_openal" = x"yes"; then
-		AL_LIBS="/usr/local/lib/libopenal.a"
-	else
-		AL_LIBS="`$OPENAL_CONFIG --libs`"
-	fi
-	
-	AL_CFLAGS="`$OPENAL_CONFIG --cflags`"
-
-	AC_MSG_RESULT(yes)
-fi
+AL_LIBS="`pkg-config --libs openal`"
+AL_CFLAGS="`pkg-config --cflags openal`"
+AC_MSG_RESULT(yes)
 
 AC_MSG_CHECKING(for Freealut support)
 AC_PATH_PROG(FREEALUT_CONFIG, freealut-config, no)
