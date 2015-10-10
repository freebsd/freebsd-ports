--- bakefile-0.2.9/autoconf/bakefile.m4.orig	2011-02-02 15:06:48 UTC
+++ bakefile-0.2.9/autoconf/bakefile.m4
@@ -444,6 +444,7 @@ AC_DEFUN([AC_BAKEFILE_SHARED_LD],
 
       powerpc-apple-macos* | \
       *-*-freebsd* | *-*-openbsd* | *-*-netbsd* | *-*-k*bsd*-gnu | \
+      *-*-dragonfly* | \
       *-*-mirbsd* | \
       *-*-sunos4* | \
       *-*-osf* | \
@@ -495,6 +496,7 @@ AC_DEFUN([AC_BAKEFILE_SHARED_VERSIONS],
 
     case "${BAKEFILE_HOST}" in
       *-*-linux* | *-*-freebsd* | *-*-openbsd* | *-*-netbsd* | \
+      *-*-dragonfly* | \
       *-*-k*bsd*-gnu | *-*-mirbsd* )
         if test "x$SUNCXX" = "xyes"; then
             SONAME_FLAG="-h "
