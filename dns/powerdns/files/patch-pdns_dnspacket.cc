--- pdns/dnspacket.cc.orig	2015-11-02 10:33:21 UTC
+++ pdns/dnspacket.cc
@@ -641,9 +641,9 @@ bool checkForCorrectTSIG(const DNSPacket
   string message;
 
   q->getTSIGDetails(trc, keyname, &message);
-  uint64_t now = time(0);
-  if(abs(trc->d_time - now) > trc->d_fudge) {
-    L<<Logger::Error<<"Packet for '"<<q->qdomain<<"' denied: TSIG (key '"<<*keyname<<"') time delta "<< abs(trc->d_time - now)<<" > 'fudge' "<<trc->d_fudge<<endl;
+  uint64_t delta = std::labs((int64_t)trc->d_time - (int64_t)time(0));
+  if(delta > trc->d_fudge) {
+    L<<Logger::Error<<"Packet for '"<<q->qdomain<<"' denied: TSIG (key '"<<*keyname<<"') time delta "<< delta <<" > 'fudge' "<<trc->d_fudge<<endl;
     return false;
   }
 
