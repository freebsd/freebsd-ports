hal.c:426:13: error: comparison between pointer and integer ('int' and 'const unsigned char *')
   if ('\0' == oligo_f) {
       ~~~~ ^  ~~~~~~~
thal.c:431:13: error: comparison between pointer and integer ('int' and 'const unsigned char *')
   if ('\0' == oligo_r) {
       ~~~~ ^  ~~~~~~~

--- thal.c.orig	2018-08-25 03:33:22 UTC
+++ thal.c
@@ -423,12 +423,12 @@ thal(const unsigned char *oligo_f, 
 	       "Illegal type");
    o->align_end_1 = -1;
    o->align_end_2 = -1;
-   if ('\0' == oligo_f) {
+   if ('\0' == *oligo_f) {
       strcpy(o->msg, "Empty first sequence");
       o->temp = 0.0;
       return;
    }
-   if ('\0' == oligo_r) {
+   if ('\0' == *oligo_r) {
       strcpy(o->msg, "Empty second sequence");
       o->temp = 0.0;
       return;
