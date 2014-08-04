--- aclocal.m4.orig	2014-07-28 21:23:20.000000000 -0400
+++ aclocal.m4	2014-07-28 21:26:51.000000000 -0400
@@ -212,4 +212,7 @@
 	fi
 fi
 
+AC_SUBST([PORTAUDIO_INCLUDE], ["-I${portaudio_include_dir}"])
+AC_SUBST([PORTAUDIO_LIBDIR], ["-L${portaudio_lib_dir}"])
+
 ])dnl }}}
