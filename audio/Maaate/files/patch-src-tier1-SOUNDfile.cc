--- src/tier1/SOUNDfile.cc.orig	Mon Mar  4 03:31:29 2002
+++ src/tier1/SOUNDfile.cc	Sat Jul 20 17:21:11 2002
@@ -132,7 +132,7 @@
 
 //give the duration of one subband sample in sec
 float 
-SOUNDfile::sample_duration( Resolution res = LOW ) {
+SOUNDfile::sample_duration( Resolution res) {
   return format->sample_duration( res );
 }
 
@@ -164,7 +164,7 @@
 
 //give the nuber of subband samples in one window
 unsigned int 
-SOUNDfile::timeticks( Resolution res = LOW ) {
+SOUNDfile::timeticks( Resolution res) {
   return format->timeticks( res );
 }
 
@@ -194,7 +194,7 @@
 /*-------------- extract and skip --------------*/
 //go to next window and analyse it with res
 bool 
-SOUNDfile::next_window( Resolution res = LOW) {
+SOUNDfile::next_window( Resolution res) {
   //set which_max as maxim do not contain a meaningful value
   which_max = -1;
   return format->next_window( res );
@@ -212,20 +212,20 @@
 /*--------------- access function ---------------*/
 //give the value of the subband samples of the current window
 double 
-SOUNDfile::freq_value( unsigned int ch, unsigned int sb, unsigned int nb = 0, Resolution res = LOW ) {
+SOUNDfile::freq_value( unsigned int ch, unsigned int sb, unsigned int nb, Resolution res) {
   return format->freq_value(ch,sb,nb,res);
 }
 
 //give the number of subband at that resolution
 unsigned int 
-SOUNDfile::nb_subbands( Resolution res = LOW ) {
+SOUNDfile::nb_subbands( Resolution res) {
   return format->nb_subbands( res );
 }
 
 /*------------- Analyse functions ----------------------*/
 //give the mean of samples nb in subband sb on both channels if available
 double 
-SOUNDfile::freqvalue_st_mean( unsigned int sb, unsigned int nb = 0, Resolution res = LOW )
+SOUNDfile::freqvalue_st_mean( unsigned int sb, unsigned int nb, Resolution res)
 {
   
   if ( format->is_stereo() ) { // in case of a stereo file it is possible to compute the mean
@@ -237,7 +237,7 @@
 
 //give the rms of samples nb in subband sb on both channels if available 
 double 
-SOUNDfile::freqvalue_st_rms( unsigned int sb, unsigned int nb = 0, Resolution res = LOW) 
+SOUNDfile::freqvalue_st_rms( unsigned int sb, unsigned int nb, Resolution res) 
 {
 
   if ( format->is_stereo() ) {  // in case of a stereo file it is possible to compute the rms
@@ -249,7 +249,7 @@
 
 //give the normalised subband energy samples
 double
-SOUNDfile::normalised_sb_nrj( unsigned int sb, unsigned int nb = 0, Resolution res = LOW) 
+SOUNDfile::normalised_sb_nrj( unsigned int sb, unsigned int nb, Resolution res) 
 {
   double resu;
 
@@ -293,7 +293,7 @@
 
 //give a coarse and quick idea of the value in that subband
 double 
-SOUNDfile::subband_scalefactor ( unsigned int sb, Resolution res = LOW)
+SOUNDfile::subband_scalefactor ( unsigned int sb, Resolution res)
 {
   switch (filetype) {
   case MPEG:
@@ -319,7 +319,7 @@
 
 //give the mean of samples over the current window
 double
-SOUNDfile::subband_mean( unsigned int sb, Resolution res = LOW) 
+SOUNDfile::subband_mean( unsigned int sb, Resolution res) 
 {
 
   int num = format->timeticks(res);
@@ -335,7 +335,7 @@
 
 //give the rms of samples over the current window
 double
-SOUNDfile::subband_rms( unsigned int sb, Resolution res = LOW) 
+SOUNDfile::subband_rms( unsigned int sb, Resolution res) 
 {
     
   int num = format->timeticks(res);
@@ -351,7 +351,7 @@
 
 //give the normalised subband energy over the current window  
 double
-SOUNDfile::subband_nrj( unsigned int sb, Resolution res = LOW) 
+SOUNDfile::subband_nrj( unsigned int sb, Resolution res) 
 {
   double resu;
 
