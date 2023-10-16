--- src/main.c.orig	2023-10-11 15:50:11 UTC
+++ src/main.c
@@ -42,6 +42,7 @@
 #include <client.h>
 #include <discover.h>
 
+#include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
@@ -52,7 +53,6 @@
 #include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
-#include <openssl/rand.h>
 
 static void applist(PSERVER_DATA server) {
   PAPP_LIST list = NULL;
@@ -149,6 +149,10 @@ static void stream(PSERVER_DATA server, PCONFIGURATION
     if (!config->viewonly)
       evdev_start();
     loop_main();
+    #ifdef HAVE_SDL
+    if (!isNoSdl)
+      x11_sdl_stop();
+    #endif
     if (!config->viewonly)
       evdev_stop();
   }
@@ -202,7 +206,6 @@ static void help() {
   printf("\t-bitrate <bitrate>\tSpecify the bitrate in Kbps\n");
   printf("\t-packetsize <size>\tSpecify the maximum packetsize in bytes\n");
   printf("\t-codec <codec>\t\tSelect used codec: auto/h264/h265/av1 (default auto)\n");
-  printf("\t-hdr\t\tEnable HDR streaming (experimental, requires host and device support)\n");
   printf("\t-remote <yes/no/auto>\t\t\tEnable optimizations for WAN streaming (default auto)\n");
   printf("\t-app <app>\t\tName of app to stream\n");
   printf("\t-nosops\t\t\tDon't allow GFE to modify game settings\n");
@@ -238,7 +241,10 @@ static void pair_check(PSERVER_DATA server) {
 int main(int argc, char* argv[]) {
   CONFIGURATION config;
   config_parse(argc, argv, &config);
-
+  #ifndef HAVE_SDL
+  isNoSdl = true;
+  #endif
+  
   if (config.action == NULL || strcmp("help", config.action) == 0)
     help();
 
@@ -322,19 +328,19 @@ int main(int argc, char* argv[]) {
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
@@ -371,7 +377,19 @@ int main(int argc, char* argv[]) {
 
         udev_init(!inputAdded, mappings, config.debug_level > 0, config.rotate);
         evdev_init(config.mouse_emulation);
+        #ifdef HAVE_SDL
+        if (isNoSdl)
+          rumble_handler = evdev_rumble;
+        else {
+          x11_sdl_init(config.mapping);
+          rumble_handler = sdlinput_rumble;
+          rumble_triggers_handler = sdlinput_rumble_triggers;
+          set_motion_event_state_handler = sdlinput_set_motion_event_state;
+          set_controller_led_handler = sdlinput_set_controller_led;
+        }
+        #else
         rumble_handler = evdev_rumble;
+        #endif
         #ifdef HAVE_LIBCEC
         cec_init();
         #endif /* HAVE_LIBCEC */
@@ -398,7 +416,8 @@ int main(int argc, char* argv[]) {
     if (config.pin > 0 && config.pin <= 9999) {
       sprintf(pin, "%04d", config.pin);
     } else {
-      sprintf(pin, "%d%d%d%d", (unsigned)random() % 10, (unsigned)random() % 10, (unsigned)random() % 10, (unsigned)random() % 10);
+      srand((unsigned)time(NULL));
+      sprintf(pin, "%04d", (unsigned)rand() % 9999 + 1);
     }
     printf("Please enter the following PIN on the target PC: %s\n", pin);
     fflush(stdout);
@@ -406,6 +425,7 @@ int main(int argc, char* argv[]) {
       fprintf(stderr, "Failed to pair to server: %s\n", gs_error);
     } else {
       printf("Succesfully paired\n");
+      printf("Note: Use Ctrl+Alt+Shift+Q to quit streaming.\n");
     }
   } else if (strcmp("unpair", config.action) == 0) {
     if (gs_unpair(&server) != GS_OK) {
