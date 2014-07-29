--- src/parser.y.orig	Thu Nov 30 00:13:01 2000
+++ src/parser.y	Wed Mar  5 18:53:02 2003
@@ -564,7 +564,7 @@
 handle    : HANDLE beg malts end        {$$ = gc4(rev($3));}
           ;
 ohandle   : handle                      {$$ = $1;}
-          | /*empty*/                   {$$ = gc0(NIL);}
+          | /*empty*/                   {$$ = gc0(NIL);};
 mexp      : mopExp COCO sigType         {$$ = gc3(ap(ESIGN,pair($1,$3)));}
 	  | mopExp                      {$$ = $1;}
 	  ;
