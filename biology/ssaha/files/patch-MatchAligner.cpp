--- ./QueryManager/MatchAligner.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./QueryManager/MatchAligner.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -53,13 +53,13 @@
   bool reverseQueryCoords,
   bool doAlignment,
   ostream& outputStream ):
+  pAlign_(pAlign),
+  outputStream_(outputStream),
   querySource_(querySource), 
   subjectSource_(subjectSource),
-  pAlign_(pAlign),
   //  numCols_(numCols),
   reverseQueryCoords_(reverseQueryCoords),
-  doAlignment_(doAlignment),
-  outputStream_(outputStream)
+  doAlignment_(doAlignment)
 {
 } // ~MatchTaskAlign::MatchTaskAlign
 
@@ -194,10 +194,10 @@
   int bandExtension,
   ScoreTable* pTable,
   ostream& outputStream ) :
+  outputStream_(outputStream),
   numCols_(numCols),
   bandExtension_(bandExtension),
-  pTable_(pTable),
-  outputStream_(outputStream)
+  pTable_(pTable)
 {
   pBufSeq1_= new char [numCols+1];
   pBufSeq2_= new char [numCols+1];
@@ -563,17 +563,17 @@
       //  cout << int ( ttDNA[ *(pChar++ ] << 4
       //     | (ttDNA[ *(pChar++) ] << 2)
       //     | ttDNA[ *(pChar++) ] ) << endl; 
-      if (    (ttDNA[ *(pChar)   ]==nv)
-           || (ttDNA[ *(pChar+1) ]==nv)
-           || (ttDNA[ *(pChar+2) ]==nv) )
+      if (    (ttDNA[ (int) *(pChar)   ]==nv)
+           || (ttDNA[ (int) *(pChar+1) ]==nv)
+           || (ttDNA[ (int) *(pChar+2) ]==nv) )
       {	
 	*i='X';
       } // ~if   
       else
       {
-	*i= gResidueNames[ ttCodon[ ttDNA[ *(pChar) ] << 4
-				  | ttDNA[ *(pChar+1) ] << 2
-				  | ttDNA[ *(pChar+2) ] ] ];
+	*i= gResidueNames[ ttCodon[ ttDNA[ (int) *(pChar) ] << 4
+				  | ttDNA[ (int) *(pChar+1) ] << 2
+				  | ttDNA[ (int) *(pChar+2) ] ] ];
       } // ~else
 
     } // ~for i
@@ -983,7 +983,7 @@
 
 void print( PathMatrix<PathType>& p )
 {
-  for (int i(0); i< p.front().size(); i++)
+  for (size_t i(0); i< p.front().size(); i++)
   {
     for (vector<vector<PathType> >::iterator j(p.begin());
 	 j!=p.end();++j)
@@ -1249,16 +1249,16 @@
   bandWidth_(p2Size-p1Size+1),
   bandLength_(p1Size+1),
   colSize_(p2Size-p1Size+1+(2*bandExtension_)),
-  fillCell_(),
   finalFrame1_(p1FinalFrame),
   finalFrame2_(p2FinalFrame),
   numFrames1_((p1Trans[1]==NULL)?1:gNumReadingFrames),
   numFrames2_((p2Trans[1]==NULL)?1:gNumReadingFrames),
+  fillCell_(),
+  getScore_(scoreTable),
   v1_(colSize_, veryBadScore3D ), 
   v2_(colSize_, veryBadScore3D ),
   pLast_(&v1_),
-  pCurrent_(&v2_),
-  getScore_(scoreTable)
+  pCurrent_(&v2_)
 {
   
   p1_[0] = p1Trans[0];
@@ -1287,7 +1287,7 @@
 {
 
   //  ScoreType lastScore, prevFrameScore1, prevFrameScore2;
-  int i,j,k,l;
+  int i,j;
 
   matrix.resize(bandLength_, vector<PathType3D>(colSize_) );
 
