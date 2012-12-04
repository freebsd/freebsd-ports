--- ./pdns/dnsreplay.cc.orig	2012-12-04 13:37:13.000000000 -0500
+++ ./pdns/dnsreplay.cc	2012-12-04 13:37:43.000000000 -0500
@@ -489,7 +489,6 @@
 
   QuestionData qd;
   try {
-    dnsheader* dh=(dnsheader*)pr.d_payload;
     if(!dh->qr) {
       qd.d_assignedID = s_idmanager.peakID();
       uint16_t tmp=dh->id;
