--- f.file.cc.orig	2021-10-17 20:02:26 UTC
+++ f.file.cc
@@ -3687,13 +3687,17 @@ int find_imagefiles(cchar *folder, int flags, char **&
    
    if (flags & 1) Fimages = 1;
    if (flags & 2) Fthumbs = 1;
+#ifdef GLOB_PERIOD
    if (flags & 4) globflags += GLOB_PERIOD;
+#endif
    if (flags & 8) Fdirs = 1;
    if (flags & 16) Frecurse = 1;
    if (flags & 32) Fnolinks = 1;
    
+#ifdef GLOB_ONLYDIR
    if (Fdirs && ! Fimages && ! Fthumbs)
       globflags += GLOB_ONLYDIR;
+#endif
 
    globdata.gl_pathc = 0;                                                        //  glob() setup
    globdata.gl_offs = 0;
