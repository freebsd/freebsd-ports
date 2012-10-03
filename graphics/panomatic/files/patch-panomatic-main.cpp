--- panomatic/main.cpp.orig	2008-03-10 20:19:09.000000000 +0000
+++ panomatic/main.cpp	2012-09-24 12:02:46.529117189 +0000
@@ -92,6 +92,7 @@
 		MyOutput my;
 		cmd.setOutput(&my);
 		
+		ValueArg<float> aArgScale("","scale", "Scale image with factor to detect keypoints    (default:0.5)\n", false, 0.5, "float");
 		SwitchArg aArgFullScale("","fullscale", "Uses full scale image to detect keypoints    (default:false)\n", false);
 		SwitchArg aArgSurfExtended("","surf128", "Uses extended SURF (128 descriptors)    (default:true)", true);
 		ValueArg<int> aArgSurfScoreThreshold("","surfscore", "SURF Detection score threshold    (default : 1000)\n", false, 1000, "int");
@@ -130,6 +131,7 @@
 		cmd.add(aArgSurfScoreThreshold);		
 		cmd.add(aArgSurfExtended);
 		cmd.add(aArgFullScale);
+		cmd.add(aArgScale);
 		
 		//cmd.add( aArgSurfExtended );
 
@@ -175,7 +177,8 @@
 		if (aArgSieve2Size.isSet())			ioPanoDetector.setSieve2Size(aArgSieve2Size.getValue());
 		if (aArgLinearMatch.isSet())		ioPanoDetector.setLinearMatch(aArgLinearMatch.getValue());
 		if (aArgLinearMatchLen.isSet())		ioPanoDetector.setLinearMatchLen(aArgLinearMatchLen.getValue());
-        if (aArgFullScale.isSet())          ioPanoDetector.setDownscale(false);
+        if (aArgFullScale.isSet())          ioPanoDetector.setScale(1.);
+        if (aArgScale.isSet())          ioPanoDetector.setScale(aArgScale.getValue());
             
 		if (aArgTest.isSet())				ioPanoDetector.setTest(aArgTest.getValue());
 		if (aArgCores.isSet())				ioPanoDetector.setCores(aArgCores.getValue());
