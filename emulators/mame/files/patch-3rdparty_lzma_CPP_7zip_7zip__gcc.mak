--- 3rdparty/lzma/CPP/7zip/7zip_gcc.mak.orig	2024-02-01 08:45:29 UTC
+++ 3rdparty/lzma/CPP/7zip/7zip_gcc.mak
@@ -24,7 +24,7 @@ ifneq ($(CC), xlc)
 
 
 ifneq ($(CC), xlc)
-CFLAGS_WARN_WALL = -Werror -Wall -Wextra
+CFLAGS_WARN_WALL =
 endif
 
 # for object file
@@ -32,14 +32,14 @@ CFLAGS_BASE_LIST = -c
 # -save-temps
 CFLAGS_BASE_LIST = -c
 # CFLAGS_BASE_LIST = -S
-CFLAGS_BASE = -O2 $(CFLAGS_BASE_LIST) $(CFLAGS_WARN_WALL) $(CFLAGS_WARN) \
- -DNDEBUG -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE \
+CFLAGS_BASE = $(CFLAGS_BASE_LIST) $(CFLAGS_WARN_WALL) $(CFLAGS_WARN) \
+ -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE \
  -fPIC
 
 FLAGS_FLTO = -ffunction-sections
 FLAGS_FLTO = -flto
 FLAGS_FLTO =
-# 
+#
 # -DZ7_AFFINITY_DISABLE
 
 
@@ -110,7 +110,7 @@ PROGPATH_STATIC = $(O)/$(PROG)s$(SHARED_EXT)
 
 PROGPATH = $(O)/$(PROG)$(SHARED_EXT)
 PROGPATH_STATIC = $(O)/$(PROG)s$(SHARED_EXT)
-	
+
 ifdef IS_MINGW
 
 ifdef MSYSTEM
@@ -130,7 +130,7 @@ CXXFLAGS_EXTRA = -DUNICODE -D_UNICODE
 CXXFLAGS_EXTRA = -DUNICODE -D_UNICODE
 # -Wno-delete-non-virtual-dtor
 
- 
+
 else
 
 RM = rm -f
@@ -142,7 +142,7 @@ DEL_OBJ_EXE = -$(RM) $(PROGPATH) $(PROGPATH_STATIC) $(
 
 # LOCAL_LIBS=-lpthread
 # LOCAL_LIBS_DLL=$(LOCAL_LIBS) -ldl
-LIB2 = -lpthread -ldl
+LIB2 = -lpthread
 
 
 endif
