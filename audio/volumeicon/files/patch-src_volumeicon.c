--- src/volumeicon.c.orig	2015-03-02 23:54:36.000000000 +0100
+++ src/volumeicon.c	2017-12-18 17:23:45.237664000 +0100
@@ -1295,6 +1295,8 @@ int main(int argc, char * argv[])
 	backend_get_mute = &oss_get_mute;
 	backend_get_channel = &oss_get_channel;
 	backend_get_channel_names = &oss_get_channel_names;
+	backend_get_device = &oss_get_device;
+	backend_get_device_names = &oss_get_device_names;
 	#else
 	backend_setup = &asound_setup;
 	backend_set_channel = &asound_set_channel;
