--- CImg.h.orig	Mon Oct 11 21:46:09 2004
+++ CImg.h	Mon Oct 11 22:04:08 2004
@@ -55,7 +55,7 @@
 
 // Autodetection of the current OS
 #ifndef cimg_OS
-#if defined(sun) || defined(__sun)        
+#if defined(sun) || defined(__sun)
 // Solaris
 #define cimg_OS            0
 #ifndef cimg_display_type
@@ -82,6 +82,15 @@
 #ifndef cimg_display_type
 #define cimg_display_type  1
 #endif
+#elif defined(__FreeBSD__)
+// FreeBSD
+#define cimg_OS            4
+#ifndef cimg_display_type
+#define cimg_display_type  1
+#endif
+#ifndef cimg_color_terminal
+#define cimg_color_terminal
+#endif
 #else 
 // Other configurations
 #define cimg_OS           -1
@@ -1110,7 +1119,7 @@
                  t_red,cimg_version,t_normal,__DATE__,__TIME__);
     std::fprintf(stderr,"  > Architecture   : %s%-12s%s %s(cimg_OS=%d)\n%s",
                  t_bold,
-                 cimg_OS==0?"Solaris":(cimg_OS==1?"Linux":(cimg_OS==2?"Windows":(cimg_OS==3?"Mac OS X":"Unknown"))),
+                 cimg_OS==0?"Solaris":(cimg_OS==1?"Linux":(cimg_OS==2?"Windows":(cimg_OS==3?"Mac OS X":(cimg_OS==4?"FreeBSD":"Unknown")))),
                  t_normal,t_purple,cimg_OS,t_normal);
     std::fprintf(stderr,"  > Display type   : %s%-12s%s %s(cimg_display_type=%d)%s\n",
                  t_bold,cimg_display_type==0?"No":(cimg_display_type==1?"X11":(cimg_display_type==2?"WindowsGDI":"Unknown")),t_normal,t_purple,cimg_display_type,t_normal);
@@ -1542,7 +1551,7 @@
   uint width;                 //!< Width of the display window.
   uint height;                //!< Height of the display window.
   uint normalize;             //!< Pixel value normalization.
-  const uint attributes;      //!< Attributes of the display window.
+  uint attributes;            //!< Attributes of the display window.
   volatile int mousex;        //!< When (attributes&3)>=2, this variable corresponds to the mouse pointer X-coordinate into the display window.
   volatile int mousey;        //!< When (attributes&3)>=2, this variable corresponds to the mouse pointer Y-coordinate into the display window.
   volatile uint button;       //!< When (attributes&3)>=2, these variables corresponds to the mouse button clicked into the display window.
@@ -6575,7 +6584,7 @@
   Here are the different environment variables used by the CImg Library :
   
   - \b \c cimg_OS : This variable defines the type of your current OS. It can be set to 0 (Solaris), 1 (Linux),
-  2 (Windows), 3 (Mac OS X) or -1 (Other configuration).
+  2 (Windows), 3 (Mac OS X), 4 (FreeBSD) or -1 (Other configuration).
   It should be actually auto-detected by the CImg library. If this is not the case (cimg_OS=-1), then you
   will probably have to tune the environment variables described below.
   - \b \c cimg_display_type : This variable defines the type of display library that will be used to
