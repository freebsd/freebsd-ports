--- addsynth.cc.orig	2022-05-05 04:20:20 UTC
+++ addsynth.cc
@@ -102,13 +102,13 @@ void N_func::clrv (int i)
 
 void N_func::write (FILE *F)
 {
-#ifdef __BYTE_ORDER
-#if (__BYTE_ORDER == __LITTLE_ENDIAN)
+#ifdef _BYTE_ORDER
+#if (_BYTE_ORDER == _LITTLE_ENDIAN)
 
     fwrite (&_b, 1, sizeof (int32_t), F);
     fwrite (_v, N_NOTE, sizeof (float), F);
 
-#elif (__BYTE_ORDER == __BIG_ENDIAN)
+#elif (_BYTE_ORDER == _BIG_ENDIAN)
 
     int  i;
     char d [N_NOTE * sizeof (float)];
@@ -130,13 +130,13 @@ void N_func::write (FILE *F)
 
 void N_func::read (FILE *F)
 {
-#ifdef __BYTE_ORDER
-#if (__BYTE_ORDER == __LITTLE_ENDIAN)
+#ifdef _BYTE_ORDER
+#if (_BYTE_ORDER == _LITTLE_ENDIAN)
 
     fread (&_b, 1, sizeof (int32_t), F);
     fread (&_v, N_NOTE, sizeof (float), F);
 
-#elif (__BYTE_ORDER == __BIG_ENDIAN)
+#elif (_BYTE_ORDER == _BIG_ENDIAN)
 
     int  i;
     char d [sizeof (int) + N_NOTE * sizeof (float)];
