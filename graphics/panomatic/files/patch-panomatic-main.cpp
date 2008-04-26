--- panomatic/main.cpp.orig	2008-03-10 21:19:09.000000000 +0100
+++ panomatic/main.cpp	2008-04-26 20:26:30.000000000 +0200
@@ -92,6 +92,7 @@
 		MyOutput my;
 		cmd.setOutput(&my);
 		
+		ValueArg<float> aArgScale("","scale", "Scale image with factor to detect keypoints    (default:0.5)\n", false, 0.5, "float");
 		SwitchArg aArgFullScale("","fullscale", "Uses full scale image to detect keypoints    (default:false)\n", false);
 		SwitchArg aArgSurfExtended("","surf128", "Uses extended SURF (128 descriptors)    (default:true)", true);
 		ValueArg<int> aArgSurfScoreThreshold("","surfscore", "SURF Detection score threshold    (default : 1000)\n", false, 1000, "int");
@@ -175,8 +176,9 @@
 		if (aArgSieve2Size.isSet())			ioPanoDetector.setSieve2Size(aArgSieve2Size.getValue());
 		if (aArgLinearMatch.isSet())		ioPanoDetector.setLinearMatch(aArgLinearMatch.getValue());
 		if (aArgLinearMatchLen.isSet())		ioPanoDetector.setLinearMatchLen(aArgLinearMatchLen.getValue());
-        if (aArgFullScale.isSet())          ioPanoDetector.setDownscale(false);
-            
+        if (aArgFullScale.isSet())          ioPanoDetector.setScale(1.);
+            if (aArgScale.isSet())          ioPanoDetector.setScale(aArgScale.getValue());
+
 		if (aArgTest.isSet())				ioPanoDetector.setTest(aArgTest.getValue());
 		if (aArgCores.isSet())				ioPanoDetector.setCores(aArgCores.getValue());
 
