--- m4/audacity_checklib_libsndfile.m4.orig	2016-01-08 22:05:48 UTC
+++ m4/audacity_checklib_libsndfile.m4
@@ -50,6 +50,7 @@ AC_DEFUN([AUDACITY_CONFIG_LIBSNDFILE], [
       SNDFILE_LIBS='$(top_builddir)/lib-src/libsndfile/src/.libs/libsndfile.a'
       AC_CONFIG_SUBDIRS([lib-src/libsndfile])
    fi
+   export SNDFILE_CFLAGS
 
    AC_SUBST([SNDFILE_CFLAGS])
    AC_SUBST([SNDFILE_LIBS])
