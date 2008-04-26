--- panomatic/PanoDetectorLogic.cpp.orig	2008-03-10 20:17:33.000000000 +0000
+++ panomatic/PanoDetectorLogic.cpp	2008-03-11 08:52:59.000000000 +0000
@@ -98,25 +98,27 @@
     	
 	    int aNewImgWidth = aImageInfo.width();
 	    int aNewImgHeight = aImageInfo.height();
+ 	    float scale = iPanoDetector.getScale();
 
-	    if (iPanoDetector.getDownscale())
+ 	    if (scale != 1.)
 	    {
-		    aNewImgWidth >>= 1;
-		    aNewImgHeight >>= 1;
+ 		    aNewImgWidth = (int)(aNewImgWidth * scale);
+ 		    aNewImgHeight = (int)(aNewImgHeight * scale);
 	    }
 
 	    vigra::DImage aImageDouble(aNewImgWidth, aNewImgHeight);
 
 	    if(aImageInfo.isGrayscale())
 	    {
-		    if (iPanoDetector.getDownscale())
+ 		    if (scale != 1.)
 		    {
 			    TRACE_IMG("Load greyscale...");
 			    vigra::DImage aImageG(aImageInfo.width(), aImageInfo.height());
 			    importImage(aImageInfo, destImage(aImageG));
-			    vigra::resizeImageNoInterpolation(
+			    TRACE_IMG("Resize greyscale witn factor " << scale << " ...");
+ 			    vigra::resizeImageLinearInterpolation(
 				    aImageG.upperLeft(),
-				    aImageG.upperLeft() + vigra::Diff2D(aNewImgWidth * 2, aNewImgHeight * 2),
+ 				    aImageG.upperLeft() + vigra::Diff2D((int)(aNewImgWidth / scale), (int)(aNewImgHeight / scale)),
 				    vigra::DImage::Accessor(),
 				    aImageDouble.upperLeft(),
 				    aImageDouble.lowerRight(),
@@ -150,12 +152,12 @@
                 return false;
             }
 
-		    if (iPanoDetector.getDownscale())
+ 		    if (scale != 1.)
 		    {
-			    TRACE_IMG("Resize to greyscale double...");
-			    vigra::resizeImageNoInterpolation(
+			    TRACE_IMG("Resize to greyscale witn factor " << scale << " ...");
+ 			    vigra::resizeImageLinearInterpolation(
 					    aImageRGB.upperLeft(),
-					    aImageRGB.upperLeft() + vigra::Diff2D(aNewImgWidth * 2, aNewImgHeight * 2),
+ 					    aImageRGB.upperLeft() + vigra::Diff2D((int)(aNewImgWidth / scale), (int)(aNewImgHeight / scale)),
 					    vigra::RGBToGrayAccessor<vigra::RGBValue<double> >(),
 					    aImageDouble.upperLeft(),
 					    aImageDouble.lowerRight(),
@@ -390,7 +392,7 @@
 
 	if (iPanoDetector.getTest())
 		TestCode::drawRansacMatches(ioMatchData._i1_name, ioMatchData._i2_name, ioMatchData._matches, 
-									aRemovedMatches, aRansacFilter, iPanoDetector.getDownscale());
+									aRemovedMatches, aRansacFilter, iPanoDetector.getScale());
 
 	return true;
 
@@ -502,12 +504,13 @@
 		BOOST_FOREACH(PointMatchPtr& aPM, aM._matches)
 		{
 			aOut << "c n" << aN1 << " N" << aN2 << " ";  
-			if (getDownscale())
+			float scale = getScale();
+			if (scale != 1.)
 			{
-				aOut << "x" << 2.0 * aPM->_img1_x << " ";
-				aOut << "y" << 2.0 * aPM->_img1_y << " ";
-				aOut << "X" << 2.0 * aPM->_img2_x << " ";
-				aOut << "Y" << 2.0 * aPM->_img2_y << " ";
+				aOut << "x" << aPM->_img1_x / scale << " ";
+				aOut << "y" << aPM->_img1_y / scale << " ";
+				aOut << "X" << aPM->_img2_x / scale << " ";
+				aOut << "Y" << aPM->_img2_y / scale << " ";
 			}
 			else
 			{
