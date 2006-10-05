--- src/readjpeg.c	Tue Mar 21 12:16:07 2006
+++ src/readjpeg.c	Wed Sep 21 21:15:01 2005
@@ -179,11 +179,13 @@
 static int have_image;
 static int width,height;
 static unsigned char *image;
+static int cmyk;
 unsigned char *ptr,*ptr2;
 int chkw,chkh;
 int f,rec;
 static int greyscale;	/* static to satisfy gcc -Wall */
 
+cmyk=0;
 greyscale=0;
 
 lineptrs=NULL;
@@ -225,6 +227,15 @@
   greyscale=1;
   }
 
+if(cinfo.jpeg_color_space==JCS_CMYK)
+  cmyk=1;
+
+if(cinfo.jpeg_color_space==JCS_YCCK)
+  {
+  cmyk=1;
+  cinfo.out_color_space=JCS_CMYK;
+  }
+
 *wp=width=cinfo.image_width;
 *hp=height=cinfo.image_height;
 
@@ -266,7 +277,7 @@
 /* this one shouldn't hurt */
 cinfo.do_block_smoothing=FALSE;
 
-if(WH_BAD(width,height) || (*imagep=image=malloc(width*height*3))==NULL)
+if(WH_BAD(width,height) || (*imagep=image=malloc(width*(height+cmyk)*3))==NULL)
   longjmp(jerr.setjmp_buffer,1);
 
 jpeg_start_decompress(&cinfo);
@@ -279,12 +290,33 @@
 for(f=0;f<height;f++,ptr+=width*3)
   lineptrs[f]=ptr;
 
-rec=cinfo.rec_outbuf_height;
-while(cinfo.output_scanline<height)
+if(!cmyk)
   {
-  f=height-cinfo.output_scanline;
-  jpeg_read_scanlines(&cinfo,lineptrs+cinfo.output_scanline,
-                      f>rec?rec:f);
+  rec=cinfo.rec_outbuf_height;
+  while(cinfo.output_scanline<height)
+    {
+    f=height-cinfo.output_scanline;
+    jpeg_read_scanlines(&cinfo,lineptrs+cinfo.output_scanline,
+                        f>rec?rec:f);
+    }
+  }
+else	/* cmyk output */
+  {
+  int tmp;
+
+  ptr=image;
+  while(cinfo.output_scanline<height)
+    {
+    jpeg_read_scanlines(&cinfo,&ptr,1);
+    ptr2=ptr;
+    for(f=0;f<width;f++,ptr+=3,ptr2+=4)
+      {
+      tmp=ptr2[3];
+      ptr[0]=(tmp*ptr2[0])/255;
+      ptr[1]=(tmp*ptr2[1])/255;
+      ptr[2]=(tmp*ptr2[2])/255;
+      }
+    }
   }
 
 free(lineptrs);
