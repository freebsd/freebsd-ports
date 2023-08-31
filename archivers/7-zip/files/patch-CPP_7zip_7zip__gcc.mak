--- CPP/7zip/7zip_gcc.mak.orig	2023-08-31 09:13:13 UTC
+++ CPP/7zip/7zip_gcc.mak
@@ -24,7 +24,7 @@ PROGPATH_STATIC = $(O)/$(PROG)s
 
 
 ifneq ($(CC), xlc)
-CFLAGS_WARN_WALL = -Werror -Wall -Wextra
+CFLAGS_WARN_WALL = 
 endif
 
 # for object file
@@ -32,7 +32,7 @@ endif
 # -save-temps
 CFLAGS_BASE_LIST = -c
 # CFLAGS_BASE_LIST = -S
-CFLAGS_BASE = -O2 $(CFLAGS_BASE_LIST) $(CFLAGS_WARN_WALL) $(CFLAGS_WARN) \
+CFLAGS_BASE = $(CFLAGS_BASE_LIST) $(CFLAGS_WARN_WALL) $(CFLAGS_WARN) \
  -DNDEBUG -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE \
  -fPIC
 
@@ -142,7 +142,7 @@ DEL_OBJ_EXE = -$(RM) $(PROGPATH) $(PROGPATH_STATIC) $(
 
 # LOCAL_LIBS=-lpthread
 # LOCAL_LIBS_DLL=$(LOCAL_LIBS) -ldl
-LIB2 = -lpthread -ldl
+LIB2 = $(LOCAL_LIBS) -lpthread
 
 
 endif
