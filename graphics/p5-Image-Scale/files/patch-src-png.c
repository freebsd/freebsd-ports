--- src/png.c	2011-07-12 01:03:28.000000000 +1000
+++ src/png.c	2012-10-04 01:53:55.000000000 +1000
@@ -40,7 +40,7 @@
     }
  }
 
- png_memcpy(data, buffer_ptr(im->buf), len);
+ memcpy(data, buffer_ptr(im->buf), len);
  buffer_consume(im->buf, len);
  
  goto ok;



