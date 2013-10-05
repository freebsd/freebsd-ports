--- wxvidext.cpp	2013-10-04 20:22:46.000000000 -0500
+++ wxvidext.cpp	2013-10-04 20:24:08.000000000 -0500
@@ -455,7 +455,7 @@
 #endif
 */
 
-m64p_error VidExt_SetVideoMode(int Width, int Height, int BitsPerPixel, /*m64p_video_mode*/ int ScreenMode)
+m64p_error VidExt_SetVideoMode(int Width, int Height, int BitsPerPixel, /*m64p_video_mode*/ int ScreenMode, int Flags)
 {
     gWidth = Width;
     gHeight = Height;
