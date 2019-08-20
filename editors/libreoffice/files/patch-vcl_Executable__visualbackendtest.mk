--- vcl/Executable_visualbackendtest.mk.orig	2019-08-07 01:26:35.000000000 +0800
+++ vcl/Executable_visualbackendtest.mk	2019-08-08 20:07:11.830059000 +0800
@@ -41,11 +41,10 @@
     vclmain \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD, $(OS)))
 $(eval $(call gb_Executable_add_libs,visualbackendtest,\
-	-lm \
-	-ldl \
-    -lX11 \
+	-lm $(DLOPEN_LIBS) \
+	-lX11 \
 ))
 
 $(eval $(call gb_Executable_use_static_libraries,visualbackendtest,\
