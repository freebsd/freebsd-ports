Regressed by https://github.com/unicode-org/icu/commit/480bec3ea652

libfreehand_utils.cpp:165:30: error: expected ';' after do/while statement
    U16_NEXT(s, j, length, c)
                             ^
                             ;
libfreehand_utils.cpp:168:23: error: use of undeclared identifier 'outbuf'
    U8_APPEND_UNSAFE(&outbuf[0], i, c);
                      ^
libfreehand_utils.cpp:168:23: error: use of undeclared identifier 'outbuf'
libfreehand_utils.cpp:168:23: error: use of undeclared identifier 'outbuf'
libfreehand_utils.cpp:168:23: error: use of undeclared identifier 'outbuf'
libfreehand_utils.cpp:168:23: error: use of undeclared identifier 'outbuf'
libfreehand_utils.cpp:168:23: error: use of undeclared identifier 'outbuf'
libfreehand_utils.cpp:168:23: error: use of undeclared identifier 'outbuf'
libfreehand_utils.cpp:169:5: error: use of undeclared identifier 'outbuf'; did you mean 'setbuf'?
    outbuf[i] = 0;
    ^~~~~~
    setbuf
/usr/include/stdio.h:283:7: note: 'setbuf' declared here
void     setbuf(FILE * __restrict, char * __restrict);
         ^
libfreehand_utils.cpp:169:5: error: subscript of pointer to function type 'void (FILE *, char *)' (aka 'void (__sFILE *, char *)')
    outbuf[i] = 0;
    ^~~~~~
libfreehand_utils.cpp:171:25: error: use of undeclared identifier 'outbuf'
    text.append((char *)outbuf);
                        ^

--- src/lib/libfreehand_utils.cpp.orig	2017-09-16 10:28:50 UTC
+++ src/lib/libfreehand_utils.cpp
@@ -162,7 +162,7 @@ void libfreehand::_appendUTF16(librevenge::RVNGString 
   while (j < length)
   {
     UChar32 c;
-    U16_NEXT(s, j, length, c)
+    U16_NEXT(s, j, length, c);
     unsigned char outbuf[U8_MAX_LENGTH+1];
     int i = 0;
     U8_APPEND_UNSAFE(&outbuf[0], i, c);
