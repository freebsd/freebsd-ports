--- scripts/update-news.pl.orig	2019-12-06 12:02:59 UTC
+++ scripts/update-news.pl
@@ -61,8 +61,8 @@ close $in;
 
 copy($tempfile, "doc/news.t2t");
 
-system "txt2tags --encoding=utf-8 -odoc/news.html -t html doc/news.t2t";
-system "txt2tags --encoding=utf-8 -oNEWS -t txt doc/news.t2t";
+system "txt2tags -odoc/news.html -t html doc/news.t2t";
+system "txt2tags -oNEWS -t txt doc/news.t2t";
 
 =head1 NAME
 
