
$FreeBSD$

--- pal/unix/file/file.c.orig	Fri Mar 22 03:48:20 2002
+++ pal/unix/file/file.c	Wed Apr 10 11:52:45 2002
@@ -37,6 +37,9 @@
 #include <sys/stat.h>
 #include <errno.h>
 
+#define chmod( path, mode )	chmod( ( path ), ( mode ) & ~GetUmask() )
+#define fchmod( fd, mode )	fchmod( ( fd ), ( mode ) & ~GetUmask() )
+#define lchmod( path, mode )	lchmod( ( path ), ( mode ) & ~GetUmask() )
 
 SET_DEFAULT_DEBUG_CHANNEL(FILE);
 
@@ -44,6 +47,8 @@
 static int FILECloseStdHandle( HOBJSTRUCT *handle_data);
 static int FILEDuplicateHandle( HANDLE handle, HOBJSTRUCT *handle_data);
 
+static mode_t GetUmask( void );
+
 static file *FILENewFileData( void );
 
 static BOOL FILEAddNewLockedRgn(SHMFILELOCKS* fileLocks,
@@ -2342,6 +2347,17 @@
     HMGRUnlockHandle(handle,&file_data->handle_data);
 }
 
+static mode_t GetUmask( void )
+{
+    mode_t mask;
+
+    /* XXX: Probably need to block signals to avoid race here */
+    mask = umask( 0 );
+    umask( mask );
+    /* XXX: Unblock here */
+
+    return mask;
+}
 
 /*++
 Function:
