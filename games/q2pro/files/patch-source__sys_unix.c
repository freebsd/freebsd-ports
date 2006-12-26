--- ./source/sys_unix.c.orig	Mon Dec 25 17:07:02 2006
+++ ./source/sys_unix.c	Mon Dec 25 17:07:03 2006
@@ -36,10 +36,15 @@
 #include <sys/wait.h>
 #include <sys/mman.h>
 #include <errno.h>
+#ifdef __linux__
 #include <mntent.h>
+#endif
 #include <dirent.h>
 #include <dlfcn.h>
 #include <termios.h>
+#ifndef __linux__
+#include <machine/param.h>
+#endif
 
 #include "qcommon.h"
 #include "q_list.h"
@@ -376,7 +381,7 @@
 	pool->maxsize = ( maxsize + 4095 ) & ~4095;
 	pool->cursize = 0;
     buf = mmap( NULL, pool->maxsize, PROT_READ|PROT_WRITE,
-		MAP_PRIVATE|MAP_ANONYMOUS, -1, 0 );
+		MAP_PRIVATE|MAP_ANON, -1, 0 );
 	if( buf == NULL || buf == ( byte * )-1 ) {
 		Com_Error( ERR_FATAL, "Hunk_Begin: unable to virtual allocate %d bytes",
                 pool->maxsize );
@@ -403,7 +408,24 @@
 void Hunk_End( mempool_t *pool ) {
 	byte *n;
 
+#ifndef __linux__
+	size_t old_size = pool->maxsize;
+	size_t new_size = pool->cursize + sizeof(int);
+	void * unmap_base;
+	size_t unmap_len;
+
+	new_size = round_page(new_size);
+	old_size = round_page(old_size);
+	if (new_size > old_size)
+		n = 0; /* error */
+	else if (new_size < old_size) {
+		unmap_base = (caddr_t)(pool->base + new_size);
+		unmap_len = old_size - new_size;
+		n = munmap(unmap_base, unmap_len) + pool->base;
+	}
+#else
 	n = mremap( pool->base, pool->maxsize, pool->cursize, 0 );
+#endif
 	if( n != pool->base ) {
 		Com_Error( ERR_FATAL, "Hunk_End: could not remap virtual block: %s",
                 strerror( errno ) );
@@ -750,7 +772,7 @@
 	if( sys_debugdir->string[0] ) {
 		base = sys_debugdir->string;
 	} else {
-		base = Sys_GetCurrentDirectory();
+		base = LIBDIR;
 	}
 
 	// check the current debug directory first for development purposes
@@ -829,7 +851,7 @@
 //=======================================================================
 static void	*gameLibrary;
 
-#define	GAMELIB		"gamei386.so"
+#define	GAMELIB		"game.so"
 
 /*
 =================
