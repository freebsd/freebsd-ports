--- src/misc/gfx_util.c.orig	2007-11-02 12:28:22.000000000 +0100
+++ src/misc/gfx_util.c	2007-11-02 12:32:42.000000000 +0100
@@ -138,14 +138,14 @@
                          *(__u8 *)dst++ = *src >> 24;
                          src++;
                     }
-                    (__u8 *)dst += dskip;
+                    dst = (__u8 *)dst + dskip;
                }
                break;
 
           case DSPF_ARGB:
                for (y = 0; y < h; y++) {
                     dfb_memcpy (dst, src, w * 4);
-                    (__u8 *)dst += w * 4 + dskip;
+                    dst = (__u8 *)dst + (w * 3 + dskip);
                     src += w;
                }
                break;
@@ -174,10 +174,10 @@
                                                   a, dst_format, palette);
                               break;
                          }
-                         (__u8 *)dst += DFB_BYTES_PER_PIXEL (dst_format);
+                         dst = (__u8 *)dst + (DFB_BYTES_PER_PIXEL (dst_format));
                          src++;
                     }
-                    (__u8 *)dst += dskip;
+                    dst = (__u8 *)dst + dskip;
                }
                break;
      }
@@ -380,7 +380,7 @@
           x += x_step;
      }
 
-     return dst;
+     return (char *)dst;
 }
 
 void dfb_scale_linear_32( void *dst, __u32 *src, int sw, int sh,
@@ -446,9 +446,9 @@
                y_start++;
           }
 
-          (__u8 *)outbuf =
+          outbuf =
           dst + i * (DFB_BYTES_PER_PIXEL (dst_format) * dw + dskip);
-          (__u8 *)outbuf_end = outbuf + DFB_BYTES_PER_PIXEL (dst_format) * dw;
+          outbuf_end = outbuf + DFB_BYTES_PER_PIXEL (dst_format) * dw;
           x = scaled_x_offset;
           x_start = x >> SCALE_SHIFT;
           dest_x = 0;
@@ -462,7 +462,7 @@
                x += x_step;
                x_start = x >> SCALE_SHIFT;
                dest_x++;
-               (__u8 *)outbuf += DFB_BYTES_PER_PIXEL (dst_format);
+               outbuf = (__u8 *)outbuf + DFB_BYTES_PER_PIXEL (dst_format);
           }
 
           new_outbuf = scale_line (run_weights, filter.n_x, filter.n_y, outbuf,
@@ -480,7 +480,7 @@
                             x >> SCALE_SHIFT, sw, dst_format, palette);
 
                x += x_step;
-               (__u8 *)outbuf += DFB_BYTES_PER_PIXEL (dst_format);
+               outbuf = (__u8 *)outbuf + DFB_BYTES_PER_PIXEL (dst_format);
           }
 
           y += y_step;
