--- src/mpeg/MPEGfile.cc.orig	Mon Mar  4 03:31:28 2002
+++ src/mpeg/MPEGfile.cc	Sat Jul 20 17:21:11 2002
@@ -97,7 +97,7 @@
 /*---------------- time functions --------------------*/
 
 float 
-MPEGfile::sample_duration( Resolution res = LOW ) {
+MPEGfile::sample_duration( Resolution res) {
   //duration of one MPEG frame
   double frameDur = (1.0*samples_per_frame() / (1000.0 * samplingrate()));
 
@@ -147,7 +147,7 @@
 }
 
 unsigned int 
-MPEGfile::timeticks( Resolution res = LOW ) {
+MPEGfile::timeticks( Resolution res) {
   if ( layer() == III  ) {
     if ( res == LOW || res == PCM) {
       return 18;
@@ -164,7 +164,7 @@
 /*------------------- skip and analyse function -----------*/
 
 bool 
-MPEGfile::next_window( Resolution res = LOW ) {
+MPEGfile::next_window( Resolution res) {
   int nb_gr = nb_granules();
   DecodeLevel touse;
   //futur current window
@@ -272,8 +272,8 @@
 /*------------- access function ----------------*/
 
 double 
-MPEGfile::freq_value( unsigned int ch, unsigned int sb, unsigned int nb = 0,
-		      Resolution res = LOW ) {
+MPEGfile::freq_value( unsigned int ch, unsigned int sb, unsigned int nb,
+		      Resolution res) {
   if ( res == HIGH && layer() == III) {
     return mdct_sample (ch,sb); //576 subbands
   } else {
@@ -283,7 +283,7 @@
 }
 
 unsigned int 
-MPEGfile::nb_subbands( Resolution res = LOW ) {
+MPEGfile::nb_subbands( Resolution res) {
   if ( layer() == III && res == HIGH ) {
     return 576;
   } else {
@@ -423,7 +423,7 @@
 
 //allow to parse next frame if available, keep windowNo up to date
 bool 
-MPEGfile::goTo_nextFrame( Resolution res = LOW) {
+MPEGfile::goTo_nextFrame( Resolution res) {
   if (!data_available()) return false;
   long oldfr = frameNo;
   while (frameNo == oldfr) {
@@ -732,7 +732,7 @@
 }
 
 short 
-MPEGfile::pcm_sample (unsigned int ch, unsigned int sb, unsigned int no, unsigned int ss=0) {
+MPEGfile::pcm_sample (unsigned int ch, unsigned int sb, unsigned int no, unsigned int ss) {
   return audio->pcm_sample(ch, sb, no, ss);
 }
 
