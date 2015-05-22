--- include/system.h.good	Wed Nov 22 23:38:44 2000
+++ include/system.h	Wed Nov 22 23:41:03 2000
@@ -522,7 +522,7 @@
 E time_t FDECL(time, (time_t *));
 #  endif
 # else
-E long FDECL(time, (time_t *));
+E time_t FDECL(time, (time_t *));
 # endif /* ULTRIX */
 
 #ifdef VMS
