--- frontends/CsoundAC/Counterpoint.cpp.orig	2015-04-25 19:06:23 UTC
+++ frontends/CsoundAC/Counterpoint.cpp
@@ -217,8 +217,8 @@ void Counterpoint::toCsoundScore(std::st
     delete uniform_real_generator;
   }
   int Counterpoint::ABS(int i) {if (i < 0) return(-i); else return(i);}
-  int Counterpoint::MIN(int a, int b) {if (a < b) return(a); else return(b);}
-  int Counterpoint::MAX(int a, int b) {if (a > b) return(a); else return(b);}
+  int Counterpoint::IMIN(int a, int b) {if (a < b) return(a); else return(b);}
+  int Counterpoint::IMAX(int a, int b) {if (a > b) return(a); else return(b);}
   void Counterpoint::ARRBLT(int *dest, int *source, int num) {int i; for (i=0;i<num;i++) dest[i]=source[i];} /* SAIL p51 */
 
   int Counterpoint::InMode(int Pitch, int Mode)
@@ -294,8 +294,8 @@ void Counterpoint::toCsoundScore(std::st
     for (i=1;i<Cn;i++)
       {
         pit=Us(i,v);
-        Minp=MIN(Minp,pit);
-        Maxp=MAX(Maxp,pit);
+        Minp=IMIN(Minp,pit);
+        Maxp=IMAX(Maxp,pit);
       }
     return(Maxp-Minp);
   }
@@ -316,7 +316,7 @@ void Counterpoint::toCsoundScore(std::st
   {
     int j,LowestPitch;
     LowestPitch=Cantus(Cn,v);
-    for (j=1;j<v;j++) LowestPitch=MIN(LowestPitch,Other(Cn,v,j));
+    for (j=1;j<v;j++) LowestPitch=IMIN(LowestPitch,Other(Cn,v,j));
     return(LowestPitch);
   }
 
@@ -993,7 +993,7 @@ void Counterpoint::toCsoundScore(std::st
     /* slightly frown upon leap back in the opposite direction */
     if ((Cn>2) && ((ASkip(MelInt)) && ((ASkip(LastMelInt)) && (!(SameDir)))))
       {
-        Val += (MAX(0,((ABS(MelInt)+ABS(LastMelInt))-8)));
+        Val += (IMAX(0,((ABS(MelInt)+ABS(LastMelInt))-8)));
         if ((Cn>3) && (ASkip(LastCp2-LastCp3))) Val += ThreeSkipsPenalty;
       }
 
@@ -1009,7 +1009,7 @@ void Counterpoint::toCsoundScore(std::st
             if ((Us(k,v)-Cantus(k,v))*(Us(k-1,v)-Cantus(k-1,v)) < 0) Cross++;
           }
       }
-    if (Cross > 0) Val += (MAX(0,((Cross-2)*3)));
+    if (Cross > 0) Val += (IMAX(0,((Cross-2)*3)));
 
     /* don't repeat note on upbeat */
     if (UpBeat(Cn,v) && (MelInt == Unison)) Val += RepetitionOnUpbeatPenalty;
@@ -1107,7 +1107,7 @@ void Counterpoint::toCsoundScore(std::st
           }
       }
     BestFitPenalty=CurrentPenalty+Penalty;
-    MaxPenalty=MIN(int(BestFitPenalty*PenaltyRatio),MaxPenalty);
+    MaxPenalty=IMIN(int(BestFitPenalty*PenaltyRatio),MaxPenalty);
     /*  AllDone=1; */
     Fits[2]=Fits[1]; Fits[1]=Fits[0]; Fits[0]=BestFitPenalty;
     for (v=1;v<=v1;v++)
@@ -1164,7 +1164,7 @@ void Counterpoint::toCsoundScore(std::st
                   {
                     for (i=1;i<=NumParts;i++) Pens[x-i]=Is[i];
                   }
-                else NewLim=MIN(NewLim,penalty);
+                else NewLim=IMIN(NewLim,penalty);
               }
           }
       }
@@ -1196,7 +1196,7 @@ void Counterpoint::toCsoundScore(std::st
     for (i=0;i<=NumParts;i++)
       {
         OurTime=Onset(VIndex(CurTime,i)+1,i);
-        if (OurTime != 0) NextTime=MIN(NextTime,OurTime);
+        if (OurTime != 0) NextTime=IMIN(NextTime,OurTime);
       }
     for (i=1;i<=NumParts;i++)
       {
@@ -1289,8 +1289,8 @@ void Counterpoint::toCsoundScore(std::st
   {
     int i;
     i=(int)(RANDOM(10.0));
-    if (CurRhy(i) >  CurRhy(MAX(1,(i-1)))) return(MAX(1,(i-1)));
-    if (CurRhy(i) <= CurRhy(MIN(9,(i+1)))) return(MIN(9,(i+1)));
+    if (CurRhy(i) >  CurRhy(IMAX(1,(i-1)))) return(IMAX(1,(i-1)));
+    if (CurRhy(i) <= CurRhy(IMIN(9,(i+1)))) return(IMIN(9,(i+1)));
     return(i);
   }
 
