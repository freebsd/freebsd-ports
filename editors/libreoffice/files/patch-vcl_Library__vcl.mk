--- vcl/Library_vcl.mk.orig	2017-05-03 16:46:29 UTC
+++ vcl/Library_vcl.mk
@@ -643,13 +643,12 @@ else
     vcl/source/opengl/OpenGLHelper \
     vcl/source/window/openglwin \
  ))
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD, $(OS)))
 $(eval $(call gb_Library_add_libs,vcl,\
-	-lm \
-	-ldl \
+	-lm $(DLOPEN_LIBS) \
 	-lpthread \
-    -lGL \
-    -lX11 \
+	-lGL \
+	-lX11 \
 ))
 endif
 endif
