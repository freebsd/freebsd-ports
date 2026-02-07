--- Makefile.PL.orig	Tue Mar 30 19:41:17 2004
+++ Makefile.PL	Tue Mar 30 19:42:44 2004
@@ -9,7 +9,7 @@
 
 our $BASE_CFG_FN;
 our $NO_DB_TESTS_FN;
-require "ladbi_config.pl";
+=for unused
 
 if (0 and read_answer_yes("Do you want to test this module against a Database?"))
   {
@@ -42,6 +42,7 @@
   }
 
 
+=cut
 
 #exit 0;
 
