--- slibu.c.orig	Mon Dec  1 19:16:38 1997
+++ slibu.c	Thu Jan  6 15:04:04 2000
@@ -20,6 +20,10 @@
 #include <errno.h>
 #include <stdarg.h>
 
+#if defined(HAVE_SYS_PARAM_H)
+#include <sys/param.h>
+#endif
+
 #if defined(unix)
 #include <unistd.h>
 #include <dirent.h>
@@ -50,7 +54,7 @@
 #include <dl.h>
 #endif
 
-#if defined(__osf__) || defined(sun) || defined(linux) || defined(sgi)
+#if defined(__osf__) || defined(sun) || defined(linux) || defined(sgi) || defined(BSD)
 #include <dlfcn.h>
 #endif
 
@@ -288,6 +292,7 @@
  return(NIL);}
 #endif
 
+#if !defined(BSD)
 LISP lputpwent(LISP alist,LISP file)
 {int iflag = no_interrupt(1);
  int status;
@@ -296,6 +301,7 @@
  status = putpwent(&p,get_c_file(file,NULL));
  no_interrupt(iflag);
  return(NIL);}
+#endif
 
 LISP laccess_problem(LISP lfname,LISP lacc)
 {char *fname = get_c_string(lfname);
@@ -1021,7 +1027,7 @@
 
 #if defined(unix) || defined(WIN32)
 
-LISP lchmod(LISP path,LISP mode)
+LISP l_chmod(LISP path,LISP mode)
 {if (chmod(get_c_string(path),get_c_long(mode)))
    return(err("chmod",llast_c_errmsg(-1)));
  else
@@ -1029,6 +1035,15 @@
 
 #endif
 
+#if defined(unix) || defined(WIN32)
+
+LISP l_lchmod(LISP path,LISP mode)
+{if (lchmod(get_c_string(path),get_c_long(mode)))
+   return(err("lchmod",llast_c_errmsg(-1)));
+ else
+   return(NIL);}
+
+#endif
 
 #ifdef unix
 
@@ -1554,7 +1569,7 @@
      /* note: error cases can leak memory in this procedure. */
 {LISP init_name;
  void (*fcn)(void) = NULL;
-#if defined(__osf__) || defined(sun) || defined(linux) || defined(sgi)
+#if defined(__osf__) || defined(sun) || defined(linux) || defined(sgi) || defined(BSD)
  void *handle;
 #endif
 #if defined(hpux)
@@ -1575,7 +1590,7 @@
    {put_st("so-loading ");
     put_st(get_c_string(fname));
     put_st("\n");}
-#if defined(__osf__) || defined(sun) || defined(linux) || defined(sgi)
+#if defined(__osf__) || defined(sun) || defined(linux) || defined(sgi) || defined(BSD)
 #if !defined(__osf__)
  /* Observed bug: values of LD_LIBRARY_PATH established with putenv
     -after- a process has started are ignored. Work around follows. */
@@ -2163,7 +2178,8 @@
 	      opendir_gc_free,
 	      &j);
  set_print_hooks(tc_opendir,opendir_prin1);
- init_subr_2("chmod",lchmod);
+ init_subr_2("chmod",l_chmod);
+ init_subr_2("lchmod",l_lchmod);
 #endif
 
  gc_protect_sym(&sym_channels,"*channels*");
@@ -2197,7 +2213,9 @@
 #if defined(__osf__)
  init_subr_1("setpwfile",lsetpwfile);
 #endif
+#if !defined(BSD)
  init_subr_2("putpwent",lputpwent);
+#endif
  init_subr_2("access-problem?",laccess_problem);
  init_subr_3("utime",lutime);
  init_subr_2("fchmod",lfchmod);
