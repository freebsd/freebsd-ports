--- PDP11/pdp11_cpumod.c.orig	2016-12-01 22:43:42 UTC
+++ PDP11/pdp11_cpumod.c
@@ -1075,7 +1075,7 @@ t_stat r;
 for (i = 0; cnf_tab[i].dib != NULL; i++) {              /* loop thru config tab */
     if (((cnf_tab[i].cpum == 0) || (cpu_type & cnf_tab[i].cpum)) &&
         ((cnf_tab[i].optm == 0) || (cpu_opt & cnf_tab[i].optm))) {
-        if (r = build_ubus_tab (&cpu_dev, cnf_tab[i].dib)) /* add to dispatch tab */
+        if ((r = build_ubus_tab (&cpu_dev, cnf_tab[i].dib))) /* add to dispatch tab */
              return r;
         }
     }
