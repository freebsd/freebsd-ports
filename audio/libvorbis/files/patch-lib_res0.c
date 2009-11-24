$FreeBSD$
--- lib/res0.c.orig	2009-11-24 21:51:43.000000000 +0100
+++ lib/res0.c	2009-11-24 21:52:01.000000000 +0100
@@ -238,6 +238,10 @@ vorbis_info_residue *res0_unpack(vorbis_
 
   /* verify the phrasebook is not specifying an impossible or
      inconsistent partitioning scheme. */
+  /* modify the phrasebook ranging check from r16327; an early beta
+     encoder had a bug where it used an oversized phrasebook by
+     accident.  These files should continue to be playable, but don't
+     allow an exploit */
   {
     int entries = ci->book_param[info->groupbook]->entries;
     int dim = ci->book_param[info->groupbook]->dim;
@@ -247,6 +251,7 @@ vorbis_info_residue *res0_unpack(vorbis_
       if(partvals > entries) goto errout;
       dim--;
     }
+    info->partvals = partvals;
   }
 
   return(info);
@@ -667,7 +672,7 @@ static int _01inverse(vorbis_block *vb,v
           for(j=0;j<ch;j++){
             int temp=vorbis_book_decode(look->phrasebook,&vb->opb);
 
-            if(temp==-1)goto eopbreak;
+            if(temp==-1 || temp>=info->partvals)goto eopbreak;
             partword[j][l]=look->decodemap[temp];
             if(partword[j][l]==NULL)goto errout;
           }
@@ -883,7 +888,7 @@ int res2_inverse(vorbis_block *vb,vorbis
         if(s==0){
           /* fetch the partition word */
           int temp=vorbis_book_decode(look->phrasebook,&vb->opb);
-          if(temp==-1)goto eopbreak;
+          if(temp==-1 || temp>info->partvals)goto eopbreak;
           partword[l]=look->decodemap[temp];
           if(partword[l]==NULL)goto errout;
         }
