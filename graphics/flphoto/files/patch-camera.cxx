--- camera.cxx.orig	2008-09-15 21:32:33.000000000 +0800
+++ camera.cxx	2008-09-15 21:33:49.000000000 +0800
@@ -42,6 +42,7 @@
 #  define fl_mkdir(p)	mkdir(p)
 #else
 #  include <unistd.h>
+#  include <sys/stat.h>
 #  define fl_mkdir(p)	mkdir(p, 0777)
 #endif // WIN32 && !__CYGWIN__
 #include <errno.h>
@@ -63,8 +64,7 @@
 static void	get_files(Camera *camera, const char *folder,
 		          CameraList *list, GPContext *context);
 static unsigned	progress_start(GPContext *context, float target,
-			       const char *format, va_list args,
-        		       void *data);
+			       const char *format, void *data);
 static void	progress_update(GPContext *context, unsigned id, float current,
 		                void *data);
 static void	purge_thumbnails(void);
@@ -909,7 +909,6 @@
 progress_start(GPContext  *context,	// I - Current context
                float      target,	// I - Target size
 	       const char *format,	// I - Progress text, if any
-	       va_list    args,		// I - Pointer to additional args
                void       *data)	// I - Callback data
 {
   Fl_Progress	*p = (Fl_Progress *)data;
