--- hotspot/make/bsd/makefiles/gcc.make.orig
+++ hotspot/make/bsd/makefiles/gcc.make
@@ -200,6 +200,9 @@ ifeq ($(USE_CLANG),)
     CFLAGS += -fvisibility=hidden
   endif
 else
+  ifneq ($(OS_VENDOR), Darwin)
+    CFLAGS += -pthread
+  endif
   CFLAGS += -fvisibility=hidden
 endif
 
