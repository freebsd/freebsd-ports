--- artiste.cc.orig	2016-06-21 21:09:17 UTC
+++ artiste.cc
@@ -166,7 +166,7 @@ void Artiste::PrintMovie(Movie movie) {
   ComputeDimensions(RatioOf(movie.width(), movie.height()));
   movie.PrepareRGB(width_, height_);
   HideCursor();
-  sighandler_t old_handler = signal(SIGINT, OnCtrlC);
+  sig_t old_handler = signal(SIGINT, OnCtrlC);
   for (auto graphic : movie) {
     if (g_done) {
       break;
