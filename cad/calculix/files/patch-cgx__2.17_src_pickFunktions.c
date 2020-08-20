--- cgx_2.17/src/pickFunktions.c.orig	2020-08-10 20:32:48.506717000 -0500
+++ cgx_2.17/src/pickFunktions.c	2020-08-10 20:35:44.407066000 -0500
@@ -283,7 +283,7 @@ int hitAction( GLuint *name, char *type, int x, int y 
     {
       delSet(specialset->impc);
       setNrbuf=pre_seta( specialset->impc, "i", 0);
-      if(setNrbuf<0) { errMsg(" ERROR: could not create set for qdis\n"); return; } 
+      if(setNrbuf<0) { errMsg(" ERROR: could not create set for qdis\n"); return(0); } 
       seta( setNrbuf, type, name[1]);
       
       /* complete the set by all connected faces which do not violate the tolerance */
@@ -1214,7 +1214,7 @@ int hitAction( GLuint *name, char *type, int x, int y 
     {
       delSet(specialset->impc);
       setNrbuf=pre_seta( specialset->impc, "i", 0);
-      if(setNrbuf<0) { errMsg(" ERROR: could not create set for qdis\n"); return; } 
+      if(setNrbuf<0) { errMsg(" ERROR: could not create set for qdis\n"); return(0); } 
       seta( setNrbuf, type, name[1]);
       qaddTol=0;  // marker
     }
