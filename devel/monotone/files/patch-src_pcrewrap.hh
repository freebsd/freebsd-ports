--- src/pcrewrap.hh.orig	2018-05-18 21:33:29 UTC
+++ src/pcrewrap.hh
@@ -18,7 +18,7 @@
 // definitions and so we don't actually expose it here. Unfortunately, this
 // means we have to hope this pair of forward declarations will not change...
 
-struct real_pcre;
+struct real_pcre8_or_16;
 struct pcre_extra;
 
 namespace pcre
@@ -61,7 +61,7 @@ namespace pcre
     regex & operator=(regex const &);
 
     // data
-    struct real_pcre const * basedat;
+    struct real_pcre8_or_16 const * basedat;
     struct pcre_extra const * extradat;
 
     // used by constructors
