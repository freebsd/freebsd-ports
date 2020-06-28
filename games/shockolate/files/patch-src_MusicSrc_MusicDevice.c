--- src/MusicSrc/MusicDevice.c.orig	2020-04-23 04:29:54 UTC
+++ src/MusicSrc/MusicDevice.c
@@ -1023,9 +1023,10 @@ static int FluidMidiInit(MusicDevice *dev, const unsig
     fluid_settings_t *settings;
     fluid_synth_t *synth;
     int sfid;
-    char fileName[1024] = "res/";
+    char fileName[1024] = "%%MIDIDIR%%";
+    size_t dirlen = strlen (fileName);
 
-    FluidMidiGetOutputName(dev, outputIndex, &fileName[4], 1020);
+    FluidMidiGetOutputName(dev, outputIndex, &fileName[dirlen], 1024 - dirlen);
     if (strlen(fileName) == 4)
     {
         WARN("Failed to locate SoundFont for outputIndex=%d", outputIndex);
@@ -1184,19 +1185,20 @@ static unsigned int FluidMidiGetOutputCount(MusicDevic
         FindClose(hFind);
     }
 #else
-    DIR *dirp = opendir("res");
+    DIR *dirp = opendir("%%MIDIDIR%%");
     struct dirent *dp = 0;
-    while ((dp = readdir(dirp)))
-    {
-        char *filename = dp->d_name;
-        char namelen = strlen(filename);
-        if (namelen < 4) continue; // ".sf2"
-        if (strcasecmp(".sf2", (char*)(filename + (namelen - 4)))) continue;
-        // found one
-        // INFO("Counting SoundFont file: %s", filename);
-        ++outputCount;
+    if (dirp != NULL) {
+        while ((dp = readdir(dirp))) {
+            char *filename = dp->d_name;
+            char namelen = strlen(filename);
+            if (namelen < 4) continue; // ".sf2"
+            if (strcasecmp(".sf2", (char*)(filename + (namelen - 4)))) continue;
+            // found one
+            // INFO("Counting SoundFont file: %s", filename);
+            ++outputCount;
+        }
+        closedir(dirp);
     }
-    closedir(dirp);
 #endif
 
     // suppress compiler warnings
@@ -1237,24 +1239,26 @@ static void FluidMidiGetOutputName(MusicDevice *dev, c
     unsigned int outputCount = 0; // subtract 1 to get index
     // count .sf2 files in res/ subdirectory until we find the one that the user
     //  probably wants
-    DIR *dirp = opendir("res");
-    struct dirent *dp = 0;
-    while ((outputCount <= outputIndex) &&
-           (dp = readdir(dirp)))
-    {
-        char *filename = dp->d_name;
-        char namelen = strlen(filename);
-        if (namelen < 4) continue; // ".sf2"
-        if (strcasecmp(".sf2", (char*)(filename + (namelen - 4)))) continue;
-        // found one
-        // INFO("Counting SoundFont file: %s", filename);
-        ++outputCount;
-        if (outputCount - 1 != outputIndex) continue;
-        // found it
-        strncpy(buffer, filename, bufferSize - 1);
-        // INFO("Found SoundFont file for outputIndex=%d: %s", outputIndex, filename);
+    DIR *dirp = opendir("%%MIDIDIR%%");
+
+    if (dirp != NULL) {
+        struct dirent *dp = 0;
+        while ((outputCount <= outputIndex) &&
+               (dp = readdir(dirp))) {
+            char *filename = dp->d_name;
+            char namelen = strlen(filename);
+            if (namelen < 4) continue; // ".sf2"
+            if (strcasecmp(".sf2", (char*)(filename + (namelen - 4)))) continue;
+            // found one
+            // INFO("Counting SoundFont file: %s", filename);
+            ++outputCount;
+            if (outputCount - 1 != outputIndex) continue;
+            // found it
+            strncpy(buffer, filename, bufferSize - 1);
+            // INFO("Found SoundFont file for outputIndex=%d: %s", outputIndex, filename);
+        }
+        closedir(dirp);
     }
-    closedir(dirp);
 #endif
     // put NULL in last position in case we filled up everything else
     *(buffer + bufferSize - 1) = '\0';
