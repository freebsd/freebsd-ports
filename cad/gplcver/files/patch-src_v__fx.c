--- src/v_fx.c.orig	2007-05-30 15:24:38 UTC
+++ src/v_fx.c
@@ -37,7 +37,7 @@
 
 #include <sys/types.h>
 
-#if defined(__SVR4) || defined(__hpux) || defined(__CYGWIN32__)
+#if defined(__SVR4) || defined(__hpux) || defined(__CYGWIN32__) || defined(__FreeBSD__)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -798,7 +798,7 @@ static void bld_ylb_dirfiles(struct vylib_t *vyp)
  register int32 last_fi;
  register int32 numdfils, siz_mydir, bytlen, obytlen;
  DIR *dirp;
-#if defined(__SVR4) || defined(__hpux) || defined(__CYGWIN32__)
+#if defined(__SVR4) || defined(__hpux) || defined(__CYGWIN32__) || defined(__FreeBSD__)
  struct dirent *dp;
 #else
  /* all BSD cases and special case interface for non unices */
