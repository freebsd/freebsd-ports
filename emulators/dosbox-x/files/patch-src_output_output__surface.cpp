--- src/output/output_surface.cpp.orig	2022-07-23 20:42:49 UTC
+++ src/output/output_surface.cpp
@@ -24,7 +24,9 @@ void OUTPUT_SURFACE_Initialize()
     // blitting the wrong dimensions to the window and trigger an X11 BadValue error.
     // Set up an error handler that prints the error to STDERR and then returns,
     // instead of the default handler which prints an error and exit()s this program.
+#ifndef __FreeBSD__
     X11_ErrorHandlerInstall();
+#endif
 #endif
 }
 
