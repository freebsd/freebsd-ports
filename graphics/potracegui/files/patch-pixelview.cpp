--- src/pixelview.cpp.orig	Tue Jan 10 02:18:12 2006
+++ src/pixelview.cpp	Tue Jan 10 11:12:14 2006
@@ -169,11 +169,11 @@
    internThresholdPercent = m_thresholdPercent;
    
    //initialize variables
-	unsigned int m_threshold = static_cast<unsigned int>(round(255*m_thresholdPercent/100));
+	unsigned int m_threshold = static_cast<unsigned int>(rint(255*m_thresholdPercent/100));
    
    //do the necessary recalculations
    if (  //if new thresholding is nesecarry. This is the case when
-        ( internThresholdingEnabled != m_thresholdingEnabled ) or //thresholding was enabled or disabled OR
+        ( internThresholdingEnabled != m_thresholdingEnabled ) || //thresholding was enabled or disabled OR
         ( internThreshold != m_threshold )                        //another threshold is given.
       )
    {
