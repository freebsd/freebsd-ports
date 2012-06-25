--- ../svxlink-11.05.orig/qtel/Settings.cpp	2010-02-21 15:01:06.000000000 -0800
+++ qtel/Settings.cpp	2012-05-28 10:27:56.000000000 -0700
@@ -119,9 +119,9 @@
 #define CONF_LIST_REFRESH_TIME_DEFAULT	5
 #define CONF_START_AS_BUSY_DEFAULT    	false
 
-#define CONF_AUDIO_DEVICE_DEFAULT 	"alsa:default"
+#define CONF_AUDIO_DEVICE_DEFAULT 	"oss:/dev/dsp"
 #define CONF_USE_FULL_DUPLEX_DEFAULT    false
-#define CONF_CONNECT_SOUND_DEFAULT 	"/usr/share/qtel/sounds/connect.raw"
+#define CONF_CONNECT_SOUND_DEFAULT 	"%%LOCALBASE%%/share/qtel/sounds/connect.raw"
 
 #define CONF_CHAT_ENCODING_DEFAULT	"ISO8859-1"
 
