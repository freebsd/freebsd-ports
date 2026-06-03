--- fotocx.cc.orig	2026-01-08 11:29:58 UTC
+++ fotocx.cc
@@ -327,7 +327,7 @@ int main(int argc, ch *argv[])                        
    //  delete fotocx temp files if owner process is no longer running
 
    pidlist = 0;
-   snprintf(buff,200,"pidof fotocx fotocx.x");                                         //  get active fotocx PIDs
+   snprintf(buff,200,"pgrep -d\\  fotocx fotocx.x");
    fid = popen(buff,"r");
    if (fid) {
       pp = fgets_trim(buff,200,fid);
@@ -462,7 +462,7 @@ int main(int argc, ch *argv[])                        
    //  Report SMP (core) count for parallel threads. Hyperthreads and E-cores 
    //  have marginal value, but the kernel scheduler does not discriminate.
 
-   NSMP = get_nprocs_conf();                                                           //  get actual CPU core count             25.2
+   NSMP = get_nprocs();
    NSMP -= 2;                                                                          //  don't use all of them                 26.0
    if (NSMP < 4) NSMP = 4;                                                             //  minimum required for some functions
    if (NSMP > XSMP) NSMP = XSMP;                                                       //  compile time limit
