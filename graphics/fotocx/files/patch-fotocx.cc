--- fotocx.cc.orig	2025-01-01 12:47:23 UTC
+++ fotocx.cc
@@ -240,7 +240,7 @@ int main(int argc, ch *argv[])                        
    Nblacklist = 0;                                                               //  blacklist folders/files count
    Nfuncbusy = 0;                                                                //  nothing busy
    Fescape = 0;                                                                  //  no escape key pressed
-   NSMP = 8;                                                                     //  default SMP (core) count
+   NSMP = get_nprocs();
 
    imagefiletypes = zstrdup(".jpg .jpeg .png .jxl .tif .tiff .bmp .ico .ppm .gif .svg .xpm .tga " ,"params",100);      //  jxl
    RAWfiletypes = zstrdup(".arw .srf .sr2 .crw .cr2 .cr3 .dng .mdc .mrw .nef .nrw .raw .rw2 .srw ", "params",100);
@@ -307,7 +307,7 @@ int main(int argc, ch *argv[])                        
    //  delete fotocx temp files if owner process is no longer running
 
    pidlist = 0;
-   snprintf(buff,200,"pidof fotocx fotocx.x");                                   //  get active fotocx PIDs
+   snprintf(buff,200,"pgrep -d\\  fotocx fotocx.x");
    fid = popen(buff,"r");
    if (fid) {
       pp = fgets_trim(buff,200,fid);
