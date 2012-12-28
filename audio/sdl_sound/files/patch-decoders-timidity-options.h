--- decoders/timidity/options.h.orig      2008-04-17 21:56:20.000000000 +0400
+++ decoders/timidity/options.h    2012-12-04 01:38:58.000000000 +0400
@@ -80,7 +80,7 @@
 #define MAX_AMPLIFICATION 800
 
 /* The TiMidity configuration file */
-#define CONFIG_FILE "timidity.cfg"
+#define CONFIG_FILE "%%PREFIX%%/share/timidity/timidity.cfg"
 
 /* These affect general volume */
 #define GUARD_BITS 3
