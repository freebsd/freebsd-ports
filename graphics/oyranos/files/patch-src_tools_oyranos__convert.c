--- src/tools/oyranos_convert.c.orig	2016-12-09 10:36:53 UTC
+++ src/tools/oyranos_convert.c
@@ -646,7 +646,8 @@ int main( int argc , char** argv )
       if(!width)
         width = 8;
       buf = calloc(sizeof(uint16_t), size*width*size*width*3);
-#pragma omp parallel for private(in,a,b,j,)
+      
+#pragma omp parallel for private(in,a,b,j)
       for(l = 0; l < size; ++l)
       {
         in[0] = floor((double) l / (size - 1) * 65535.0 + 0.5);
