--- src/editor-lua.cc.orig	Mon Nov 22 10:43:09 2004
+++ src/editor-lua.cc	Mon Nov 22 10:43:21 2004
@@ -50,7 +50,7 @@
  {
  int i;
  for(i=0; i<nentries;i++)
- tolua_pushfieldstring(tolua_S,4,i+1,(const char*) entries[i]);
+ tolua_pushfieldstring(tolua_S,4,i+1,(char*) entries[i]);
  }
  free(entries);
  }
@@ -93,7 +93,7 @@
  {
  int i;
  for(i=0; i<nentries;i++)
- tolua_pushfieldstring(tolua_S,4,i+1,(const char*) entries[i]);
+ tolua_pushfieldstring(tolua_S,4,i+1,(char*) entries[i]);
  }
  free(entries);
  }
@@ -136,7 +136,7 @@
  {
  int i;
  for(i=0; i<nentries;i++)
- tolua_pushfieldstring(tolua_S,4,i+1,(const char*) entries[i]);
+ tolua_pushfieldstring(tolua_S,4,i+1,(char*) entries[i]);
  }
  free(entries);
  }
