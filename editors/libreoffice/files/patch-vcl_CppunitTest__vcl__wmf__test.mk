--- vcl/CppunitTest_vcl_wmf_test.mk.orig	2017-05-03 16:46:29 UTC
+++ vcl/CppunitTest_vcl_wmf_test.mk
@@ -131,10 +131,9 @@ $(eval $(call gb_CppunitTest_use_externals,vcl_wmf_tes
 ))
 endif
 else
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD, $(OS)))
 $(eval $(call gb_CppunitTest_add_libs,vcl_wmf_test,\
-    -lm \
-    -ldl \
+    -lm $(DLOPEN_LIBS) \
     -lpthread \
     -lGL \
     -lX11 \
