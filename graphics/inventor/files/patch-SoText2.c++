*** lib/database/src/so/nodes/SoText2.c++.orig	Tue Sep 25 00:45:41 2001
--- lib/database/src/so/nodes/SoText2.c++	Mon Dec 23 13:28:11 2002
***************
*** 1498,1503 ****
--- 1498,1504 ----
      // And some font library stuff:
      static FLcontext	flContext;
      FLfontNumber	fontId;
+     GLubyte* fontNumList;
  };
      
  SO_NODE_SOURCE(SoText2);
