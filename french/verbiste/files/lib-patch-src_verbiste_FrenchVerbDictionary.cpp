--- src/verbiste/FrenchVerbDictionary.cpp.orig	Sun Mar 13 14:03:26 2005
+++ src/verbiste/FrenchVerbDictionary.cpp	Sat Nov  5 21:32:23 2005
@@ -655,7 +655,7 @@
     char *inbuf = strcpy(new char[inbytesleft], latin1String.c_str());
     char *outbuf = new char[outbytesleft];
 
-    char *in = inbuf;
+    const char *in = inbuf;
     char *out = outbuf;
     if (iconv(toUTF8, &in, &inbytesleft, &out, &outbytesleft) == (size_t) -1)
     {
@@ -681,7 +681,7 @@
     char *inbuf = strcpy(new char[inbytesleft], utf8String.c_str());
     char *outbuf = new char[outbytesleft];
 
-    char *in = inbuf;
+    const char *in = inbuf;
     char *out = outbuf;
     if (iconv(toLatin1, &in, &inbytesleft, &out, &outbytesleft) == (size_t) -1)
     {
