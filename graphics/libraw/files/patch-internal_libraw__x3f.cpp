In file included from src/libraw_cxx.cpp:5472:
src/../internal/libraw_x3f.cpp:1404:19: error: non-constant-expression cannot be narrowed from type
      'int' to 'int16_t' (aka 'short') in initializer list [-Wc++11-narrowing]
  int16_t c[3] = {offset,offset,offset};
                  ^~~~~~
src/../internal/libraw_x3f.cpp:1404:19: note: insert an explicit cast to silence this issue
  int16_t c[3] = {offset,offset,offset};
                  ^~~~~~
                  static_cast<int16_t>( )
src/../internal/libraw_x3f.cpp:1404:26: error: non-constant-expression cannot be narrowed from type
      'int' to 'int16_t' (aka 'short') in initializer list [-Wc++11-narrowing]
  int16_t c[3] = {offset,offset,offset};
                         ^~~~~~
src/../internal/libraw_x3f.cpp:1404:26: note: insert an explicit cast to silence this issue
  int16_t c[3] = {offset,offset,offset};
                         ^~~~~~
                         static_cast<int16_t>( )
src/../internal/libraw_x3f.cpp:1404:33: error: non-constant-expression cannot be narrowed from type
      'int' to 'int16_t' (aka 'short') in initializer list [-Wc++11-narrowing]
  int16_t c[3] = {offset,offset,offset};
                                ^~~~~~
src/../internal/libraw_x3f.cpp:1404:33: note: insert an explicit cast to silence this issue
  int16_t c[3] = {offset,offset,offset};
                                ^~~~~~
                                static_cast<int16_t>( )

https://github.com/LibRaw/LibRaw/commit/6d4b3ea

--- internal/libraw_x3f.cpp.orig	2017-09-22 06:23:54 UTC
+++ internal/libraw_x3f.cpp
@@ -1401,7 +1401,7 @@ static void huffman_decode_row(x3f_info_t *I,
   x3f_image_data_t *ID = &DEH->data_subsection.image_data;
   x3f_huffman_t *HUF = ID->huffman;
 
-  int16_t c[3] = {offset,offset,offset};
+  int16_t c[3] = {(int16_t)offset,(int16_t)offset,(int16_t)offset};
   int col;
   bit_state_t BS;
 
