--- src/pcrewrap.cc.orig	2018-05-18 21:33:20 UTC
+++ src/pcrewrap.cc
@@ -74,7 +74,7 @@ get_capturecount(void const * bd)
 namespace pcre
 {
   typedef map<char const *,
-              pair<struct real_pcre const *, struct pcre_extra const *> >
+              pair<struct real_pcre8_or_16 const *, struct pcre_extra const *> >
               regex_cache;
 
   class regex_cache_manager
@@ -86,7 +86,7 @@ namespace pcre (public)
       }
 
     void store(char const * pattern,
-               pair<struct real_pcre const *, struct pcre_extra const *>
+               pair<struct real_pcre8_or_16 const *, struct pcre_extra const *>
                data)
       {
         cache[pattern] = data;
