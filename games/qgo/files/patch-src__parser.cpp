--- src/parser.cpp.orig	Tue Dec 27 17:49:01 2005
+++ src/parser.cpp	Wed Jan 18 03:20:10 2006
@@ -1176,13 +1176,13 @@
 				{
 					aGameInfo->wname = element(line, 1, ":","(");
 					aGameInfo->wtime = (time1.toInt()==0 ? time2 : time1);
-					aGameInfo->wstones = (time1.toInt()==0 ?stones: "-1") ;
+					aGameInfo->wstones = (time1.toInt()==0 ? stones : QString("-1")) ;
 				}
 				else if (line.contains("(B)"))					
 				{
 					aGameInfo->bname = element(line, 1, ":","(");
 					aGameInfo->btime = (time1.toInt()==0 ? time2 : time1);
-					aGameInfo->bstones = (time1.toInt()==0 ? stones:"-1") ;
+					aGameInfo->bstones = (time1.toInt()==0 ? stones : QString("-1")) ;
 				}
 				else //never know with IGS ...
 					return IT_OTHER;
