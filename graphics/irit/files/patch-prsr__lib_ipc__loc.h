--- prsr_lib/ipc_loc.h.orig
+++ prsr_lib/ipc_loc.h
@@ -338,7 +338,7 @@
 /* General file pointer for varios compression tools. */ 
 typedef gzFile IpcFile; 
 #define _IPC_OPEN_FILE(FileName, Mode) (gzopen(FileName, Mode)) 
-#define _IPC_DOPEN_FILE(f, Mode)       (gzdopen(_fileno(f), Mode))
+#define _IPC_DOPEN_FILE(f, Mode)       (gzdopen(fileno(f), Mode))
 #define _IPC_INIT(f) { \
           if (gzsetparams(f, IPC_COMPRESS_LEVEL, Z_DEFAULT_STRATEGY) != Z_OK) \
 	                   return IPC_ERROR_ZLIB;}
@@ -353,7 +353,7 @@
 /* General file pointer for varios compression tools. */ 
 typedef FILE IpcFile; 
 #define _IPC_OPEN_FILE(FileName, Mode) (fopen(FileName, Mode))
-#define _IPC_DOPEN_FILE(f, Mode)       (fdopen(_fileno(f), Mode))
+#define _IPC_DOPEN_FILE(f, Mode)       (fdopen(fileno(f), Mode))
 #define _IPC_INIT(f)
 #define _IPC_CLOSE_FILE(f) fclose(f)
 /* In Debug mode if used extern console compressor, */
