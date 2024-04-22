Lowering dep to webkit2gtk-4.0

--- dodo.py.orig	2024-02-17 20:49:47 UTC
+++ dodo.py
@@ -73,7 +73,7 @@ def make_birdfont(target_binary, deps):
 		--pkg gio-2.0  \
 		--pkg cairo \
 		--pkg gdk-pixbuf-2.0 \
-		--pkg webkit2gtk-4.1 \
+		--pkg webkit2gtk-4.0 \
 		--pkg libnotify \
 		--pkg xmlbird \
 		--pkg libbirdfont \
@@ -90,7 +90,7 @@ def make_birdfont(target_binary, deps):
 		$({pkg-config} --cflags glib-2.0) \
 		$({pkg-config} --cflags gdk-pixbuf-2.0) \
 		$({pkg-config} --cflags xmlbird) \
-		$({pkg-config} --cflags webkit2gtk-4.1) \
+		$({pkg-config} --cflags webkit2gtk-4.0) \
 		$({pkg-config} --cflags libnotify) \
         -o OBJECT_FILE""".format(**config.SETTINGS)
         
@@ -104,7 +104,7 @@ def make_birdfont(target_binary, deps):
 		$({pkg-config} --libs cairo-gobject) \
 		$({pkg-config} --libs glib-2.0) \
 		$({pkg-config} --libs gdk-pixbuf-2.0) \
-		$({pkg-config} --libs webkit2gtk-4.1) \
+		$({pkg-config} --libs webkit2gtk-4.0) \
 		$({pkg-config} --libs xmlbird) \
 		$({pkg-config} --libs libnotify) \
 		-L./build -L./build/bin -l birdgems \
