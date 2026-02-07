--- src/pfsglview/m_histogram.cpp.orig	2018-01-19 06:59:44 UTC
+++ src/pfsglview/m_histogram.cpp
@@ -176,7 +176,7 @@ void M_Histogram::drawHistogram() {
 
 	int array_pos ;
 	int ch = 0 ;
-	if(!strcmp(channel, "XYZ") == 0)
+	if(!(strcmp(channel, "XYZ") == 0))
 			switch(channel[0]) {
 			case 'X': ch = 1 ; break ;
 			case 'Y': ch = 2 ; break ;
