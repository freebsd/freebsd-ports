--- src/main.cpp.orig	2019-11-13 08:52:44 UTC
+++ src/main.cpp
@@ -13,6 +13,7 @@
 #include "viewer.h"
 
 #include <GLFW/glfw3.h>
+#include <png.h>
 
 #include <clocale>
 #include <cstdio>
@@ -148,6 +149,64 @@ namespace
         ::printf("(EE) GLFW error (%d) '%s'\n", e, error);
     }
 
+    // Based on https://gist.github.com/niw/5963798
+    void load_png_icon(const char *filename, GLFWimage *icon)
+    {
+        png_byte color_type;
+        png_byte bit_depth;
+
+        FILE *fp = fopen(filename, "rb");
+        if (!fp) return;
+
+        png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
+        if (!png) return;
+        png_infop info = png_create_info_struct(png);
+        if (!info) return;
+        if (setjmp(png_jmpbuf(png))) return;
+
+        png_init_io(png, fp);
+        png_read_info(png, info);
+
+        icon->width = png_get_image_width(png, info);
+        icon->height = png_get_image_height(png, info);
+        color_type = png_get_color_type(png, info);
+        bit_depth = png_get_bit_depth(png, info);
+
+        // Read any color_type into 8bit depth, RGBA format.
+        // See http://www.libpng.org/pub/png/libpng-manual.txt
+        if (bit_depth == 16)
+            png_set_strip_16(png);
+        if (color_type == PNG_COLOR_TYPE_PALETTE)
+            png_set_palette_to_rgb(png);
+        // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16 bit depth.
+        if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
+            png_set_expand_gray_1_2_4_to_8(png);
+        if (png_get_valid(png, info, PNG_INFO_tRNS))
+            png_set_tRNS_to_alpha(png);
+        // These color_type don't have an alpha channel then fill it with 0xFF.
+        if (color_type == PNG_COLOR_TYPE_RGB ||
+          color_type == PNG_COLOR_TYPE_GRAY ||
+          color_type == PNG_COLOR_TYPE_PALETTE)
+            png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
+        if (color_type == PNG_COLOR_TYPE_GRAY ||
+          color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
+            png_set_gray_to_rgb(png);
+        png_read_update_info(png, info);
+
+        // Allocate contiguous memory region; caller has to delete[].
+        icon->pixels = new unsigned char[icon->width * icon->height * 4];
+
+        auto *row_pointers = new png_bytep[icon->height];
+        png_byte bpr = png_get_rowbytes(png, info);
+        for (int y = 0; y < icon->height; y++)
+            row_pointers[y] = icon->pixels + y * bpr;
+
+        png_read_image(png, row_pointers);
+        delete[] row_pointers;
+        png_destroy_read_struct(&png, &info, NULL);
+        fclose(fp);
+    }
+
     void setup(GLFWwindow* window)
     {
         glfwMakeContextCurrent(window);
@@ -173,6 +232,18 @@ namespace
 #if GLFW_VERSION_MAJOR >= 3 && GLFW_VERSION_MINOR >= 1
         glfwSetDropCallback(window, callbackDrop);
 #endif
+
+        GLFWimage icons[3];
+
+        load_png_icon("%%DATADIR%%/Icon-1024.png", &icons[0]);
+        load_png_icon("%%DATADIR%%/Icon-32.png", &icons[1]);
+        load_png_icon("%%DATADIR%%/Icon-16.png", &icons[2]);
+
+        glfwSetWindowIcon(window, 3, icons);
+
+        delete[] icons[2].pixels;
+        delete[] icons[1].pixels;
+        delete[] icons[0].pixels;
     }
 
     GLFWwindow* createWindowedWindow(int width, int height, GLFWwindow* parent, const sConfig& config)
