--- cgx_2.14/src/uselibSNL.cpp.orig	2017-10-07 09:58:00 UTC
+++ cgx_2.14/src/uselibSNL.cpp
@@ -934,7 +934,7 @@ int createBlendedNurbs(int nr, Points **
   // (5)   create the cgx nurbs
   // printf(" create blended nurbs\n"); 
   buffer[0]='S';
-  buffer[1]=(char)NULL;
+  buffer[1]='\0';
   getNewName( name, buffer );
   for (i=0; i<MAX_LINE_LENGTH; i++) sname[i]=name[i];
   if(printFlag) printf ("store NURS Nr:%d Name:%s\n", anzGeo->nurs+1, name);
@@ -1012,7 +1012,7 @@ int createBlendedNurbs(int nr, Points **
     for (j=0; j<nurbs[nr].v_npnt; j++)
     {
       buffer[0]='p';
-      buffer[1]=(char)NULL;
+      buffer[1]='\0';
       getNewName( name, buffer );
       nurbs[nr].ctlpnt[i][j]  = pnt( name, surface->controlPoints()[ index ].x(), surface->controlPoints()[ index ].y(), surface->controlPoints()[ index ].z(), 0);
       point=*pntpntr;  /* update pointer */
