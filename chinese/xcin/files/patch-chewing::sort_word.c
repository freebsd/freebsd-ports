--- src/Cinput/chewing/sort_word.c.orig	Sun Aug 11 12:32:03 2002
+++ src/Cinput/chewing/sort_word.c	Sun Aug 11 12:32:20 2002
@@ -40,6 +40,7 @@
   Key2Pho(phoneBuf, keyBuf, KB_DEFAULT, 1) ;
   word_data[nWord].num = PhoneBg2Uint(phoneBuf) ;
   nWord++ ;
+  return 0;
 }
 
 void Output()
