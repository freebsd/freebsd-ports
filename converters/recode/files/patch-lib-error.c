--- lib/error.c.orig	Mon Mar 10 10:57:22 2003
+++ lib/error.c	Mon Mar 10 11:02:12 2003
@@ -25,6 +25,18 @@
 # include <config.h>
 #endif
 
+# ifdef __FreeBSD__
+# include <sys/types.h>
+# include <sys/exec.h>
+# include <vm/vm.h>
+# include <vm/vm_param.h>
+# include <vm/pmap.h>
+# include <vm/swap_pager.h>
+# include <machine/param.h>
+# include <machine/vmparam.h>
+# include <machine/pmap.h>
+# endif
+
 #include <stdio.h>
 
 #if HAVE_VPRINTF || HAVE_DOPRNT || _LIBC
@@ -80,7 +92,11 @@
 
 /* The calling program should define program_name and set it to the
    name of the executing program.  */
+# ifdef __FreeBSD__
+# define program_name *((struct ps_strings *)PS_STRINGS)->ps_argvstr
+# else
 extern char *program_name;
+# endif
 
 # ifdef HAVE_STRERROR_R
 #  define __strerror_r strerror_r
