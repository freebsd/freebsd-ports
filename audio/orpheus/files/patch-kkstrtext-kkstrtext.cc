--- kkstrtext-0.1/kkstrtext.cc	2004-01-15 21:25:31.000000000 +0100
+++ kkstrtext-0.1/kkstrtext.cc	2006-08-28 11:48:36.926598598 +0200
@@ -431,7 +431,7 @@
 }
 
 int intcompare(void *s1, void *s2) {
-    return (int) s1 != (int) s2;
+    return (long) s1 != (long) s2;
 }
 
 string i2str(int i) {
@@ -885,7 +885,7 @@
 #ifdef HAVE_ICONV
     iconv_t cd = iconv_open(tocs.c_str(), fromcs.c_str());
 
-    if(((int) cd) != -1) {
+    if(((long) cd) != -1) {
 	string r, text(atext);
 	size_t inleft, outleft, soutleft;
 	char *inbuf, *outbuf, *sinbuf, *soutbuf;

