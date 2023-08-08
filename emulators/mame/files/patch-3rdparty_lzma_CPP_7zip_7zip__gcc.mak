--- 3rdparty/lzma/CPP/7zip/7zip_gcc.mak.orig	2023-05-30 17:50:57 UTC
+++ 3rdparty/lzma/CPP/7zip/7zip_gcc.mak
@@ -18,13 +18,13 @@ PROGPATH_STATIC = $(O)/$(PROG)s
 
 
 ifneq ($(CC), xlc)
-CFLAGS_WARN_WALL = -Wall -Werror -Wextra
+CFLAGS_WARN_WALL = 
 endif
 
 # for object file
 CFLAGS_BASE_LIST = -c
 # CFLAGS_BASE_LIST = -S
-CFLAGS_BASE = -O2 $(CFLAGS_BASE_LIST) $(CFLAGS_WARN_WALL) $(CFLAGS_WARN) \
+CFLAGS_BASE = $(CFLAGS_BASE_LIST) $(CFLAGS_WARN_WALL) $(CFLAGS_WARN) \
  -DNDEBUG -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE \
  -fPIC
 
@@ -131,7 +131,7 @@ DEL_OBJ_EXE = -$(RM) $(PROGPATH) $(PROGPATH_STATIC) $(
 
 # LOCAL_LIBS=-lpthread
 # LOCAL_LIBS_DLL=$(LOCAL_LIBS) -ldl
-LIB2 = -lpthread -ldl
+LIB2 = $(LOCAL_LIBS) -lpthread
 
 
 endif
