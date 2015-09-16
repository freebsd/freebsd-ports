--- aclocal.m4.orig	2009-05-17 12:27:34 UTC
+++ aclocal.m4
@@ -175,41 +175,6 @@ if test $[{HAS_PORTAUDIO_H}] -eq 1 -a $[
 	else
 		HAS_PORTAUDIO=1
 	fi
-else
-	AC_MSG_RESULT([portaudio not found trying FreeBSD paths ])
-	portaudio_lib_dir="/usr/local/lib/portaudio2"
-	portaudio_include_dir="/usr/local/include/portaudio2"
-dnl
-dnl Try again to make sure portaudio dirs are valid
-dnl
-	AC_MSG_CHECKING([for a v19 portaudio in FreeBSD paths.])
-	HAS_PORTAUDIO_H=0
-	HAS_PORTAUDIO_LIB=0
-
-	if test -e $[{portaudio_include_dir}]/portaudio.h; then
-		HAS_PORTAUDIO_H=1
-	fi
-
-	if test -e $[{portaudio_lib_dir}]/libportaudio.so \
-	    -o -e $[{portaudio_lib_dir}]/libportaudio.a;then
-		HAS_PORTAUDIO_LIB=1
-	fi
-
-	if test $[{HAS_PORTAUDIO_H}] -eq 1 -a $[{HAS_PORTAUDIO_LIB}] -eq 1; then
-		AC_MSG_RESULT([found portaudio in FreeBSD paths, double checking it is v19 ])
-		LDFLAGS="-L$[{portaudio_lib_dir}] $[{LDFLAGS}]"
-		LIBS="$[{LIBS}] -lportaudio"
-		CPPFLAGS="-I$[{portaudio_include_dir}] $[{CPPFLAGS}]"
-		AC_CHECK_LIB(portaudio, Pa_GetVersion, \
-			[HAS_PORTAUDIO_VERSION=1], [HAS_PORTAUDIO_VERSION=0])
-		if test $[{HAS_PORTAUDIO_VERSION}] -eq 0; then
-			AC_MSG_RESULT([How did you end up with a portaudio v18 here?])
-		else
-			AC_MSG_RESULT([found v19])
-			HAS_PORTAUDIO=1
-			HAS_PORTAUDIO_H=1
-		fi
-	fi
 fi
 
 ])dnl }}}
