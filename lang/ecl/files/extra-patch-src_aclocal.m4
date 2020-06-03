--- src/aclocal.m4.orig	2016-12-19 10:25:00 UTC
+++ src/aclocal.m4
@@ -231,6 +231,8 @@ AC_SUBST(LIBPREFIX)dnl	Name components of a statically
 AC_SUBST(LIBEXT)
 AC_SUBST(SHAREDEXT)dnl	Name components of a dynamically linked library
 AC_SUBST(SHAREDPREFIX)
+AC_SUBST(IMPLIB_EXT)dnl	Name components of a dynamically linked library import file - borrowed from SageMath
+AC_SUBST(IMPLIB_PREFIX)
 AC_SUBST(OBJEXT)dnl	These are set by autoconf
 AC_SUBST(EXEEXT)
 AC_SUBST(INSTALL_TARGET)dnl Which type of installation: flat directory or unix like.
@@ -240,6 +242,8 @@ ECL_GC_DIR=bdwgc
 ECL_LDRPATH=''
 SHAREDEXT='so'
 SHAREDPREFIX='lib'
+IMPLIB_EXT=''
+IMPLIB_PREFIX=''
 LIBPREFIX='lib'
 LIBEXT='a'
 PICFLAG='-fPIC'
@@ -251,6 +255,8 @@ THREAD_OBJ="$THREAD_OBJ c/threads/process c/threads/qu
 clibs='-lm'
 SONAME=''
 SONAME_LDFLAGS=''
+IMPLIB_NAME=''
+IMPLIB_LDFLAGS=''
 case "${host_os}" in
         linux-androideabi)
                 thehost='android'
@@ -366,10 +372,14 @@ case "${host_os}" in
                 shared='yes'
                 THREAD_CFLAGS='-D_THREAD_SAFE'
                 THREAD_LIBS='-lpthread'
-                SHARED_LDFLAGS="-shared ${LDFLAGS}"
-                BUNDLE_LDFLAGS="-shared ${LDFLAGS}"
-                SHAREDPREFIX=''
+                SHARED_LDFLAGS="-shared -Wl,--enable-auto-image-base ${LDFLAGS}"
+                BUNDLE_LDFLAGS="-shared -Wl,--enable-auto-image-base ${LDFLAGS}"
+                SHAREDPREFIX='cyg'
                 SHAREDEXT='dll'
+                IMPLIB_PREFIX='lib'
+                IMPLIB_EXT='dll.a'
+                IMPLIB_NAME="${IMPLIB_PREFIX}ecl.${IMPLIB_EXT}"
+                IMPLIB_LDFLAGS="-Wl,--out-implib,${IMPLIB_NAME}"
                 PICFLAG=''
                 if test "x$host_cpu" = "xx86_64" ; then
                    # Our GMP library is too old and does not support
@@ -387,10 +397,14 @@ case "${host_os}" in
                 enable_threads='yes'
                 THREAD_CFLAGS='-D_THREAD_SAFE'
                 THREAD_GC_FLAGS='--enable-threads=win32'
-                SHARED_LDFLAGS=''
-                BUNDLE_LDFLAGS=''
+                SHARED_LDFLAGS="-shared -Wl,--enable-auto-image-base ${LDFLAGS}"
+                BUNDLE_LDFLAGS="-shared -Wl,--enable-auto-image-base ${LDFLAGS}"
                 SHAREDPREFIX=''
                 SHAREDEXT='dll'
+                IMPLIB_PREFIX='lib'
+                IMPLIB_EXT='dll.a'
+                IMPLIB_NAME="${IMPLIB_PREFIX}ecl.${IMPLIB_EXT}"
+                IMPLIB_LDFLAGS="-Wl,--out-implib,${IMPLIB_NAME}"
                 PICFLAG=''
                 INSTALL_TARGET='flatinstall'
                 TCPLIBS='-lws2_32'
