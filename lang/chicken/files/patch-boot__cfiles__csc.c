--- boot/cfiles/csc.c   Wed Sep 27 19:43:04 2006
+++ csc.c       Wed Dec  6 11:44:51 2006
@@ -1,7 +1,7 @@
 /* Generated from csc.scm by the Chicken compiler
-   2006-09-27 11:43
-   Version 2.434 - linux-unix-gnu-x86 - [ libffi dload ptables applyhook ]
-   command line: csc.scm -output-file csc.c -quiet -no-trace -optimize-level 2 -include-path .
+   2006-12-06 11:44
+   Version 2.5 - freebsd-unix-gnu-x86 - [ dload ptables applyhook ]
+   command line: csc.scm -quiet -no-trace -optimize-level 2 -include-path . -output-file csc.c
    used units: library eval extras extras srfi_1 srfi_13 regex utils
    default heap size: 0
    default nursery (stack) size: 131072
@@ -976,9 +976,9 @@
 C_save(t1);
 C_reclaim((void*)toplevel_trampoline,NULL);}
 toplevel_initialized=1;
-if(!C_demand_2(2418)){
+if(!C_demand_2(2415)){
 C_save(t1);
-C_rereclaim2(2418*sizeof(C_word), 1);
+C_rereclaim2(2415*sizeof(C_word), 1);
 t1=C_restore;}
 a=C_alloc(3);
 C_initialize_lf(lf,411);
@@ -1006,12 +1006,10 @@
 lf[48]=C_h_pair(C_restore,tmp);
 tmp=C_static_string(C_heaptop,12,"/usr/include");
 C_save(tmp);
-tmp=C_static_string(C_heaptop,18,"/usr/local/include");
-C_save(tmp);
 tmp=C_static_string(C_heaptop,0,"");
 C_save(tmp);
-lf[49]=C_h_list(3,C_pick(2),C_pick(1),C_pick(0));
-C_drop(3);
+lf[49]=C_h_list(2,C_pick(1),C_pick(0));
+C_drop(2);
 lf[52]=C_static_string(C_heaptop,2,"/c");
 lf[53]=C_static_string(C_heaptop,2,"-c");
 lf[71]=C_h_intern(&lf[71],18,"string-intersperse");
