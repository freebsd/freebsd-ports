--- ruby/video/glx.cpp.orig	2014-01-20 06:37:14 UTC
+++ ruby/video/glx.cpp
@@ -128,6 +128,28 @@ struct pVideoGLX : OpenGL {
     //require GLX 1.2+ API
     if(glx.version_major < 1 || (glx.version_major == 1 && glx.version_minor < 2)) return false;
 
+    int major, minor;
+    const char *version = (const char *) glGetString (GL_VERSION);
+    const char *dot = version == NULL ? NULL : strchr (version, '.');
+    const char *major_start = dot;
+
+    /* Sanity check */
+    if (dot == NULL || dot == version || *(dot + 1) == '\0') {
+        major = 0;
+        minor = 0;
+    } else {
+    /* Find the start of the major version in the string */
+    while (major_start > version && *major_start != ' ')
+           --major_start;
+        major = strtol (major_start, NULL, 10);
+        minor = strtol (dot + 1, NULL, 0);
+    }
+
+    if(major < 3 || (major == 3 && minor < 2)) {
+        printf("Error: OpenGL 3.2 is not available. Select another video driver on the Advanced Configuration tab and restart higan.\n");
+        return false;
+    }
+
     XWindowAttributes window_attributes;
     XGetWindowAttributes(display, settings.handle, &window_attributes);
 
