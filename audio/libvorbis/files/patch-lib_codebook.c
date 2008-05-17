
$FreeBSD$

--- lib/codebook.c.orig
+++ lib/codebook.c
@@ -159,6 +159,8 @@
   s->entries=oggpack_read(opb,24);
   if(s->entries==-1)goto _eofout;
 
+  if(_ilog(s->dim)+_ilog(s->entries)>24)goto _eofout;
+
   /* codeword ordering.... length ordered or unordered? */
   switch((int)oggpack_read(opb,1)){
   case 0:
@@ -225,7 +227,7 @@
       int quantvals=0;
       switch(s->maptype){
       case 1:
-	quantvals=_book_maptype1_quantvals(s);
+	quantvals=(s->dim==0?0:_book_maptype1_quantvals(s));
 	break;
       case 2:
 	quantvals=s->entries*s->dim;
