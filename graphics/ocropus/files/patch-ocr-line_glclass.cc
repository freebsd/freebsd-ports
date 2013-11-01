--- ocr-line/glclass.cc.orig	2009-05-31 20:18:41.000000000 +0000
+++ ocr-line/glclass.cc
@@ -95,7 +95,7 @@ namespace glinerec {
     double nearest_neighbor_error(IDataset &data,int ntrials=1000) {
         int total = 0;
         ntrials = min(data.nsamples(),ntrials);
-        for(int i=0;i<data.nsamples();i++) {
+        for(int ic=0;ic<data.nsamples();ic++) {
             // FIXME use sampling without replacement
             int i = lrand48()%data.nsamples();
             floatarray u;
