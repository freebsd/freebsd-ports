--- src/sound.cc.orig	2010-04-07 17:42:43.000000000 +0400
+++ src/sound.cc	2010-04-07 17:44:00.000000000 +0400
@@ -31,7 +31,7 @@
     ALenum error = alGetError();
     if (error != AL_NO_ERROR) {
         ls_error("OpenAL Error %d", error);
-        const ALbyte * errtxt = alGetString(error);
+        const ALchar * errtxt = alGetString(error);
         error = alGetError();
         if (error == AL_NO_ERROR) {
             ls_error(": %s \n", errtxt);
@@ -318,7 +318,7 @@
     ALCenum error = alcGetError(dev);
     if (error != ALC_NO_ERROR) {
         ls_error("OpenAL (ALC) Error %d", error);
-        const ALbyte * errtxt = alcGetString(NULL,error);
+        const ALCchar * errtxt = alcGetString(NULL,error);
         error = alcGetError(dev);
         if (error == ALC_NO_ERROR) {
             ls_error(": %s \n", errtxt);
@@ -340,7 +340,7 @@
     if (device == NULL ) {
         throw std::runtime_error("SoundMan: Failed to initialize Sound subsystem.");
     } else {
-        const ALCbyte * device_specifier =
+        const ALCchar * device_specifier =
             alcGetString(device, ALC_DEVICE_SPECIFIER);
         check(device);
         ls_message("  Using device \"%s\"\n", device_specifier);
