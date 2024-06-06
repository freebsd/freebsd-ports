Fix build with Taglib 2.x

Based on patch from Arch Linux:
https://gitlab.archlinux.org/archlinux/packaging/packages/easytag/-/blob/main/taglib-2.patch?ref_type=heads

--- src/tags/gio_wrapper.cc.orig	2016-06-24 14:57:32 UTC
+++ src/tags/gio_wrapper.cc
@@ -47,11 +47,11 @@ TagLib::ByteVector
 }
 
 TagLib::ByteVector
-GIO_InputStream::readBlock (TagLib::ulong len)
+GIO_InputStream::readBlock (unsigned long len)
 {
     if (error)
     {
-        return TagLib::ByteVector::null;
+        return TagLib::ByteVector();
     }
 
     TagLib::ByteVector rv (len, 0);
@@ -70,14 +70,24 @@ GIO_InputStream::insert (TagLib::ByteVector const &dat
 
 void
 GIO_InputStream::insert (TagLib::ByteVector const &data,
-                         TagLib::ulong start,
-                         TagLib::ulong replace)
+#if TAGLIB_MAJOR_VERSION >= 2
+                         TagLib::offset_t start,
+                         size_t replace)
+#else
+                         unsigned long start,
+                         unsigned long replace)
+#endif
+
 {
     g_warning ("%s", "Trying to write to read-only file!");
 }
 
 void
-GIO_InputStream::removeBlock (TagLib::ulong start, TagLib::ulong len)
+#if TAGLIB_MAJOR_VERSION >= 2
+GIO_InputStream::removeBlock (TagLib::offset_t start, size_t len)
+#else
+GIO_InputStream::removeBlock (unsigned long start, unsigned long len)
+#endif
 {
     g_warning ("%s", "Trying to write to read-only file!");
 }
@@ -200,11 +210,11 @@ TagLib::ByteVector
 }
 
 TagLib::ByteVector
-GIO_IOStream::readBlock (TagLib::ulong len)
+GIO_IOStream::readBlock (unsigned long len)
 {
     if (error)
     {
-        return TagLib::ByteVector::null;
+        return TagLib::ByteVector();
     }
 
     gsize bytes = 0;
@@ -239,8 +249,14 @@ GIO_IOStream::insert (TagLib::ByteVector const &data,
 
 void
 GIO_IOStream::insert (TagLib::ByteVector const &data,
-                      TagLib::ulong start,
-                      TagLib::ulong replace)
+#if TAGLIB_MAJOR_VERSION >= 2
+                      TagLib::offset_t start,
+                      size_t replace)
+#else
+                      unsigned long start,
+                      unsigned long replace)
+#endif
+
 {
     if (error)
     {
@@ -278,7 +294,7 @@ GIO_IOStream::insert (TagLib::ByteVector const &data,
     seek (0);
 
     while (g_input_stream_read_all (istream, buffer,
-                                    MIN (G_N_ELEMENTS (buffer), start),
+                                    MIN (G_N_ELEMENTS (buffer), (unsigned long)start),
                                     &r, NULL, &error) && r > 0)
     {
         gsize w;
@@ -351,9 +367,13 @@ void
 }
 
 void
-GIO_IOStream::removeBlock (TagLib::ulong start, TagLib::ulong len)
+#if TAGLIB_MAJOR_VERSION >= 2
+GIO_IOStream::removeBlock (TagLib::offset_t start, size_t len)
+#else
+GIO_IOStream::removeBlock (unsigned long start, unsigned long len)
+#endif
 {
-    if (start + len >= (TagLib::ulong)length ())
+    if (start + len >= (unsigned long)length ())
     {
         truncate (start);
         return;
