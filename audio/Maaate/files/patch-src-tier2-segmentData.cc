--- src/tier2/segmentData.cc.orig	Mon Mar  4 03:31:29 2002
+++ src/tier2/segmentData.cc	Sat Jul 20 17:21:11 2002
@@ -27,8 +27,8 @@
 #include "segmentData.H"
 
 // constructor
-SegmentData::SegmentData(double t1, double t2, int col=0, int row=0, 
-			 int i=0, char f=' ', double cnf=0.0) : 
+SegmentData::SegmentData(double t1, double t2, int col, int row, 
+			 int i, char f, double cnf) : 
     starttime(t1), endtime(t2), columns(col), rows(row),
     id(i), flag(f), conf(cnf) {
 	if (col<0) col=0;
@@ -89,7 +89,7 @@
 // partial copy constructor
 SegmentData::SegmentData(const SegmentData& sd,
 			 int st_row, int end_row,
-			 int i=0, char f=' ', double cnf=0.0)
+			 int i, char f, double cnf)
 {
   int nb_rows;
 
@@ -309,7 +309,7 @@
 
 // minimum of all contained data
 double
-SegmentData::min(double downto = -DBL_MAX) {
+SegmentData::min(double downto ) {
 
   double * ptr;
 
@@ -332,7 +332,7 @@
 
 // maximum of all contained data
 double
-SegmentData::max(double upto = DBL_MAX) {
+SegmentData::max(double upto) {
 
   double * ptr;
 
@@ -363,7 +363,7 @@
 
 // normalize data values to [0;1], clipping outside of [downto;upto]
 bool
-SegmentData::normalise(double downto = - DBL_MAX, double upto = DBL_MAX) {
+SegmentData::normalise(double downto, double upto) {
 
   double * ptr;
 
