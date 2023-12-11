--- fotoxx.cc.orig	2023-12-02 22:45:44 UTC
+++ fotoxx.cc
@@ -294,7 +294,7 @@ int main(int argc, ch *argv[])                        
    //  delete fotoxx temp files if owner process is no longer running
    
    pidlist = 0;
-   snprintf(buff,200,"pidof fotoxx fotoxx.x");                                   //  get active fotoxx PIDs                23.3
+   snprintf(buff,200,"pgrep -d\\  fotoxx fotoxx.x");
    fid = popen(buff,"r");
    if (fid) {
       pp = fgets_trim(buff,200,fid);                                           
@@ -432,13 +432,15 @@ int main(int argc, ch *argv[])                        
 
    //  get SMP thread count                                                      //  23.3
 
-   NSMP = 0;                                                                     //  assume at least 4 threads   
+   NSMP = get_nprocs();
+#if 0
    fid = popen("lscpu | grep 'CPU(s):'","r");
    if (fid) {
       pp = fgets(buff,200,fid);                                                  //  get CPU threads supported
       pclose(fid);
       if (pp && strmatchN(pp,"CPU(s):",7)) NSMP = atoi(pp+8);                    //  default: 2 per P-core + 1 per E-core
    }
+#endif
    if (NSMP < 1) {                                                               //  23.80 
       Plog(1,"cannot get SMP thread count, assume 4 \n");
       NSMP = 4;
