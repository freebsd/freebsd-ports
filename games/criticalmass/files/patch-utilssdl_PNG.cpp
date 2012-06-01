--- utilssdl/PNG.cpp.orig	2004-12-18 03:41:42.000000000 +0100
+++ utilssdl/PNG.cpp	2012-05-08 07:00:15.000000000 +0200
@@ -13,6 +13,7 @@
 // FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details
 //
 #include <PNG.hpp>
+#include "pngpriv.h"
 
 //Save SDL surface as png
 bool PNG::Save( SDL_Surface *img, const string &filename)
@@ -72,7 +73,7 @@
 	return false;
     }
 
-    if( setjmp(_png->jmpbuf))
+    if( setjmp(_png->longjmp_buffer))
     {
 	fclose( fp);
 	png_destroy_write_struct(&_png, (png_infopp)NULL);
