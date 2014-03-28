--- dialogue/jisyo.c.orig	2013-11-03 22:38:25.000000000 +0900
+++ dialogue/jisyo.c	2013-11-03 22:43:05.000000000 +0900
@@ -1,3 +1,4 @@
+#include <string.h>
 #include "onew.h"
 
 int OM_JisyoMode;
@@ -6,8 +7,10 @@
 int OM_JisyoGetKanjiFlush;
 int OM_JisyoMassyou;
 
-extern Uchar ONEW_DicYomi[];
+extern char ONEW_DicYomi[];
+void odmJisyo_massyou(void);
 
+int
 odmStart_touroku(yomi)
 	char *yomi;
 {
@@ -20,6 +23,7 @@
 	return 1;
 }
 
+int
 odmAbort_touroku(){
 	if( OM_JisyoGetYomi || OM_JisyoGetTsuduri || OM_JisyoGetKanjiFlush ){
 		Onew_putmsg(1,ONEW_msg_tourokuABORT);
@@ -32,6 +36,7 @@
 	return 0;
 }
 
+int
 odmJisyo_sousa(){
 	int com;
 
@@ -50,6 +55,7 @@
 	return 0;
 }
 
+void
 odmJisyo_massyou()
 {
 	OM_JisyoMassyou = 1;
@@ -59,6 +65,7 @@
 	OM_JisyoMassyou = 0;
 }
 
+void
 odmJisyo_touroku()
 {	int i,max;
 	int com;
