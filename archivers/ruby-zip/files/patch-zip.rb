--- zip.rb.orig	Sat Mar 30 02:15:47 2002
+++ zip.rb	Fri Mar 28 05:03:01 2003
@@ -173,7 +173,7 @@
   class Inflater < Decompressor
     def initialize(inputStream)
       super
-      @zlibInflater = Zlib::Inflate.new(-Zlib::Inflate::MAX_WBITS)
+      @zlibInflater = Zlib::Inflate.new(-Zlib::MAX_WBITS)
       @outputBuffer=""
       @hasReturnedEmptyString = false
     end
@@ -621,7 +621,7 @@
   class Deflater < Compressor
     def initialize(outputStream, level = Zlib::DEFAULT_COMPRESSION)
       @outputStream = outputStream
-      @zlibDeflater = Zlib::Deflate.new(level, -Zlib::Deflate::MAX_WBITS)
+      @zlibDeflater = Zlib::Deflate.new(level, -Zlib::MAX_WBITS)
       @size = 0
       @crc = Zlib::crc32
     end
