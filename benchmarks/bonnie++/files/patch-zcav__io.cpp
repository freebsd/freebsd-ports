--- zcav_io.cpp.orig	2012-11-23 07:34:43 UTC
+++ zcav_io.cpp
@@ -83,7 +83,6 @@ int ZcavRead::Read(int max_loops, int ma
   for(int loops = 0; !exiting && loops < max_loops; loops++)
   {
     int i = 0;
-#ifdef _LARGEFILE64_SOURCE
     if(start_offset)
     {
       OFF_TYPE real_offset = OFF_TYPE(start_offset) * OFF_TYPE(m_block_size) * OFF_TYPE(1<<20);
@@ -96,7 +95,6 @@ int ZcavRead::Read(int max_loops, int ma
       i = start_offset;
     }
     else
-#endif
     if(lseek(m_fd, 0, SEEK_SET))
     {
       fprintf(stderr, "Can't lseek().\n");
@@ -224,14 +222,12 @@ ssize_t ZcavRead::access_all(int count)
 // Read/write a block of data
 double ZcavRead::access_data(int skip)
 {
-#ifdef _LARGEFILE64_SOURCE
   if(skip)
   {
     OFF_TYPE real_offset = OFF_TYPE(skip) * OFF_TYPE(m_block_size) * OFF_TYPE(1<<20);
     if(file_lseek(m_fd, real_offset, SEEK_CUR) == OFF_TYPE(-1))
       return -1.0;
   }
-#endif
 
   m_dur.start();
   for(int i = 0; i < m_block_size; i+= m_chunk_size)
