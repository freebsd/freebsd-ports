# Fix an uninitialized variable in a particular execution path
#
# While it would be better design to initialize the error value
# at the start, it is set in every other error path so the least
# intrusive correction is to set it in the one missed path.
#
--- src/egl/opengl/eglkms.c.orig	2012-08-28 14:31:17 UTC
+++ src/egl/opengl/eglkms.c
@@ -212,6 +212,7 @@ int main(int argc, char *argv[])
 
    if (!eglChooseConfig(dpy, attribs, &config, 1, &n) || n != 1) {
       fprintf(stderr, "failed to choose argb config\n");
+      ret = -1;
       goto egl_terminate;
    }
    
