--- Makefile.inc.orig	Thu Feb 26 12:27:32 2004
+++ Makefile.inc	Thu Feb 26 11:33:27 2004
@@ -6,7 +6,7 @@
 CFLAGS += `glib-config --cflags` `gtk-config --cflags`
 
 $(PLUGIN_FILE): $(OBJECTS)
-	$(CC) -o $@ $^ -L ffmpeg-strip-wma -lffwma -lxmms -shared
+	$(CC) -o $@ $^ -L ffmpeg-strip-wma -lffwma -shared ` xmms-config --libs`
 
 $(OBJDIR)/%.o: %.c
 	$(CC) -c -o $@ $(CFLAGS) $<
