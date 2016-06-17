--- src/parser.y.orig	2000-11-29 23:13:01 UTC
+++ src/parser.y
@@ -564,7 +564,7 @@ gen       : mexp FROM exp               
 handle    : HANDLE beg malts end        {$$ = gc4(rev($3));}
           ;
 ohandle   : handle                      {$$ = $1;}
-          | /*empty*/                   {$$ = gc0(NIL);}
+          | /*empty*/                   {$$ = gc0(NIL);};
 mexp      : mopExp COCO sigType         {$$ = gc3(ap(ESIGN,pair($1,$3)));}
 	  | mopExp                      {$$ = $1;}
 	  ;
