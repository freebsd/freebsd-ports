# Provide a fallback for missing sincos()
#
--- src/egl/opengles2/es2gears.c.orig	2012-06-25 15:34:58 UTC
+++ src/egl/opengles2/es2gears.c
@@ -168,6 +168,12 @@ create_gear(GLfloat inner_radius, GLfloa
    gear->vertices = calloc(VERTICES_PER_TOOTH * teeth, sizeof(*gear->vertices));
    v = gear->vertices;
 
+#ifndef sincos
+#define sincos(__x, _s, _c) do { \
+   float _x = (__x); *(_s) = sin(_x); *(_c) = cos(_x); \
+} while(0)
+#endif
+
    for (i = 0; i < teeth; i++) {
       /* Calculate needed sin/cos for varius angles */
       sincos(i * 2.0 * M_PI / teeth, &s[0], &c[0]);
