--- src/main.c.orig	2017-07-02 11:38:48 UTC
+++ src/main.c
@@ -113,13 +113,8 @@ static void stream(PSERVER_DATA server, PCONFIGURATION
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
 
@@ -160,7 +155,6 @@ static void help() {
   printf("\t-surround\t\tStream 5.1 surround sound (requires GFE 2.7)\n");
   printf("\t-keydir <directory>\tLoad encryption keys from directory\n");
   printf("\t-mapping <file>\t\tUse <file> as gamepad mappings configuration file\n");
-  printf("\t-platform <system>\tSpecify system used for audio, video and input: pi/imx/aml/x11/x11_vdpau/sdl/fake (default auto)\n");
   printf("\t-unsupported\t\tTry streaming if GFE version or options are unsupported\n");
   #if defined(HAVE_SDL) || defined(HAVE_X11)
   printf("\n WM options (SDL and X11 only)\n\n");
@@ -199,12 +193,8 @@ int main(int argc, char* argv[]) {
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
@@ -251,38 +241,8 @@ int main(int argc, char* argv[]) {
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
