--- lib/inno.h.orig	Mon Sep  8 17:17:28 2003
+++ lib/inno.h	Mon Jan 10 05:07:47 2005
@@ -3,7 +3,7 @@
 #define __inno_h__
 
 #include <stdbool.h>
-#include <stdint.h>
+#include <inttypes.h>
 #include <stdio.h>
 #include <zlib.h>
 
@@ -100,7 +100,7 @@
   uint32_t NumUninstallDeleteEntries; 
   uint32_t NumRunEntries; 
   uint32_t NumUninstallRunEntries;  
-  P uint8_t stuff[0x35];
+  uint8_t P stuff[0x35];
 } TSetupHeader;
 
 #define SETUP_HEADER_SIZE   0xd9
@@ -144,9 +144,9 @@
 
 typedef struct
 {
-  P uint32_t WinVersion;
-  P uint32_t NTVersion;
-  P uint16_t Word;
+  uint32_t P WinVersion;
+  uint32_t P NTVersion;
+  uint16_t P Word;
 } TSetupVersionData;
 
 #if 0
@@ -173,12 +173,12 @@
     char* InstallFontName;
     char* Components; 
     char* Tasks;
-    P TSetupVersionData MinVersion;
-    P TSetupVersionData OnlyBelowVersion;
+    TSetupVersionData P MinVersion;
+    TSetupVersionData P OnlyBelowVersion;
     uint32_t LocationEntry;
     uint32_t Attribs;
     uint32_t ExternalSize;
-    P char stuff[4];
+    char P stuff[4];
 #if 0
     Options: set of (foConfirmOverwrite, foUninsNeverUninstall, foRestartReplace,
       foDeleteAfterInstall, foRegisterServer, foRegisterTypeLib, foSharedFile,
@@ -191,7 +191,7 @@
 #endif
 } TSetupFileEntry;
 
-P typedef struct
+typedef struct
 {
   uint32_t FirstDisk;
   uint32_t LastDisk;
@@ -202,7 +202,7 @@
   uint32_t Date;
   uint32_t FileVersionMS;
   uint32_t FileVersionLS;
-} TSetupFileLocationEntry;
+} P TSetupFileLocationEntry;
 
 #define SETUP_FILE_LOCATION_ENTRY_SIZE  0x29
 
