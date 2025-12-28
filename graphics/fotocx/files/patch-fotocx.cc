--- fotocx.cc.orig	2025-11-18 09:44:35 UTC
+++ fotocx.cc
@@ -333,7 +333,7 @@ int main(int argc, ch *argv[])                        
    //  delete fotocx temp files if owner process is no longer running
 
    pidlist = 0;
-   snprintf(buff,200,"pidof fotocx fotocx.x");                                   //  get active fotocx PIDs
+   snprintf(buff,200,"pgrep -d\\  fotocx fotocx.x");
    fid = popen(buff,"r");
    if (fid) {
       pp = fgets_trim(buff,200,fid);
@@ -464,7 +464,7 @@ int main(int argc, ch *argv[])                        
    //  Report SMP (core) count for parallel threads. Hyperthreads and E-cores 
    //  have marginal value, but the kernel scheduler does not discriminate.
 
-   NSMP = get_nprocs_conf();                                                     //  get actual CPU core count             25.2
+   NSMP = get_nprocs();
    if (NSMP < 4) NSMP = 4;                                                       //  minimum required for some functions
    if (NSMP > XSMP) NSMP = XSMP;                                                 //  compile time limit
    printf("SMP thread count: %d \n",NSMP);
