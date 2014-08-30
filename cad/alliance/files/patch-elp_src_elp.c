--- elp/src/elp.c.orig	2002-06-12 12:54:39 UTC
+++ elp/src/elp.c
@@ -62,6 +62,7 @@ elpFCT elpenv()
    if ( str == (char *)NULL ) str = ALLIANCE_TOP;
    sprintf( elpTechnoFile, "%s/%s", str, TECHNOLOGY );
  }
+ return (0); 
 }
 
 /*****************************************************************************/
@@ -249,7 +250,7 @@ if(elpGeneral[elpACM] == 1.0)
     lotrs->PS = lotrs->PD = lotrs->WIDTH ;
     }
 
-return ;
+return 0;
 }
 
 
@@ -457,7 +458,7 @@ if((lotrs->PS != 0.0) && (lotrs->XS != 0
       addcapa( lotrs->SOURCE->SIG, elpLotrsCapaSource(lotrs) ) ;
     }
 
-return ;
+return 0;
 }
 
 
@@ -487,7 +488,7 @@ for(lotrs = lofig->LOTRS ; lotrs != NULL
   
   addcapa( lotrs->GRID->SIG, elpLotrsCapaGrid(lotrs) );
 }
-return ;
+return 0;
 }
 
 
@@ -515,5 +516,5 @@ lotrs_list *lotrs  ;
 for(lotrs = lofig->LOTRS ; lotrs != NULL ; lotrs = lotrs->NEXT)
 elpLotrsShrink(lotrs) ;
 
-return ;
+return 0;
 }
