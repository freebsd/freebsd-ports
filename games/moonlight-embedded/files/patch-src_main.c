--- src/main.c.orig	2019-04-29 17:09:45 UTC
+++ src/main.c
@@ -91,7 +91,6 @@ static void stream(PSERVER_DATA server, PCONFIGURATION
   }
 
   int gamepads = 0;
-  gamepads += evdev_gamepads;
   #ifdef HAVE_SDL
   gamepads += sdl_gamepads;
   #endif
@@ -121,19 +120,11 @@ static void stream(PSERVER_DATA server, PCONFIGURATION
     connection_debug = true;
   }
 
-  if (IS_EMBEDDED(system))
-    loop_init();
-
   platform_start(system);
   LiStartConnection(&server->serverInfo, &config->stream, &connection_callbacks, platform_get_video(system), platform_get_audio(system, config->audio_device), NULL, drFlags, config->audio_device, 0);
 
-  if (IS_EMBEDDED(system)) {
-    evdev_start();
-    loop_main();
-    evdev_stop();
-  }
   #ifdef HAVE_SDL
-  else if (system == SDL)
+  if (system == SDL)
     sdl_loop();
   #endif
 
@@ -182,7 +173,6 @@ static void help() {
   printf("\t-surround\t\tStream 5.1 surround sound (requires GFE 2.7)\n");
   printf("\t-keydir <directory>\tLoad encryption keys from directory\n");
   printf("\t-mapping <file>\t\tUse <file> as gamepad mappings configuration file\n");
-  printf("\t-platform <system>\tSpecify system used for audio, video and input: pi/imx/aml/rk/x11/x11_vdpau/sdl/fake (default auto)\n");
   printf("\t-unsupported\t\tTry streaming if GFE version or options are unsupported\n");
   printf("\t-quitappafter\t\tSend quit app request to remote after quitting session\n");
   #if defined(HAVE_SDL) || defined(HAVE_X11)
@@ -221,8 +211,6 @@ int main(int argc, char* argv[]) {
       exit(-1);
     }
  
-    evdev_create(config.inputs[0], NULL, config.debug_level > 0);
-    evdev_map(config.inputs[0]); 
     exit(0); 
   }
 
@@ -233,12 +221,8 @@ int main(int argc, char* argv[]) {
       exit(-1);
     }
     config.address[0] = 0;
-    printf("Searching for server...\n");
-    gs_discover_server(config.address);
-    if (config.address[0] == 0) {
-      fprintf(stderr, "Autodiscovery failed. Specify an IP address next time.\n");
-      exit(-1);
-    }
+    fprintf(stderr, "Autodiscovery unsupported. Specify an IP address next time.\n");
+    exit(-1);
   }
   
   char host_config_file[128];
@@ -288,39 +272,8 @@ int main(int argc, char* argv[]) {
     }
     config.stream.supportsHevc = config.codec != CODEC_H264 && (config.codec == CODEC_HEVC || platform_supports_hevc(system));
 
-    if (IS_EMBEDDED(system)) {
-      char* mapping_env = getenv("SDL_GAMECONTROLLERCONFIG");
-      if (config.mapping == NULL && mapping_env == NULL) {
-        fprintf(stderr, "Please specify mapping file as default mapping could not be found.\n");
-        exit(-1);
-      }
-
-      struct mapping* mappings = NULL;
-      if (config.mapping != NULL)
-        mappings = mapping_load(config.mapping, config.debug_level > 0);
-
-      if (mapping_env != NULL) {
-        struct mapping* map = mapping_parse(mapping_env);
-        map->next = mappings;
-        mappings = map;
-      }
-
-      for (int i=0;i<config.inputsCount;i++) {
-        if (config.debug_level > 0)
-          printf("Add input %s...\n", config.inputs[i]);
-
-        evdev_create(config.inputs[i], mappings, config.debug_level > 0);
-      }
-
-      udev_init(!inputAdded, mappings, config.debug_level > 0);
-      evdev_init();
-      rumble_handler = evdev_rumble;
-      #ifdef HAVE_LIBCEC
-      cec_init();
-      #endif /* HAVE_LIBCEC */
-    }
     #ifdef HAVE_SDL
-    else if (system == SDL) {
+    if (system == SDL) {
       if (config.inputsCount > 0) {
         fprintf(stderr, "You can't select input devices as SDL will automatically use all available controllers\n");
         exit(-1);
