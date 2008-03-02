--- src/include/glame_guile_compat.h.orig	2008-03-02 13:59:02.000000000 -0500
+++ src/include/glame_guile_compat.h	2008-03-02 13:59:41.000000000 -0500
@@ -32,58 +32,10 @@
 
 #include <libguile.h>
 
-#ifdef SCM_MAJOR_VERSION
-/* this works because Guile 1.4 doesn't define SCM_MAJOR_VERSION */
-
-#define NEW_GUILE 1
-
 /* Glame wrapper functions: */
-#if (SCM_MINOR_VERSION < 7)
-/* use GLAME_NEWCELL instead of SCM_NEWCELL */
-#define GLAME_NEWCELL(z) SCM_NEWCELL(z)
-#endif
 #define glame_scm2newstr(obj, lenp) gh_scm2newstr (obj, lenp)
 #define glame_scm2long(obj) scm_num2long (obj, SCM_ARG1, "somewhere")
 #define glame_scm2double(obj) scm_num2dbl (obj, "somewhere")
 #define scm_str2string(str) gh_str02scm (str)
 
-#if (SCM_MINOR_VERSION == 7)
-#define GLAME_NEWCELL(z) z = scm_cell (SCM_UNPACK(z), 0)
-#endif
-
-#else /* Guile 1.4.x */
-
-#include <guile/gh.h>
-
-#define NEW_GUILE 0
-#define SCM_MAJOR_VERSION 1
-#define SCM_MINOR_VERSION 4
-#define SCM_MICRO_VERSION 0
-
-/* Glame wrapper functions: */
-#define GLAME_NEWCELL(z) SCM_NEWCELL(z)
-#define glame_scm2newstr(obj, lenp) gh_scm2newstr (obj, lenp)
-#define glame_scm2long(obj) gh_scm2long (obj)
-#define glame_scm2double(obj) gh_scm2double (obj)
-
-/* 1.6 compat stuff: (make guile 1.4 use the 1.6 api) */
-/* If a function cannot be easily defined in terms of a 1.4
-   function, then write a glame wrapper or reimplement the
-   version from Guile 1.6 using internal 1.4 stuff...
-   if stuff in here gets too large, maybe a glame_guile_compat.c
-   should be written 
-*/
-
-#define scm_c_define_gsubr(func_name, req, opt, rest, func) gh_new_procedure(func_name, func, req, opt, rest)
-#define scm_c_export(sym, ...) /* nothing */
-#define scm_c_define(sym, val) gh_define (sym, val)
-#define scm_long2num(num) gh_long2scm (num)
-#define scm_double2num(num) gh_double2scm (num)
-#define scm_cons(a, b) gh_cons (a, b)
-#define scm_makfrom0str(str) gh_str02scm (str)
-#define scm_str2string(str) gh_str02scm (str)
-
-/* types */
-#define scm_t_port scm_port
-#endif /* defined SCM_MAJOR_VERSION */
 #endif /* GLAME_GUILE_COMPAT_H */
