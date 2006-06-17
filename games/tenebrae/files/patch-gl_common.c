--- ./gl_common.c.orig	Sat Jun 10 12:08:13 2006
+++ ./gl_common.c	Sat Jun 10 12:08:13 2006
@@ -248,11 +248,11 @@
      if (!strstr(gl_extensions, "GL_ARB_texture_env_dot3")) {
           Sys_Error ("ARB_texture_env_dot3 not found.\nProbably your 3d-card is not supported.\n");
      }
-
+#if 0
      if (!strstr(gl_extensions, "GL_ARB_texture_cube_map")) {
           Sys_Error ("ARB_texture_cube_map not found.\nProbably your 3d-card is not supported.\n");
      }
-
+#endif
      //Just spit a warning user prob has gl-1.2 or something
      if (!strstr(gl_extensions, "GL_SGI_texture_edge_clamp") &&
          !strstr(gl_extensions, "GL_EXT_texture_edge_clamp")) {
