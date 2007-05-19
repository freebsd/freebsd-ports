--- progs/xdemos/yuvrect_client.c.orig	Fri Apr  6 22:42:30 2007
+++ progs/xdemos/yuvrect_client.c	Fri Apr  6 22:48:05 2007
@@ -140,7 +140,11 @@
       exit(0);
    }
    
-   glx_memory = glXAllocateMemoryMESA(dpy, screen, ImgWidth * ImgHeight * 2, 0, 0 ,0);
+   #ifdef WITH_NVIDIA_GL
+   	glx_memory = glXAllocateMemoryNV(ImgWidth * ImgHeight * 2, 0, 0 ,0);
+   #else
+   	glx_memory = glXAllocateMemoryMESA(dpy, screen, ImgWidth * ImgHeight * 2, 0, 0 ,0);
+   #endif
    if (!glx_memory)
    {
      fprintf(stderr,"Failed to allocate MESA memory\n");
@@ -317,7 +321,11 @@
    glXSwapBuffers(dpy, win);
    event_loop(dpy, win);
 
-   glXFreeMemoryMESA(dpy, DefaultScreen(dpy), glx_memory);
+   #ifdef WITH_NVIDIA_GL
+      glXFreeMemoryNV(glx_memory);
+   #else
+      glXFreeMemoryMESA(dpy, DefaultScreen(dpy), glx_memory);
+   #endif
    glXDestroyContext(dpy, ctx);
    XDestroyWindow(dpy, win);
    XCloseDisplay(dpy);
