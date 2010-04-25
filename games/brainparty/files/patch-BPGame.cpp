--- BPGame.cpp.orig	2010-03-11 03:15:34.000000000 +0300
+++ BPGame.cpp	2010-04-04 05:56:27.000000000 +0400
@@ -1295,7 +1295,7 @@
 	NumUnlockedGames = 0;
 
 	ifstream ifs;
-	ifs.open(".brainparty");
+	ifs.open((string(getenv("HOME")) + "/.brainparty").c_str());
 	
 	FirstRun = false;
 	
@@ -1426,7 +1426,7 @@
 
 void BPGame::SaveSettings() {
  	ofstream savefile;
- 	savefile.open(".brainparty");
+ 	savefile.open((string(getenv("HOME")) + "/.brainparty").c_str());
 	savefile << EnableSound << endl;
 	savefile << EnableMusic << endl;
 	savefile << endl;
@@ -2407,4 +2407,4 @@
 Colour* BPGame::ColorLerp(Colour* from, Colour* to, float amount) {
 	Colour* col = new Colour(Lerp(from->R, to->R, amount), Lerp(from->G, to->G, amount), Lerp(from->B, to->B, amount), Lerp(from->A, to->A, amount));
 	return col;
-}
\ No newline at end of file
+}
