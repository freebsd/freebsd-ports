--- core/input/sfark/sfarkextractor2.cpp.orig	2024-12-27 19:56:25 UTC
+++ core/input/sfark/sfarkextractor2.cpp
@@ -73,13 +73,13 @@ const char SfArkExtractor2::UpgradeMsg[] = "Please see
 #define	WFIX(I)		s = bp[I+0]; bp[I+0] = bp[I+1]; bp[I+1] = s;
 // Read from disk if needed, and fix endians
 #define CHECK_INBUFFER                          \
-    if (bioP == BIOBUFSIZE)                       \
+    if (_bioP == BIOBUFSIZE)                       \
 {                                             \
-    bioWholeBlocks++;                           \
-    bioP = 0;                                   \
-    int ReadLen = ReadInputFile((quint8 *) bioBuf, BIOBUFSIZE * sizeof(quint16)); \
+    _bioWholeBlocks++;                           \
+    _bioP = 0;                                   \
+    int ReadLen = ReadInputFile((quint8 *) _bioBuf, BIOBUFSIZE * sizeof(quint16)); \
     if (ReadLen <= 0)  return 0;		\
-    quint8 *bp = (quint8 *) bioBuf, *ep = (quint8 *) (bioBuf+BIOBUFSIZE); \
+    quint8 *bp = (quint8 *) _bioBuf, *ep = (quint8 *) (_bioBuf+BIOBUFSIZE); \
     do {					\
     quint8 s;					\
     WFIX(0); WFIX(2); WFIX(4); WFIX(6);	\
