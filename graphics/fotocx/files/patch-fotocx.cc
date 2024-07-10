--- fotocx.cc.orig	2024-07-01 07:25:41 UTC
+++ fotocx.cc
@@ -335,7 +335,7 @@ int main(int argc, ch *argv[])                        
    //  delete fotocx temp files if owner process is no longer running
 
    pidlist = 0;
-   snprintf(buff,200,"pidof fotocx fotocx.x");                                   //  get active fotocx PIDs
+   snprintf(buff,200,"pgrep -d\\  fotocx fotocx.x");
    fid = popen(buff,"r");
    if (fid) {
       pp = fgets_trim(buff,200,fid);
@@ -464,13 +464,15 @@ int main(int argc, ch *argv[])                        
 
    //  get SMP thread count
 
-   NSMP = 0;                                                                     //  assume at least 4 threads
+   NSMP = get_nprocs();
+#if 0
    fid = popen("lscpu | grep 'CPU(s):'","r");
    if (fid) {
       pp = fgets(buff,200,fid);                                                  //  get CPU threads supported
       pclose(fid);
       if (pp && strmatchN(pp,"CPU(s):",7)) NSMP = atoi(pp+8);                    //  P-cores + E-cores
    }
+#endif
    if (NSMP < 1) {
       Plog(1,"cannot get SMP thread count, assume 4 \n");
       NSMP = 4;
