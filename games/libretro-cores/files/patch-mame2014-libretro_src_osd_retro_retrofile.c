--- mame2014-libretro/src/osd/retro/retrofile.c.orig	2015-11-04 17:31:20 UTC
+++ mame2014-libretro/src/osd/retro/retrofile.c
@@ -135,7 +135,7 @@ file_error osd_open(const char *path, UI
    UINT32 access;
    const char *src;
    char *dst;
-#if defined(__MACH__) || defined(_WIN32) ||  defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
+#if defined(__FreeBSD__) || defined(__MACH__) || defined(_WIN32) ||  defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
    struct stat st;
 #else
    struct stat64 st;
@@ -238,7 +238,7 @@ file_error osd_open(const char *path, UI
 #endif
 
    // attempt to open the file
-#if defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
+#if defined(__FreeBSD__) || defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
    (*file)->handle = open(tmpstr, access, 0666);
 #else
    (*file)->handle = open64(tmpstr, access, 0666);
@@ -262,7 +262,7 @@ file_error osd_open(const char *path, UI
             // attempt to reopen the file
             if (error == NO_ERROR)
             {
-#if defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
+#if defined(__FreeBSD__) || defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
                (*file)->handle = open(tmpstr, access, 0666);
 #else
                (*file)->handle = open64(tmpstr, access, 0666);
@@ -282,7 +282,7 @@ file_error osd_open(const char *path, UI
    }
 
    // get the file size
-#if defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
+#if defined(__FreeBSD__) || defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
    fstat((*file)->handle, &st);
 #else
    fstat64((*file)->handle, &st);
@@ -315,7 +315,7 @@ file_error osd_read(osd_file *file, void
    switch (file->type)
    {
       case SDLFILE_FILE:
-#if defined(__MACH__) || defined(SDLMAME_BSD)
+#if defined(__FreeBSD__) || defined(__MACH__) || defined(SDLMAME_BSD)
          result = pread(file->handle, buffer, count, offset);
          if (result < 0)
 #elif defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_OS2)
@@ -361,7 +361,7 @@ file_error osd_write(osd_file *file, con
    switch (file->type)
    {
       case SDLFILE_FILE:
-#if defined(__MACH__) || defined(SDLMAME_BSD)
+#if defined(__FreeBSD__) || defined(__MACH__) || defined(SDLMAME_BSD)
          result = pwrite(file->handle, buffer, count, offset);
          if (!result)
 #elif defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_OS2)
@@ -532,13 +532,13 @@ osd_directory_entry *osd_stat(const char
 {
 	int err;
 	osd_directory_entry *result = NULL;
-#if defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
+#if defined(__FreeBSD__) || defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
    struct stat st;
 #else
    struct stat64 st;
 #endif
 
-#if defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
+#if defined(__FreeBSD__) || defined(__MACH__) || defined(_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_ARM) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(SDLMAME_HAIKU)
    err = stat(path, &st);
 #else
    err = stat64(path, &st);
