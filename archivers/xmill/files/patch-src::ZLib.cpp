--- src/ZLib.cpp.orig	Fri May  9 16:34:09 2003
+++ src/ZLib.cpp	Fri May  9 16:55:35 2003
@@ -125,7 +125,7 @@
       // We finish compression, if there has been some data in the queue
    {
 #ifdef USE_BZIP
-      bzCompressEnd(&state);
+      BZ2_bzCompressEnd(&state);
 #else
       deflateEnd(&state);
 #endif
@@ -175,7 +175,7 @@
    if(isinitialized==0)
    {
 #ifdef USE_BZIP
-      if(bzCompressInit(&state,7,0,0)!=BZ_OK)
+      if(BZ2_bzCompressInit(&state,7,0,0)!=BZ_OK)
 #else
       if(deflateInit(&state,zlib_compressidx)!=Z_OK)
 #endif
@@ -183,8 +183,15 @@
          Error("Error while compressing container!");
          Exit();
       }
+#ifdef USE_BZIP
+      state.total_out_lo32=0;
+      state.total_out_hi32=0;
+      state.total_in_lo32=0;
+      state.total_in_hi32=0;
+#else
       state.total_out=0;
       state.total_in=0;
+#endif
 
       isinitialized=1;
    }
@@ -205,7 +212,7 @@
          saveavail=state.avail_out;
 
 #ifdef USE_BZIP
-         if(bzCompress(&state,BZ_RUN)!=BZ_RUN_OK)
+         if(BZ2_bzCompress(&state,BZ_RUN)!=BZ_RUN_OK)
 #else
          if(deflate(&state,Z_NO_FLUSH)!=Z_OK)
 #endif
@@ -259,7 +266,7 @@
    if(isinitialized==0)
    {
 #ifdef USE_BZIP
-      if(bzCompressInit(&state,7,0,0)!=BZ_OK)
+      if(BZ2_bzCompressInit(&state,7,0,0)!=BZ_OK)
 #else
       if(deflateInit(&state,zlib_compressidx)!=Z_OK)
 #endif
@@ -267,8 +274,15 @@
          Error("Error while compressing container!");
          Exit();
       }
+#ifdef USE_BZIP
+      state.total_out_lo32=0;
+      state.total_out_hi32=0;
+      state.total_in_lo32=0;
+      state.total_in_hi32=0;
+#else
       state.total_out=0;
       state.total_in=0;
+#endif
       isinitialized=1;
    }
 
@@ -278,7 +292,7 @@
 
       // The actual compression
 #ifdef USE_BZIP
-      if(bzCompress(&state,BZ_RUN)!=BZ_RUN_OK)
+      if(BZ2_bzCompress(&state,BZ_RUN)!=BZ_RUN_OK)
 #else
       if(deflate(&state,Z_NO_FLUSH)!=Z_OK)
 #endif
@@ -326,7 +340,7 @@
       saveavail=state.avail_out;
 
 #ifdef USE_BZIP
-      err=bzCompress(&state,BZ_FINISH);
+      err=BZ2_bzCompress(&state,BZ_FINISH);
 #else
       err=deflate(&state,Z_FINISH);
 #endif
@@ -353,15 +367,25 @@
    while(1);
 
    // Let's store the input and output size
+#ifdef USE_BZIP
+   if(uncompressedsize!=NULL) *uncompressedsize =state.total_in_lo32;
+   if(compressedsize!=NULL)   *compressedsize   =state.total_out_lo32;
+
+   state.total_out_lo32=0;
+   state.total_out_hi32=0;
+   state.total_in_lo32=0;
+   state.total_in_hi32=0;
+#else
    if(uncompressedsize!=NULL) *uncompressedsize =state.total_in;
    if(compressedsize!=NULL)   *compressedsize   =state.total_out;
 
    state.total_out=0;
    state.total_in=0;
+#endif
 
    // Finally, we release the internal memory
 #ifdef USE_BZIP
-   if(bzCompressEnd(&state)!=BZ_OK)
+   if(BZ2_bzCompressEnd(&state)!=BZ_OK)
 #else
    if(deflateReset(&state)!=Z_OK)
 #endif
@@ -404,7 +428,7 @@
 #endif
 
 #ifdef USE_BZIP
-      if(bzDecompressInit(&state,0,0)!=BZ_OK)
+      if(BZ2_bzDecompressInit(&state,0,0)!=BZ_OK)
 #else
       if(inflateInit(&state)!=Z_OK)
 #endif
@@ -439,7 +463,7 @@
 
       // The actual decompression
 #ifdef USE_BZIP
-      switch(bzDecompress(&state))
+      switch(BZ2_bzDecompress(&state))
 #else
       switch(inflate(&state,Z_NO_FLUSH))
 #endif
@@ -454,11 +478,15 @@
          input->SkipData(save_in-state.avail_in);
 
          // Let's store the overall amount of "decompressed" data.
+#ifdef USE_BZIP
+         *len=state.total_out_lo32;
+#else
          *len=state.total_out;
+#endif
 
          // Let's finish the decompression entirely
 #ifdef USE_BZIP
-         if(bzDecompressEnd(&state)!=BZ_OK)
+         if(BZ2_bzDecompressEnd(&state)!=BZ_OK)
 #else
          if(inflateReset(&state)!=Z_OK)
 #endif
