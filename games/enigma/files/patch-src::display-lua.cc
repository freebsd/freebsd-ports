--- src/display-lua.cc.orig	Mon Nov 22 10:42:13 2004
+++ src/display-lua.cc	Mon Nov 22 10:42:49 2004
@@ -201,7 +201,7 @@
  {
  int i;
  for(i=0; i<n;i++)
- tolua_pushfieldstring(tolua_S,3,i+1,(const char*) names[i]);
+ tolua_pushfieldstring(tolua_S,3,i+1,(char*) names[i]);
  }
  free(names);
  }
@@ -267,7 +267,7 @@
  {
  int i;
  for(i=0; i<n;i++)
- tolua_pushfieldstring(tolua_S,3,i+1,(const char*) images[i]);
+ tolua_pushfieldstring(tolua_S,3,i+1,(char*) images[i]);
  }
  free(images);
  }
