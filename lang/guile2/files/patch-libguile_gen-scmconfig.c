--- libguile/gen-scmconfig.c.orig	2016-06-17 09:37:10 UTC
+++ libguile/gen-scmconfig.c
@@ -138,6 +138,7 @@
 
 #include <libguile/gen-scmconfig.h>
 
+#define _ANSI_SOURCE
 #include <stdio.h>
 #include <string.h>
 
@@ -382,6 +383,10 @@ main (int argc, char *argv[])
   pf ("typedef int scm_t_off;\n");
   pf ("#define SCM_T_OFF_MAX INT_MAX\n");
   pf ("#define SCM_T_OFF_MIN INT_MIN\n");
+#elif SIZEOF_OFF_T == SIZEOF_LONG_LONG && SIZEOF_OFF_T != SIZEOF_LONG
+  pf ("typedef long long int scm_t_off;\n");
+  pf ("#define SCM_T_OFF_MAX LLONG_MAX\n");
+  pf ("#define SCM_T_OFF_MIN LLONG_MIN\n");
 #else
   pf ("typedef long int scm_t_off;\n");
   pf ("#define SCM_T_OFF_MAX LONG_MAX\n");
