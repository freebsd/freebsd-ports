--- src/typespeed.c.orig	2008-08-13 14:36:51 UTC
+++ src/typespeed.c
@@ -136,6 +136,12 @@ static void		usage(void);
 #endif /* TEST */
 
 /* globals */
+struct finfo finfo;
+struct stats now;
+struct opt opt;
+struct rules rules;
+struct rawdata words;
+
 char *rankki[11] =
 {"None", "Beginner", "Learner", "NoGood", "Average",
  "Good", "VeryGood", "Pro", "3l33t", "*(GOD)*", "Computer"};
