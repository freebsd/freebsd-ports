--- src/pic2img.cc.orig	2003-03-28 12:37:32 UTC
+++ src/pic2img.cc
@@ -72,6 +72,7 @@ int LoadPicture (
    int *pic_width,		// To return the size of the picture
    int *pic_height)		// (can be NULL)
 {
+MasterDirectory	dirbuf;
 MDirPtr	dir;
 i16	pic_width_;
 i16	pic_height_;
@@ -95,7 +96,6 @@ u8      *buf;	/* This variable is set to point to the 
 // Locate the lump where the picture is
 if (picloc.wad != 0)
    {
-   MasterDirectory dirbuf;
    dirbuf.wadfile   = picloc.wad;
    dirbuf.dir.start = picloc.ofs;
    dirbuf.dir.size  = picloc.len;
