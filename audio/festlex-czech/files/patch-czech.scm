--- czech.scm.orig	2006-06-21 07:32:07 UTC
+++ czech.scm
@@ -917,7 +917,7 @@
 (lex.create "czech")
 (lex.set.phoneset "czech")
 (lex.select "czech")
-(let ((dirs '("." "/usr/share/festival"))
+(let ((dirs '("@FESTIVAL_TARGET_DIR@"))
       (lexfile nil))
   (while dirs
     (let ((file (path-append (car dirs) czech-lexicon-file)))
