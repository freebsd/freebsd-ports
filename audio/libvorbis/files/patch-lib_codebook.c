$FreeBSD$
--- lib/codebook.c.orig	2009-07-09 11:12:08.000000000 +0200
+++ lib/codebook.c	2009-11-24 21:46:47.000000000 +0100
@@ -198,6 +198,7 @@ int vorbis_staticbook_unpack(oggpack_buf
       for(i=0;i<s->entries;){
         long num=oggpack_read(opb,_ilog(s->entries-i));
         if(num==-1)goto _eofout;
+        if(length>32)goto _errout;
         for(j=0;j<num && i<s->entries;j++,i++)
           s->lengthlist[i]=length;
         length++;
