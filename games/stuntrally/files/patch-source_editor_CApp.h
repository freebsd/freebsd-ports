--- source/editor/CApp.h.orig	2019-11-27 17:44:26 UTC
+++ source/editor/CApp.h
@@ -137,7 +137,7 @@ class App : public BaseApp, (public)
 		float Size,Intens,Pow,Fq,NOf;
 		int Oct;  EBrShape shape;
 		float Filter,HSet;
-		char newLine;  Ogre::String name;
+		signed char newLine;  Ogre::String name;
 	};
 
 	const static int brSetsNum = 87;
