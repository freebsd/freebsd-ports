--- toycars_track_editor/src/TrackView.cxx.orig	2009-06-28 03:13:24 UTC
+++ toycars_track_editor/src/TrackView.cxx
@@ -89,7 +89,7 @@ TiXmlDocument *findXMLFile(const char *f
 //{jpg,png,bmp,pnm,pbm,pgm,ppm}
 Fl_Image* loadImage(const char *filename)
 {
-   char *suffix = strrchr(filename, '.');
+   const char *suffix = strrchr(filename, '.');
    if (suffix == NULL)
       return NULL;
    if (strcmp(suffix,".jpg") == 0)
@@ -956,8 +956,8 @@ void TrackView::importImage(const char *
 // installs map into user data directory
 void TrackView::installMap(const char *name)
 {
-#ifdef WIN32
-   fl_alert("Unfortunately this is unsupported on Windows at this time.\nYou may still install maps manually by saving them to a folder and placing it inside the data\\tracks directory and editing the tracklist.xml file.");
+#if 1
+   fl_alert("Unfortunately this is unsupported at this time.\nYou may still install maps manually by saving them to a folder and placing it inside the data\\tracks directory and editing the tracklist.xml file.");
    return;
 #else
    char fullname[1024];
@@ -1033,8 +1033,8 @@ void TrackView::installMap(const char *n
 // nb: doesn't remove track data itself, only remove entry from tracklist xml file.
 void TrackView::uninstallMap(const char *name)
 {
-#ifdef WIN32
-   fl_alert("Unfortunately this is unsupported on Windows at this time.\nYou may still uninstall maps manually by removing them from the data\\tracks directory and editing the tracklist.xml file.");
+#if 1
+   fl_alert("Unfortunately this is unsupported at this time.\nYou may still uninstall maps manually by removing them from the data\\tracks directory and editing the tracklist.xml file.");
    return;
 #else
    char fullname[1024];
