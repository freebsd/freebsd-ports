--- utilssdl/PNG.cpp.orig	2003-03-03 03:32:18.000000000 +0100
+++ utilssdl/PNG.cpp	2012-05-09 12:16:57.000000000 +0200
@@ -13,6 +13,7 @@
 // FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details
 //
 #include <PNG.hpp>
+#include <pngpriv.h>
 
 //Save SDL surface as png
 bool PNG::Save( SDL_Surface *img, const string &filename)
@@ -72,7 +73,7 @@
 	return false;
     }
 
-    if( setjmp(_png->jmpbuf))
+    if( setjmp(png_jmpbuf(_png)))
     {
 	fclose( fp);
 	png_destroy_write_struct(&_png, (png_infopp)NULL);
