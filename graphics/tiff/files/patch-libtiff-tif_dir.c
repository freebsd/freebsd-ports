--- libtiff/tif_dir.c.orig	Tue Sep 30 08:13:07 2003
+++ libtiff/tif_dir.c	Mon Dec  1 15:36:11 2003
@@ -607,18 +607,18 @@
 	va_end(ap);
 	return (status);
 badvalue:
-	TIFFError(module, "%.1000s: Bad value %d for \"%s\"", v,
-		  tif->tif_name, _TIFFFieldWithTag(tif, tag)->field_name);
+	TIFFError(module, "%.1000s: Bad value %d for \"%s\"",
+		  tif->tif_name, v, _TIFFFieldWithTag(tif, tag)->field_name);
 	va_end(ap);
 	return (0);
 badvalue32:
-	TIFFError(module, "%.1000s: Bad value %ld for \"%s\"", v32,
-		   tif->tif_name, _TIFFFieldWithTag(tif, tag)->field_name);
+	TIFFError(module, "%.1000s: Bad value %ld for \"%s\"",
+		   tif->tif_name, v32, _TIFFFieldWithTag(tif, tag)->field_name);
 	va_end(ap);
 	return (0);
 badvaluedbl:
-	TIFFError(module, "%.1000s: Bad value %f for \"%s\"", d,
-		  tif->tif_name, _TIFFFieldWithTag(tif, tag)->field_name);
+	TIFFError(module, "%.1000s: Bad value %f for \"%s\"",
+		  tif->tif_name, d, _TIFFFieldWithTag(tif, tag)->field_name);
 	va_end(ap);
 	return (0);
 }
