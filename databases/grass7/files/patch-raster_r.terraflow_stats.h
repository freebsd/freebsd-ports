--- raster/r.terraflow/stats.h.orig	2020-12-21 18:40:15 UTC
+++ raster/r.terraflow/stats.h
@@ -35,14 +35,11 @@ int noclobberFile(char *);
 class statsRecorder : public ofstream {
 private:
   Rtimer tm;
-  void *bss;
 public:
   statsRecorder(char *fname);
   ~statsRecorder() { 
 	this->flush(); 
   }
-  char *freeMem(char *);
-  long freeMem();
   char *timestamp();
   void timestamp(const char *s);
   void comment(const char *s, const int verbose=1);
