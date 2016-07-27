--- bonnie++.cpp.orig	2009-07-03 02:38:14 UTC
+++ bonnie++.cpp
@@ -73,7 +73,7 @@ public:
   void set_io_chunk_size(int size)
     { delete m_buf; pa_new(size, m_buf, m_buf_pa); m_io_chunk_size = size; }
   void set_file_chunk_size(int size)
-    { delete m_buf; m_buf = new char[__max(size, m_io_chunk_size)]; m_file_chunk_size = size; }
+    { delete m_buf; m_buf = new char[max(size, m_io_chunk_size)]; m_file_chunk_size = size; }
 
   // Return the page-aligned version of the local buffer
   char *buf() { return m_buf_pa; }
@@ -138,7 +138,7 @@ CGlobalItems::CGlobalItems(bool *exitFla
  , m_buf(NULL)
  , m_buf_pa(NULL)
 {
-  pa_new(__max(m_io_chunk_size, m_file_chunk_size), m_buf, m_buf_pa);
+  pa_new(max(m_io_chunk_size, m_file_chunk_size), m_buf, m_buf_pa);
   SetName(".");
 }
 
@@ -294,11 +294,7 @@ int main(int argc, char *argv[])
       {
         char *sbuf = _strdup(optarg);
         char *size = strtok(sbuf, ":");
-#ifdef _LARGEFILE64_SOURCE
         file_size = size_from_str(size, "gt");
-#else
-        file_size = size_from_str(size, "g");
-#endif
         size = strtok(NULL, "");
         if(size)
         {
@@ -384,17 +380,8 @@ int main(int argc, char *argv[])
     if(file_size % 1024 > 512)
       file_size = file_size + 1024 - (file_size % 1024);
   }
-#ifndef _LARGEFILE64_SOURCE
-  if(file_size == 2048)
-    file_size = 2047;
-  if(file_size > 2048)
-  {
-    fprintf(stderr, "Large File Support not present, can't do %dM.\n", file_size);
-    usage();
-  }
-#endif
-  globals.byte_io_size = __min(file_size, globals.byte_io_size);
-  globals.byte_io_size = __max(0, globals.byte_io_size);
+  globals.byte_io_size = min(file_size, globals.byte_io_size);
+  globals.byte_io_size = max(0, globals.byte_io_size);
 
   if(machine == NULL)
   {
@@ -465,14 +452,6 @@ int main(int argc, char *argv[])
      && (directory_max_size < directory_min_size || directory_max_size < 0
      || directory_min_size < 0) )
     usage();
-#ifndef _LARGEFILE64_SOURCE
-  if(file_size > (1 << (31 - 20 + globals.io_chunk_bits)) )
-  {
-    fprintf(stderr
-   , "The small chunk size and large IO size make this test impossible in 32bit.\n");
-    usage();
-  }
-#endif
   if(file_size && globals.ram && (file_size * concurrency) < (globals.ram * 2) )
   {
     fprintf(stderr
