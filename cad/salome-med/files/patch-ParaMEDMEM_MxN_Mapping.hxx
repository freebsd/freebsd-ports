--- src/ParaMEDMEM/MxN_Mapping.hxx.orig	2009-10-19 15:18:21.000000000 +0700
+++ src/ParaMEDMEM/MxN_Mapping.hxx	2009-10-19 15:18:27.000000000 +0700
@@ -39,8 +39,8 @@
     void addElementFromSource(int distant_proc, int distant_elem);
     void prepareSendRecv();
     void sendRecv(MEDCouplingFieldDouble& field);
-    void sendRecv(double* field, MEDCouplingFieldDouble& field) const ;
-    void reverseSendRecv(double* field, MEDCouplingFieldDouble& field) const ;
+    void sendRecv(double* fieldd, MEDCouplingFieldDouble& field) const ;
+    void reverseSendRecv(double* fieldd, MEDCouplingFieldDouble& field) const ;
  
     //
     const std::vector<std::pair<int,int> >& getSendingIds() const { return _sending_ids; }//tmp
