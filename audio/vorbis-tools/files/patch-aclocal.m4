$FreeBSD$
--- aclocal.m4.orig	Mon Jun 18 06:43:11 2001
+++ aclocal.m4	Tue Jul 17 01:38:36 2001
@@ -313,6 +313,68 @@ int main ()
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
