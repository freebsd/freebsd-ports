--- hfaxd/FileTransfer.c++.orig	2009-12-28 20:05:40.000000000 +0100
+++ hfaxd/FileTransfer.c++	2010-08-26 21:47:16.000000000 +0200
@@ -65,11 +65,31 @@
 static 	const char* strunames[] =  { "File", "Record", "Page", "TIFF" };
 static 	const char* modenames[] =  { "Stream", "Block", "Compressed", "ZIP" };
 
+extern "C" {
+/*
+ * TIFF Image File Directories are comprised of a table of field
+ * descriptors of the form shown below.  The table is sorted in
+ * ascending order by tag.  The values associated with each entry are
+ * disjoint and may appear anywhere in the file (so long as they are
+ * placed on a word boundary).
+ *
+ * If the value is 4 bytes or less, then it is placed in the offset
+ * field to save space.  If the value is less than 4 bytes, it is
+ * left-justified in the offset field.
+ */
+typedef struct {
+        uint16          tdir_tag;       /* see below */
+        uint16          tdir_type;      /* data type; see below */
+        uint32          tdir_count;     /* number of items; length in spec */
+        uint32          tdir_offset;    /* byte offset to field data */
+} TIFFDirEntry;
+}
+
 #define	N(a)	(sizeof (a) / sizeof (a[0]))
 
 
 static bool
-isTIFF(const TIFFHeader& h)
+isTIFF(const TIFFHeaderClassic& h)
 {
     if (h.tiff_magic != TIFF_BIGENDIAN && h.tiff_magic != TIFF_LITTLEENDIAN)
 	return (false);
@@ -82,7 +102,7 @@
     // byte swap version stamp if opposite byte order
     if ((u.c[0] == 0) ^ (h.tiff_magic == TIFF_BIGENDIAN))
 	TIFFSwabShort(&version);
-    return (version == TIFF_VERSION);
+    return (version == TIFF_VERSION_CLASSIC);
 }
 
 
@@ -229,7 +249,7 @@
 		uint32* sb;
 		TIFFGetField(tif, TIFFTAG_STRIPBYTECOUNTS, &sb);
 		file_size = sizeof (DirTemplate) +
-		    sizeof (TIFFHeader) + sizeof (uint16);
+		    sizeof (TIFFHeaderClassic) + sizeof (uint16);
 		for (tstrip_t s = 0, ns = TIFFNumberOfStrips(tif); s < ns; s++)
 		    file_size += sb[s];
 		reply(code, "%s for %s (%lu bytes).",
@@ -261,10 +281,10 @@
 	if (fd >= 0) {
 	    union {
 		char buf[512];
-		TIFFHeader h;
+		TIFFHeaderClassic h;
 	    } b;
 	    ssize_t cc = Sys::read(fd, (char*) &b, sizeof (b));
-	    if (cc > (ssize_t)sizeof (b.h) && b.h.tiff_version == TIFF_VERSION &&
+	    if (cc > (ssize_t)sizeof (b.h) && b.h.tiff_version == TIFF_VERSION_CLASSIC &&
 	      (b.h.tiff_magic == TIFF_BIGENDIAN ||
 	       b.h.tiff_magic == TIFF_LITTLEENDIAN)) {
 		(void) lseek(fd, 0L, SEEK_SET);		// rewind
@@ -343,7 +363,7 @@
 {
     static DirTemplate templ = {
 #define	TIFFdiroff(v) \
-    (uint32) (sizeof (TIFFHeader) + sizeof (uint16) + \
+    (uint32) (sizeof (TIFFHeaderClassic) + sizeof (uint16) + \
       (intptr_t) &(((DirTemplate*) 0)->v))
 	{ TIFFTAG_SUBFILETYPE,		TIFF_LONG,	1 },
 	{ TIFFTAG_IMAGEWIDTH,		TIFF_LONG,	1 },
@@ -377,14 +397,14 @@
      * of things about the contents of the TIFF file.
      */
     struct {
-	TIFFHeader h;
+	TIFFHeaderClassic h;
 	uint16	dircount;
 	u_char	dirstuff[sizeof (templ)];
     } buf;
     union { int32 i; char c[4]; } u; u.i = 1;
     buf.h.tiff_magic = (u.c[0] == 0 ? TIFF_BIGENDIAN : TIFF_LITTLEENDIAN);
-    buf.h.tiff_version = TIFF_VERSION;
-    buf.h.tiff_diroff = sizeof (TIFFHeader);
+    buf.h.tiff_version = TIFF_VERSION_CLASSIC;
+    buf.h.tiff_diroff = sizeof (TIFFHeaderClassic);
     buf.dircount = (uint16) NTAGS;
     getLong(tif, templ.SubFileType);
     getLong(tif, templ.ImageWidth);
@@ -957,7 +977,7 @@
 	if (FileCache::lookup(docname, sb) && S_ISREG(sb.st_mode)) {
 	    union {
 		char buf[512];
-		TIFFHeader h;
+		TIFFHeaderClassic h;
 	    } b;
 	    ssize_t cc = Sys::read(fd, (char*) &b, sizeof (b));
 	    if (cc > 2 && b.buf[0] == '%' && b.buf[1] == '!')
