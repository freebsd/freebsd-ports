--- src/mb.h.orig	Fri Apr  8 23:32:30 2005
+++ src/mb.h	Sun May  1 15:35:53 2005
@@ -77,7 +77,7 @@
 # define choose_wch()	choose_ch()
 # define InsertWChar(ch) InsertChar(ch)
 # define ReplaceWCharExt(c) ReplaceCharExt(c)
-# define ReplaceWCharExtMove(c) ReplaceWCharExtMove(c)
+# define ReplaceWCharExtMove(c) ReplaceCharExtMove(c)
 # define ReplaceWCharMove(c) ReplaceCharMove(c)
 # define mb_get_col(buf,pos,col,len)	*(col)=(pos)
 # define mb_char_left(buf,pos,col,len)  *(col)=--(*pos)
