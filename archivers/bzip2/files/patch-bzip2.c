--- bzip2.c.orig	Wed Feb 16 03:25:35 2005
+++ bzip2.c	Sun Oct 16 09:47:40 2005
@@ -312,6 +312,7 @@
 
 static void    copyFileName ( Char*, Char* );
 static void*   myMalloc     ( Int32 );
+static int     applySavedFileAttrToOutputFile ( int fd );
 
 
 
@@ -457,6 +458,10 @@
    ret = fflush ( zStream );
    if (ret == EOF) goto errhandler_io;
    if (zStream != stdout) {
+      int fd = fileno ( zStream );
+      if (fd < 0) goto errhandler_io;
+      ret = applySavedFileAttrToOutputFile ( fd );
+      if (ret != 0) goto errhandler_io;
       ret = fclose ( zStream );
       outputHandleJustInCase = NULL;
       if (ret == EOF) goto errhandler_io;
@@ -569,6 +574,12 @@
 
    closeok:
    if (ferror(zStream)) goto errhandler_io;
+   if ( stream != stdout) {
+      int fd = fileno ( stream );
+      if (fd < 0) goto errhandler_io;
+      ret = applySavedFileAttrToOutputFile ( fd );
+      if (ret != 0) goto errhandler_io;
+   }
    ret = fclose ( zStream );
    if (ret == EOF) goto errhandler_io;
 
@@ -1129,7 +1140,7 @@
 
 
 static 
-void applySavedMetaInfoToOutputFile ( Char *dstName )
+void applySavedTimeInfoToOutputFile ( Char *dstName )
 {
 #  if BZ_UNIX
    IntNative      retVal;
@@ -1138,16 +1149,26 @@
    uTimBuf.actime = fileMetaInfo.st_atime;
    uTimBuf.modtime = fileMetaInfo.st_mtime;
 
-   retVal = chmod ( dstName, fileMetaInfo.st_mode );
-   ERROR_IF_NOT_ZERO ( retVal );
-
    retVal = utime ( dstName, &uTimBuf );
    ERROR_IF_NOT_ZERO ( retVal );
+#  endif
+}
+
+static 
+int applySavedFileAttrToOutputFile ( int fd )
+{
+#  if BZ_UNIX
+   IntNative      retVal;
+
+   retVal = fchmod ( fd, fileMetaInfo.st_mode );
+   if (retVal != 0)
+       return retVal;
 
-   retVal = chown ( dstName, fileMetaInfo.st_uid, fileMetaInfo.st_gid );
+   (void) fchown ( fd, fileMetaInfo.st_uid, fileMetaInfo.st_gid );
    /* chown() will in many cases return with EPERM, which can
       be safely ignored.
    */
+   return 0;
 #  endif
 }
 
@@ -1370,7 +1391,7 @@
 
    /*--- If there was an I/O error, we won't get here. ---*/
    if ( srcMode == SM_F2F ) {
-      applySavedMetaInfoToOutputFile ( outName );
+      applySavedTimeInfoToOutputFile ( outName );
       deleteOutputOnInterrupt = False;
       if ( !keepInputFiles ) {
          IntNative retVal = remove ( inName );
@@ -1548,7 +1569,7 @@
    /*--- If there was an I/O error, we won't get here. ---*/
    if ( magicNumberOK ) {
       if ( srcMode == SM_F2F ) {
-         applySavedMetaInfoToOutputFile ( outName );
+         applySavedTimeInfoToOutputFile ( outName );
          deleteOutputOnInterrupt = False;
          if ( !keepInputFiles ) {
             IntNative retVal = remove ( inName );
