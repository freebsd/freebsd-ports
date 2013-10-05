--- wxvidext.h	2013-10-04 20:22:58.000000000 -0500
+++ wxvidext.h	2013-10-04 20:23:12.000000000 -0500
@@ -29,7 +29,7 @@
 m64p_error VidExt_Init(void);
 m64p_error VidExt_Quit(void);
 m64p_error VidExt_ListFullscreenModes(m64p_2d_size *SizeArray, int *NumSizes);
-m64p_error VidExt_SetVideoMode(int Width, int Height, int BitsPerPixel, /*m64p_video_mode*/ int ScreenMode);
+m64p_error VidExt_SetVideoMode(int Width, int Height, int BitsPerPixel, /*m64p_video_mode*/ int ScreenMode, int Flags);
 m64p_error VidExt_SetCaption(const char *Title);
 m64p_error VidExt_ToggleFullScreen(void);
 void* VidExt_GL_GetProcAddress(const char* Proc);
