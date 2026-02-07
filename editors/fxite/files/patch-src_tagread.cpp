--- src/tagread.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/tagread.cpp
@@ -532,11 +532,11 @@ void AutoCompleter::Show(SciDoc*sci)
   if (no()&&sci->PrefixAtPos(part)) {
     FXint partlen=part.length();
     FXint len=0; // save lots of reallocs by calculating overall length first
-    for (FXint i=first(); i<=last(); i=next(i)) {
-      const char*ctag=key(i);
-      int taglen=strlen(ctag);
-      if ((taglen>partlen)&&(strncmp(part.text(),ctag,partlen)==0)) {
-        replace(ctag,(void*)((FXival)1)); // flag it for inclusion
+    for (FXint i=0; i<TotalSlotsInDict(this); ++i) {
+      FXString ctag=key(i);
+      int taglen=ctag.length();
+      if ((taglen>partlen)&&(compare(part,ctag,partlen)==0)) {
+        ReplaceInDict(this,ctag.text(),(void*)((FXival)1)); // flag it for inclusion
         len+=taglen+1; // count its length
       }
     }
@@ -544,10 +544,10 @@ void AutoCompleter::Show(SciDoc*sci)
       FXString list=FXString::null;
       list.length(len);
       list.trunc(0);
-      for (FXint i=first(); i<=last(); i=next(i)) {
+      for (FXint i=0; i<TotalSlotsInDict(this); ++i) {
         if (data(i)) {
-          const char*ctag=key(i);
-          replace(ctag,NULL); // reset our flag
+          FXString ctag=key(i);
+          ReplaceInDict(this,ctag.text(),NULL); // reset our flag
           list.append(ctag);
           list.append(' ');
         }
