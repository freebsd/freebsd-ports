--- spl.h.orig	2021-07-20 09:35:24 UTC
+++ spl.h
@@ -43,13 +43,17 @@ typedef struct {
 
 /* global variables */
 
-CHARACTER **cast;
-CHARACTER *first_person;
-CHARACTER *second_person;
+#ifndef GLOBAL
+# define GLOBAL extern
+#endif
 
-int truth_flag;
-int num_on_stage;
-int num_cast;
+GLOBAL CHARACTER **cast;
+GLOBAL CHARACTER *first_person;
+GLOBAL CHARACTER *second_person;
+
+GLOBAL int truth_flag;
+GLOBAL int num_on_stage;
+GLOBAL int num_cast;
 
 /* function prototypes */
 extern void activate_character(int line, CHARACTER *character);
