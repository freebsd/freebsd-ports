--- classes/tdisplay.cc.orig	2017-08-18 14:39:55 UTC
+++ classes/tdisplay.cc
@@ -22,6 +22,11 @@ same used in original Turbo Vision for compatibility p
 #define Uses_TVCodePage
 #include <tv.h>
 
+inline unsigned int absdiff(unsigned int a, unsigned int b)
+{
+    return (a>=b)?a-b:b-a;
+}
+
 // Remove me please!
 int TDisplay::dual_display=0;
 
@@ -381,10 +386,10 @@ Boolean TDisplay::searchClosestRes(TScreenResolution *
  if (firstXMatch!=-1)
    {// Return the closest y that match x
     i=indexMin=firstXMatch;
-    minDif=abs(res[i].y-y);
+    minDif=absdiff(res[i].y,y);
     while (++i<cant && res[i].x==x)
       {
-       dif=abs(res[i].y-y);
+       dif=absdiff(res[i].y,y);
        if (dif<minDif)
          {
           minDif=dif;
@@ -396,11 +401,11 @@ Boolean TDisplay::searchClosestRes(TScreenResolution *
    }
  // No x match, looks the one with minimum differences
  indexMin=0;
- minDif=abs(res[0].y-y)+abs(res[0].x-x);
+ minDif=absdiff(res[0].y,y)+absdiff(res[0].x,x);
  i=1;
  while (i<cant)
    {
-    dif=abs(res[i].y-y)+abs(res[i].x-x);
+    dif=absdiff(res[i].y,y)+absdiff(res[i].x,x);
     if (dif<minDif)
       {
        minDif=dif;
