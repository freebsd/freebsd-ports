--- src/wp/impexp/xp/ie_imp_MsWord_97.cpp.orig	Mon Aug 25 04:03:16 2003
+++ src/wp/impexp/xp/ie_imp_MsWord_97.cpp	Mon Aug 25 04:03:27 2003
@@ -3402,7 +3402,7 @@
     comprLen = size;
     uncomprLen = b->blip.metafile.m_cb;
     unsigned char *uncompr = new unsigned char[uncomprLen];
-    int err = uncompress (uncompr, &uncomprLen, data, comprLen);
+    int err = uncompress (uncompr, &uncomprLen, (unsigned char *)data, comprLen);
     if (err != Z_OK)
       {
 	UT_DEBUGMSG(("Could not uncompress image\n"));
