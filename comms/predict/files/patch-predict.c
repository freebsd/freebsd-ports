--- predict.c.orig	Tue May 16 20:48:30 2006
+++ predict.c	Tue May 16 20:49:36 2006
@@ -5128,7 +5128,7 @@
 
 					if ((old_visibility=='V' || old_visibility=='D') && visibility=='N')
 					{
-						sprintf(command,"%svocalizer/vocalizer eclipse &",predictpath);
+						sprintf(command,"vocalizer eclipse &",predictpath);
 						system(command);
 						eclipse_alarm=1;
 						oldtime-=0.000015*sqrt(sat_alt);
@@ -5136,7 +5136,7 @@
 
 					if (old_visibility=='N' && (visibility=='V' || visibility=='D'))
 					{
-						sprintf(command,"%svocalizer/vocalizer sunlight &",predictpath);
+						sprintf(command,"vocalizer sunlight &",predictpath);
 						system(command);
 						eclipse_alarm=1;
 						oldtime-=0.000015*sqrt(sat_alt);
@@ -5151,7 +5151,7 @@
 					if (sat_range_rate>0.0)
 						approaching='-';
 
-					sprintf(command,"%svocalizer/vocalizer %.0f %.0f %c %c &",predictpath,sat_azi,sat_ele,approaching,visibility);
+					sprintf(command,"vocalizer %.0f %.0f %c %c &",predictpath,sat_azi,sat_ele,approaching,visibility);
 					system(command);
   					oldtime=CurrentDaynum();
 					old_visibility=visibility;
@@ -5273,7 +5273,7 @@
 			{
 				/* Announce LOS */
 
-				sprintf(command,"%svocalizer/vocalizer los &",predictpath);
+				sprintf(command,"vocalizer los &",predictpath);
 				system(command);
 			}
 		}
