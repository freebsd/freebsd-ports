--- coders/png.c.orig	2010-01-06 23:01:31.000000000 +0100
+++ coders/png.c	2012-05-10 04:50:59.000000000 +0200
@@ -75,6 +75,7 @@
 #if defined(HasPNG)
 #include "png.h"
 #include "zlib.h"
+#include "pngpriv.h"
 
 #if PNG_LIBPNG_VER > 95
 /*
@@ -1292,7 +1293,7 @@
                         "  libpng-%.1024s error: %.1024s", PNG_LIBPNG_VER_STRING,
                         message);
   (void) ThrowException2(&image->exception,CoderError,message,image->filename);
-  longjmp(ping->jmpbuf,1);
+  longjmp(png_jmpbuf(ping),1);
 }
 
 static void PNGWarningHandler(png_struct *ping,png_const_charp message)
@@ -1593,7 +1594,7 @@
       ThrowReaderException(ResourceLimitError,MemoryAllocationFailed,image);
     }
   png_pixels=(unsigned char *) NULL;
-  if (setjmp(ping->jmpbuf))
+  if (setjmp(png_jmpbuf(ping)))
     {
       /*
         PNG image is corrupt.
@@ -1955,13 +1956,13 @@
         Image has a transparent background.
       */
       transparent_color.red=
-        (Quantum)(ping_info->trans_values.red & bit_mask);
+        (Quantum)(ping_info->trans_color.red & bit_mask);
       transparent_color.green=
-        (Quantum) (ping_info->trans_values.green & bit_mask);
+        (Quantum) (ping_info->trans_color.green & bit_mask);
       transparent_color.blue=
-        (Quantum) (ping_info->trans_values.blue & bit_mask);
+        (Quantum) (ping_info->trans_color.blue & bit_mask);
       transparent_color.opacity=
-        (Quantum) (ping_info->trans_values.gray & bit_mask);
+        (Quantum) (ping_info->trans_color.gray & bit_mask);
       if (ping_info->color_type == PNG_COLOR_TYPE_GRAY)
         {
           transparent_color.red=transparent_color.opacity;
@@ -2469,7 +2470,7 @@
                     index=indexes[x];
                     if (index < ping_info->num_trans)
                       q->opacity=
-                        ScaleCharToQuantum(255-ping_info->trans[index]);
+                        ScaleCharToQuantum(255-ping_info->trans_alpha[index]);
 		    else
 		      q->opacity=OpaqueOpacity;
                     q++;
@@ -6054,7 +6055,7 @@
   AcquireSemaphoreInfo(&png_semaphore);
 #endif
 
-  if (setjmp(ping->jmpbuf))
+  if (setjmp(png_jmpbuf(ping)))
     {
       /*
         PNG write failed.
@@ -6258,13 +6259,13 @@
         /*
           Identify which colormap entry is transparent.
         */
-        ping_info->trans=MagickAllocateMemory(unsigned char *,number_colors);
-        if (ping_info->trans == (unsigned char *) NULL)
+        ping_info->trans_alpha=MagickAllocateMemory(unsigned char *,number_colors);
+        if (ping_info->trans_alpha == (unsigned char *) NULL)
           ThrowWriterException(ResourceLimitError,MemoryAllocationFailed,
                                image);
         assert(number_colors <= 256);
         for (i=0; i < (long) number_colors; i++)
-          ping_info->trans[i]=255;
+          ping_info->trans_alpha[i]=255;
         for (y=0; y < (long) image->rows; y++)
           {
             register const PixelPacket
@@ -6284,7 +6285,7 @@
 
                     index=indexes[x];
                     assert((unsigned long) index < number_colors);
-                    ping_info->trans[index]=(png_byte) (255-
+                    ping_info->trans_alpha[index]=(png_byte) (255-
                                                         ScaleQuantumToChar(p->opacity));
                   }
                 p++;
@@ -6292,14 +6293,14 @@
           }
         ping_info->num_trans=0;
         for (i=0; i < (long) number_colors; i++)
-          if (ping_info->trans[i] != 255)
+          if (ping_info->trans_alpha[i] != 255)
             ping_info->num_trans=(unsigned short) (i+1);
         if (ping_info->num_trans == 0)
           ping_info->valid&=(~PNG_INFO_tRNS);
         if (!(ping_info->valid & PNG_INFO_tRNS))
           ping_info->num_trans=0;
         if (ping_info->num_trans == 0)
-          MagickFreeMemory(ping_info->trans);
+          MagickFreeMemory(ping_info->trans_alpha);
         /*
           Identify which colormap entry is the background color.
         */
@@ -6441,12 +6442,12 @@
                   (p->opacity != OpaqueOpacity))
                 {
                   ping_info->valid|=PNG_INFO_tRNS;
-                  ping_info->trans_values.red=ScaleQuantumToShort(p->red)&mask;
-                  ping_info->trans_values.green=ScaleQuantumToShort(p->green)&mask;
-                  ping_info->trans_values.blue=ScaleQuantumToShort(p->blue)&mask;
-                  ping_info->trans_values.gray=
+                  ping_info->trans_color.red=ScaleQuantumToShort(p->red)&mask;
+                  ping_info->trans_color.green=ScaleQuantumToShort(p->green)&mask;
+                  ping_info->trans_color.blue=ScaleQuantumToShort(p->blue)&mask;
+                  ping_info->trans_color.gray=
                     (png_uint_16) ScaleQuantumToShort(PixelIntensity(p))&mask;
-                  ping_info->trans_values.index=(unsigned char)
+                  ping_info->trans_color.index=(unsigned char)
                     (ScaleQuantumToChar(MaxRGB-p->opacity));
                 }
             }
@@ -6467,7 +6468,7 @@
                     {
                       if (p->opacity != OpaqueOpacity)
                         {
-                          if (!RGBColorMatchExact(ping_info->trans_values,*p))
+                          if (!RGBColorMatchExact(ping_info->trans_color,*p))
                             {
                               break;  /* Can't use RGB + tRNS for multiple
                                          transparent colors.  */
@@ -6480,7 +6481,7 @@
                         }
                       else
                         {
-                          if (RGBColorMatchExact(ping_info->trans_values,*p))
+                          if (RGBColorMatchExact(ping_info->trans_color,*p))
                             break; /* Can't use RGB + tRNS when another pixel
                                       having the same RGB samples is
                                       transparent. */
@@ -6498,10 +6499,10 @@
               ping_info->color_type &= 0x03;  /* changes 4 or 6 to 0 or 2 */
               if (image->depth == 8)
                 {
-                  ping_info->trans_values.red&=0xff;
-                  ping_info->trans_values.green&=0xff;
-                  ping_info->trans_values.blue&=0xff;
-                  ping_info->trans_values.gray&=0xff;
+                  ping_info->trans_color.red&=0xff;
+                  ping_info->trans_color.green&=0xff;
+                  ping_info->trans_color.blue&=0xff;
+                  ping_info->trans_color.gray&=0xff;
                 }
             }
         }
@@ -6517,7 +6518,7 @@
             {
               ping_info->color_type=PNG_COLOR_TYPE_GRAY;
               if (save_image_depth == 16 && image->depth == 8)
-                ping_info->trans_values.gray*=0x0101;
+                ping_info->trans_color.gray*=0x0101;
             }
           if (image->depth > QuantumDepth)
             image->depth=QuantumDepth;
@@ -6701,13 +6702,13 @@
                       ping_info->num_trans=0;
                     if (ping_info->num_trans != 0)
                       {
-                        ping_info->trans=MagickAllocateMemory(unsigned char *,
+                        ping_info->trans_alpha=MagickAllocateMemory(unsigned char *,
                                                               number_colors);
-                        if (ping_info->trans == (unsigned char *) NULL)
+                        if (ping_info->trans_alpha == (unsigned char *) NULL)
                           ThrowWriterException(ResourceLimitError,
                                                MemoryAllocationFailed,image);
                         for (i=0; i < (long) number_colors; i++)
-                          ping_info->trans[i]=(png_byte) trans[i];
+                          ping_info->trans_alpha[i]=(png_byte) trans[i];
                       }
                   }
 
@@ -6726,10 +6727,10 @@
               image->depth=8;
             if ((save_image_depth == 16) && (image->depth == 8))
               {
-                ping_info->trans_values.red*=0x0101;
-                ping_info->trans_values.green*=0x0101;
-                ping_info->trans_values.blue*=0x0101;
-                ping_info->trans_values.gray*=0x0101;
+                ping_info->trans_color.red*=0x0101;
+                ping_info->trans_color.green*=0x0101;
+                ping_info->trans_color.blue*=0x0101;
+                ping_info->trans_color.gray*=0x0101;
               }
           }
 
@@ -6756,8 +6757,8 @@
                                   "  Setting up bKGD chunk");
           png_set_bKGD(ping,ping_info,&background);
 
-          ping_info->trans_values.gray=(png_uint_16)(maxval*
-                                                     ping_info->trans_values.gray/MaxRGB);
+          ping_info->trans_color.gray=(png_uint_16)(maxval*
+                                                    ping_info->trans_color.gray/MaxRGB);
         }
     }
   if (logging)
@@ -7332,7 +7333,7 @@
 #endif
   if (ping_info->valid & PNG_INFO_tRNS)
     {
-      MagickFreeMemory(ping_info->trans);
+      MagickFreeMemory(ping_info->trans_alpha);
       ping_info->valid&=(~PNG_INFO_tRNS);
     }
   png_destroy_write_struct(&ping,&ping_info);
@@ -8416,10 +8416,10 @@
             {
               (void) LogMagickEvent(CoderEvent,GetMagickModule(),
                                     "     TERM delay: %lu",
-                                    (png_uint_32) (mng_info->ticks_per_second*final_delay/100));
+                                    (uint64_t) (mng_info->ticks_per_second*final_delay/100));
               if (image->iterations == 0)
                 (void) LogMagickEvent(CoderEvent,GetMagickModule(),
-                                      "     TERM iterations: %lu",PNG_MAX_UINT);
+                                      "     TERM iterations: %lu", (uint64_t)PNG_MAX_UINT);
               else
                 (void) LogMagickEvent(CoderEvent,GetMagickModule(),
                                       "     Image iterations: %lu",
