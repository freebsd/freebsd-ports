-- workaround for https://gitlab.com/free-astro/siril/-/work_items/2011

--- src/io/SirilXISFReader.cpp.orig	2026-10-28 05:48:34 UTC
+++ src/io/SirilXISFReader.cpp
@@ -45,7 +45,7 @@ int siril_get_xisf_buffer(const char *filename, struct
 int siril_get_xisf_buffer(const char *filename, struct xisf_data *xdata) {
 	try {
 		LibXISF::XISFReader xisfReader;
-		xisfReader.open(filename);
+		xisfReader.open(std::string(filename));
 
 		if (xisfReader.imagesCount() == 0) {
 			xisfReader.close();
@@ -166,7 +166,7 @@ GdkPixbuf* get_thumbnail_from_xisf(char *filename, gch
 	gchar *description = NULL;
 	try {
 		LibXISF::XISFReader xisfReader;
-		xisfReader.open(filename);
+		xisfReader.open(std::string(filename));
 
 		if (xisfReader.imagesCount() == 0) {
 			xisfReader.close();
