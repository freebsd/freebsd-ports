--- ./QueryManager/MatchAligner.h.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./QueryManager/MatchAligner.h	2008-06-12 15:39:31.000000000 -0300
@@ -315,13 +315,13 @@
 
   static char getCodon( const char* pChar )
   {
-    return (  (    (ttDNA[ *pChar ] ==nv)
-		   || (ttDNA[ *(pChar+1) ] ==nv)
-		   || (ttDNA[ *(pChar+2) ] ==nv) )
+    return (  (    (ttDNA[ (int) *pChar ] ==nv)
+		   || (ttDNA[ (int) *(pChar+1) ] ==nv)
+		   || (ttDNA[ (int) *(pChar+2) ] ==nv) )
 	      ? 'X'
-	      : gResidueNames[ ttCodon[ ttDNA[ *(pChar) ] << 4
-				      | ttDNA[ *(pChar+1) ] << 2
-				      | ttDNA[ *(pChar+2) ] ] ] );
+	      : gResidueNames[ ttCodon[ ttDNA[ (int) *(pChar) ] << 4
+				      | ttDNA[ (int) *(pChar+1) ] << 2
+				      | ttDNA[ (int) *(pChar+2) ] ] ] );
   } // ~getCodon
 
 
@@ -519,8 +519,8 @@
   : public vector<vector<PATH_TYPE> >
 {
 public:
-  typedef pair<vector<vector<PATH_TYPE> >::iterator,
-    vector<PATH_TYPE>::iterator> CellIterator;
+  typedef pair<typename vector<vector<PATH_TYPE> >::iterator,
+    typename vector<PATH_TYPE>::iterator> CellIterator;
 
   template<class MATRIX_FILLER> ScoreType fillIn( MATRIX_FILLER& doMatrix )
   {
