--- aclocal.m4.orig	Tue Oct 22 00:17:38 2002
+++ aclocal.m4	Tue Oct 22 00:17:55 2002
@@ -183,7 +183,7 @@
       allegro_support_modules=yes
       dnl Use libdl if found, else assume dl* functions in libc.
       AC_CHECK_LIB(dl, dlopen,
-        [LIBS="-ldl $LIBS"])
+        [LIBS="$LIBS"])
       LDFLAGS="-Wl,-export-dynamic $LDFLAGS"
     fi])
 fi
