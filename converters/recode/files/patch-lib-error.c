--- lib/error.c.orig	Thu Aug  3 03:21:13 2000
+++ lib/error.c	Thu Apr 17 00:29:29 2003
@@ -25,6 +25,16 @@
 # include <config.h>
 #endif
 
+# ifdef __FreeBSD__
+# include <sys/types.h>
+# include <sys/exec.h>
+# include <sys/param.h>
+# include <vm/vm.h>
+# include <vm/vm_param.h>
+# include <vm/pmap.h>
+# include <vm/swap_pager.h>
+# endif
+
 #include <stdio.h>
 
 #if HAVE_VPRINTF || HAVE_DOPRNT || _LIBC
@@ -80,7 +90,11 @@
 
 /* The calling program should define program_name and set it to the
    name of the executing program.  */
+# ifdef __FreeBSD__
+# define program_name *((struct ps_strings *)PS_STRINGS)->ps_argvstr
+# else
 extern char *program_name;
+# endif
 
 # ifdef HAVE_STRERROR_R
 #  define __strerror_r strerror_r
