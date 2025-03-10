--- fotocx.cc.orig	2024-10-01 05:03:10 UTC
+++ fotocx.cc
@@ -335,7 +335,7 @@ int main(int argc, ch *argv[])                        
    //  delete fotocx temp files if owner process is no longer running
 
    pidlist = 0;
-   snprintf(buff,200,"pidof fotocx fotocx.x");                                   //  get active fotocx PIDs
+   snprintf(buff,200,"pgrep -d\\  fotocx fotocx.x");
    fid = popen(buff,"r");
    if (fid) {
       pp = fgets_trim(buff,200,fid);
@@ -466,7 +466,7 @@ int main(int argc, ch *argv[])                        
    //  Cannot get P-core and E-core counts (methods vary by kernel release). 
    //  Hyperthreads and E-cores have marginal value.
 
-   NSMP = 12;                                                                    //  24.60
+   NSMP = get_nprocs();
    Plog(1,"SMP thread count: %d \n",NSMP);
 
    //  get locale specific name for /home/<user>/Desktop
