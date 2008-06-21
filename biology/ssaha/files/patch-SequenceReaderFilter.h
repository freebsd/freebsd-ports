--- ./SequenceReader/SequenceReaderFilter.h.orig	2004-03-01 13:51:30.000000000 -0300
+++ ./SequenceReader/SequenceReaderFilter.h	2008-06-12 15:39:31.000000000 -0300
@@ -80,7 +80,7 @@
 
   size_t max( void ) const 
   { 
-    int max(0);
+    size_t max(0);
     for (vector<vector<string*> >::const_iterator i(bins_.begin()); i!= bins_.end(); i++ )
       if (i->size()>max) max=i->size();
     return max;
@@ -109,7 +109,7 @@
  public:
   SequenceReaderFilterState
     ( SequenceNumber lsn, SequenceReader* ps ) :
-    pState_(ps->saveState()), SequenceReaderState(lsn) {}
+    SequenceReaderState(lsn), pState_(ps->saveState())  {}
   virtual ~SequenceReaderFilterState() {} //delete pState_;
   // no point in making this private as it's const
   // this is state info for *ps, whatever it is
