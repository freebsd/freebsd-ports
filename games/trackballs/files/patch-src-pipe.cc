--- src/pipe.cc.orig	Wed Feb 23 00:10:31 2005
+++ src/pipe.cc	Fri Jun  3 02:54:26 2005
@@ -96,8 +96,8 @@
 }
 void Pipe::computeBoundingBox() {
   for(int i=0;i<3;i++) {
-	boundingBox[0][i]=fmin(from[i]-radius,to[i]-radius)-position[i];
-	boundingBox[1][i]=fmax(from[i]+radius,to[i]+radius)-position[i];
+	boundingBox[0][i]=((from[i]-radius)>(to[i]-radius)?(to[i]-radius):(from[i]-radius))-position[i];
+	boundingBox[1][i]=((from[i]+radius)>(to[i]+radius)?(from[i]+radius):(to[i]+radius))-position[i];
   }
 }
 void Pipe::onRemove() {Animated::onRemove(); pipes->erase(this);}
