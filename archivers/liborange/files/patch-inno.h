--- lib/inno.h.orig	2008-05-22 15:55:23.000000000 +1000
+++ lib/inno.h	2008-05-22 15:57:49.000000000 +1000
@@ -3,7 +3,7 @@
 #define __inno_h__
 
 #include <stdbool.h>
-#include <stdint.h>
+#include <inttypes.h>
 #include <stdio.h>
 #include <zlib.h>
 
@@ -99,7 +99,7 @@
   uint32_t NumUninstallDeleteEntries; 
   uint32_t NumRunEntries; 
   uint32_t NumUninstallRunEntries;  
-  P uint8_t stuff[0x35];
+  uint8_t P stuff[0x35];
 } TSetupHeader;
 
 #define SETUP_HEADER_SIZE   0xd9
@@ -143,9 +143,9 @@
 
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
@@ -172,12 +172,12 @@
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
