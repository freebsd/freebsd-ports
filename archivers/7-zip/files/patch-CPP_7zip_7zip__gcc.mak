--- CPP/7zip/7zip_gcc.mak.orig	2024-06-24 19:51:06 UTC
+++ CPP/7zip/7zip_gcc.mak
@@ -24,7 +24,7 @@ ifneq ($(CC), xlc)
 
 
 ifneq ($(CC), xlc)
-CFLAGS_WARN_WALL = -Werror -Wall -Wextra
+CFLAGS_WARN_WALL = 
 endif
 
 # for object file
@@ -50,7 +50,7 @@ endif
 endif
 
 # CFLAGS_BASE_LIST = -S
-CFLAGS_BASE = -O2 $(CFLAGS_BASE_LIST) $(CFLAGS_WARN_WALL) $(CFLAGS_WARN) \
+CFLAGS_BASE = $(CFLAGS_BASE_LIST) $(CFLAGS_WARN_WALL) $(CFLAGS_WARN) \
  $(CFLAGS_DEBUG) -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE \
  -fPIC
 
@@ -162,7 +162,6 @@ LIB2 = -lpthread
 # LOCAL_LIBS=-lpthread
 # LOCAL_LIBS_DLL=$(LOCAL_LIBS) -ldl
 LIB2 = -lpthread
-LIB2 = -lpthread -ldl
 
 
 endif
