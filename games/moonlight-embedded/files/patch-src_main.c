--- src/main.c.orig	2024-02-20 04:01:31 UTC
+++ src/main.c
@@ -42,6 +42,7 @@
 #include <client.h>
 #include <discover.h>
 
+#include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
@@ -52,7 +53,8 @@
 #include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
-#include <openssl/rand.h>
+ 
+extern void is_use_kbdmux();
 
 static void applist(PSERVER_DATA server) {
   PAPP_LIST list = NULL;
@@ -202,7 +204,6 @@ static void help() {
   printf("\t-bitrate <bitrate>\tSpecify the bitrate in Kbps\n");
   printf("\t-packetsize <size>\tSpecify the maximum packetsize in bytes\n");
   printf("\t-codec <codec>\t\tSelect used codec: auto/h264/h265/av1 (default auto)\n");
-  printf("\t-hdr\t\tEnable HDR streaming (experimental, requires host and device support)\n");
   printf("\t-remote <yes/no/auto>\t\t\tEnable optimizations for WAN streaming (default auto)\n");
   printf("\t-app <app>\t\tName of app to stream\n");
   printf("\t-nosops\t\t\tDon't allow GFE to modify game settings\n");
@@ -322,19 +323,19 @@ int main(int argc, char* argv[]) {
     config.stream.supportedVideoFormats = VIDEO_FORMAT_H264;
     if (config.codec == CODEC_HEVC || (config.codec == CODEC_UNSPECIFIED && platform_prefers_codec(system, CODEC_HEVC))) {
       config.stream.supportedVideoFormats |= VIDEO_FORMAT_H265;
-      if (config.hdr)
-        config.stream.supportedVideoFormats |= VIDEO_FORMAT_H265_MAIN10;
+      //if (config.hdr)
+      //  config.stream.supportedVideoFormats |= VIDEO_FORMAT_H265_MAIN10;
     }
     if (config.codec == CODEC_AV1 || (config.codec == CODEC_UNSPECIFIED && platform_prefers_codec(system, CODEC_AV1))) {
       config.stream.supportedVideoFormats |= VIDEO_FORMAT_AV1_MAIN8;
-      if (config.hdr)
-        config.stream.supportedVideoFormats |= VIDEO_FORMAT_AV1_MAIN10;
+      //if (config.hdr)
+      //  config.stream.supportedVideoFormats |= VIDEO_FORMAT_AV1_MAIN10;
     }
 
-    if (config.hdr && !(config.stream.supportedVideoFormats & VIDEO_FORMAT_MASK_10BIT)) {
-      fprintf(stderr, "HDR streaming requires HEVC or AV1 codec\n");
-      exit(-1);
-    }
+    //if (config.hdr && !(config.stream.supportedVideoFormats & VIDEO_FORMAT_MASK_10BIT)) {
+    //  fprintf(stderr, "HDR streaming requires HEVC or AV1 codec\n");
+    //  exit(-1);
+    //}    
 
     #ifdef HAVE_SDL
     if (system == SDL)
@@ -362,6 +363,9 @@ int main(int argc, char* argv[]) {
           mappings = map;
         }
 
+        // test is use kbdmux driver
+        if (config.inputsCount <= 0)
+          is_use_kbdmux();
         for (int i=0;i<config.inputsCount;i++) {
           if (config.debug_level > 0)
             printf("Adding input device %s...\n", config.inputs[i]);
@@ -398,7 +402,8 @@ int main(int argc, char* argv[]) {
     if (config.pin > 0 && config.pin <= 9999) {
       sprintf(pin, "%04d", config.pin);
     } else {
-      sprintf(pin, "%d%d%d%d", (unsigned)random() % 10, (unsigned)random() % 10, (unsigned)random() % 10, (unsigned)random() % 10);
+      srand((unsigned)time(NULL));
+      sprintf(pin, "%04d", (unsigned)rand() % 9999 + 1);
     }
     printf("Please enter the following PIN on the target PC: %s\n", pin);
     fflush(stdout);
@@ -406,6 +411,7 @@ int main(int argc, char* argv[]) {
       fprintf(stderr, "Failed to pair to server: %s\n", gs_error);
     } else {
       printf("Succesfully paired\n");
+      printf("Note: Use Ctrl+Alt+Shift+Q to quit streaming.\n");
     }
   } else if (strcmp("unpair", config.action) == 0) {
     if (gs_unpair(&server) != GS_OK) {
