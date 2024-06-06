Fix build with Taglib 2.x

Based on patch from Arch Linux:
https://gitlab.archlinux.org/archlinux/packaging/packages/easytag/-/blob/main/taglib-2.patch?ref_type=heads

--- src/tags/gio_wrapper.h.orig	2016-06-24 14:57:32 UTC
+++ src/tags/gio_wrapper.h
@@ -33,10 +33,15 @@ class GIO_InputStream : public TagLib::IOStream (publi
     GIO_InputStream (GFile *file_);
     virtual ~GIO_InputStream ();
     virtual TagLib::FileName name () const;
-    virtual TagLib::ByteVector readBlock (TagLib::ulong length);
+    virtual TagLib::ByteVector readBlock (unsigned long length);
     virtual void writeBlock (TagLib::ByteVector const &data);
-    virtual void insert (TagLib::ByteVector const &data, TagLib::ulong start = 0, TagLib::ulong replace = 0);
-    virtual void removeBlock (TagLib::ulong start = 0, TagLib::ulong length = 0);
+#if TAGLIB_MAJOR_VERSION >= 2
+    virtual void insert (TagLib::ByteVector const &data, TagLib::offset_t start = 0, size_t replace = 0);
+    virtual void removeBlock (TagLib::offset_t start = 0, size_t length = 0);
+#else
+    virtual void insert (TagLib::ByteVector const &data, unsigned long start = 0, unsigned long replace = 0);
+    virtual void removeBlock (unsigned long start = 0, unsigned long length = 0);
+#endif
     virtual bool readOnly () const;
     virtual bool isOpen () const;
     virtual void seek (long int offset, TagLib::IOStream::Position p = TagLib::IOStream::Beginning);
@@ -61,10 +66,15 @@ class GIO_IOStream : public TagLib::IOStream (public)
     GIO_IOStream (GFile *file_);
     virtual ~GIO_IOStream ();
     virtual TagLib::FileName name () const;
-    virtual TagLib::ByteVector readBlock (TagLib::ulong length);
+    virtual TagLib::ByteVector readBlock (unsigned long length);
     virtual void writeBlock (TagLib::ByteVector const &data);
-    virtual void insert (TagLib::ByteVector const &data, TagLib::ulong start = 0, TagLib::ulong replace = 0);
-    virtual void removeBlock (TagLib::ulong start = 0, TagLib::ulong len = 0);
+#if TAGLIB_MAJOR_VERSION >= 2
+    virtual void insert (TagLib::ByteVector const &data, TagLib::offset_t start = 0, size_t replace = 0);
+    virtual void removeBlock (TagLib::offset_t start = 0, size_t len = 0);
+#else
+    virtual void insert (TagLib::ByteVector const &data, unsigned long start = 0, unsigned long replace = 0);
+    virtual void removeBlock (unsigned long start = 0, unsigned long len = 0);
+#endif
     virtual bool readOnly () const;
     virtual bool isOpen () const;
     virtual void seek (long int offset, TagLib::IOStream::Position p = TagLib::IOStream::Beginning);
