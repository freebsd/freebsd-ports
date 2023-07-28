--- libguile/gen-scmconfig.c.orig	2021-03-09 19:24:59 UTC
+++ libguile/gen-scmconfig.c
@@ -343,6 +343,10 @@ main (int argc, char *argv[])
   pf ("typedef int scm_t_off;\n");
   pf ("#define SCM_T_OFF_MAX INT_MAX\n");
   pf ("#define SCM_T_OFF_MIN INT_MIN\n");
+#elif SIZEOF_OFF_T == SIZEOF_LONG_LONG
+  pf ("typedef long long int scm_t_off;\n");
+  pf ("#define SCM_T_OFF_MAX LLONG_MAX\n");
+  pf ("#define SCM_T_OFF_MIN LLONG_MIN\n");
 #else
   pf ("typedef long int scm_t_off;\n");
   pf ("#define SCM_T_OFF_MAX LONG_MAX\n");
