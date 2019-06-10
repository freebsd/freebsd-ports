--- src/Network.cpp.orig	2019-06-09 23:58:33 UTC
+++ src/Network.cpp
@@ -475,7 +475,7 @@ void Network::select_precision(int channels) {
 
 void Network::initialize(int playouts, const std::string & weightsfile) {
 #ifdef USE_BLAS
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #ifdef USE_OPENBLAS
     openblas_set_num_threads(1);
     myprintf("BLAS Core: %s\n", openblas_get_corename());
