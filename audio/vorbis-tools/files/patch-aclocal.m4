$FreeBSD$
--- aclocal.m4.orig	Mon Feb 26 06:51:03 2001
+++ aclocal.m4	Wed Mar 21 15:31:39 2001
@@ -222,7 +222,7 @@
     AO_LIBS="-L$ao_prefix/lib"
   fi
 
-  AO_LIBS="$AO_LIBS -lao -ldl"
+  AO_LIBS="$AO_LIBS -lao"
 
   AC_MSG_CHECKING(for ao)
   no_ao=""
@@ -293,6 +293,68 @@
   rm -f conf.aotest
 ])
 
+dnl Shamelessly stolen from Joerg Schilling's star.
+dnl Copyright 1998 J. Schilling
+
+dnl Checks if mmap() works to get shared memory
+dnl Defines HAVE_SMMAP on success.
+AC_DEFUN(AC_FUNC_SMMAP,
+[AC_CACHE_CHECK([if mmap works to get shared memory], ac_cv_func_smmap,
+                [AC_TRY_RUN([
+#include <sys/types.h>
+#include <sys/mman.h>
+
+char *
+mkshare()
+{
+        int     size = 8192;
+        int     f;
+        char    *addr;
+
+        if ((f = open("/dev/zero", 2)) < 0)
+                exit(1);
+        addr = mmap(0, size, PROT_READ|PROT_WRITE, MAP_SHARED, f, 0);
+        if (addr == (char *)-1)
+                exit(1);
+        close(f);
+
+        return (addr);
+}
+
+main()
+{
+        char    *addr;
+        
+        addr = mkshare(8192);
+        *addr = 'I';
+
+        switch (fork()) {
+
+        case -1:
+                printf("help\n"); exit(1);
+
+        case 0: /* child */
+                *addr = 'N';
+                _exit(0);
+                break;
+        default: /* parent */
+                wait(0);
+                sleep(1);
+                break;
+        }
+
+        if (*addr != 'N')
+                exit(1);
+        exit(0);
+}
+], 
+                [ac_cv_func_smmap=yes],
+                [ac_cv_func_smmap=no],
+                [ac_cv_func_smmap=no])])
+if test $ac_cv_func_smmap = yes; then
+  AC_DEFINE(HAVE_SMMAP)
+fi])
+
 # Do all the work for Automake.  This macro actually does too much --
 # some checks are only needed if your package does certain things.
 # But this isn't really a big deal.
@@ -398,15 +460,15 @@
 LD="$LD" LDFLAGS="$LDFLAGS" LIBS="$LIBS" \
 LN_S="$LN_S" NM="$NM" RANLIB="$RANLIB" \
 DLLTOOL="$DLLTOOL" AS="$AS" OBJDUMP="$OBJDUMP" \
-${CONFIG_SHELL-/bin/sh} $ac_aux_dir/ltconfig --no-reexec \
-$libtool_flags --no-verify $ac_aux_dir/ltmain.sh $lt_target \
+${CONFIG_SHELL-/bin/sh} /usr/local/share/libtool/ltconfig --no-reexec \
+$libtool_flags --no-verify --disable-ltlibs /usr/local/share/libtool/ltmain.sh $lt_target \
 || AC_MSG_ERROR([libtool configure failed])
 
 # Reload cache, that may have been modified by ltconfig
 AC_CACHE_LOAD
 
 # This can be used to rebuild libtool when needed
-LIBTOOL_DEPS="$ac_aux_dir/ltconfig $ac_aux_dir/ltmain.sh"
+LIBTOOL_DEPS="/usr/local/share/libtool/ltconfig --disable-ltlibs /usr/local/share/libtool/ltmain.sh"
 
 # Always use our own libtool.
 LIBTOOL='$(SHELL) $(top_builddir)/libtool'
