===================================================================
RCS file: /cvsroot/enlightenment/e17/libs/imlib2/loaders/loader_bmp.c,v
retrieving revision 1.13
retrieving revision 1.15
diff -u -r1.13 -r1.15
--- loaders/loader_bmp.c	2004/02/09 01:26:03	1.13
+++ loaders/loader_bmp.c	2004/08/28 03:34:05	1.15
@@ -111,6 +111,11 @@
       fseek(f, 8, SEEK_CUR);
       ReadleLong(f, &offset);
       ReadleLong(f, &headSize);
+      if (offset >= size)
+        {
+           fclose(f);
+           return 0;
+        }
       if (headSize == 12)
         {
            ReadleShort(f, &tmpShort);
@@ -139,6 +144,12 @@
            fclose(f);
            return 0;
         }
+      
+      if ((w > 8192) || (h > 8192))
+	{
+	   fclose(f);
+	   return 0;
+	}
 
       if (bitcount < 16)
         {
@@ -146,12 +157,14 @@
            if (headSize == 12)
              {
                 ncols /= 3;
+                if (ncols > 256) ncols = 256;
                 for (i = 0; i < ncols; i++)
                    fread(&rgbQuads[i], 3, 1, f);
              }
            else
              {
                 ncols /= 4;
+                if (ncols > 256) ncols = 256;
                 fread(rgbQuads, 4, ncols, f);
              }
         }
