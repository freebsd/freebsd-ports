--- IlmImf/ImfHeader.cpp.orig	2018-08-10 01:34:58 UTC
+++ IlmImf/ImfHeader.cpp
@@ -785,30 +785,46 @@ Header::sanityCheck (bool isTiled, bool isMultipartFil
 	throw IEX_NAMESPACE::ArgExc ("Invalid data window in image header.");
     }
 
-    if (maxImageWidth > 0 &&
-        maxImageWidth < (dataWindow.max.x - dataWindow.min.x + 1))
+    int w = (dataWindow.max.x - dataWindow.min.x + 1);
+    if (maxImageWidth > 0 && maxImageWidth < w)
     {
 	THROW (IEX_NAMESPACE::ArgExc, "The width of the data window exceeds the "
 			    "maximum width of " << maxImageWidth << "pixels.");
     }
 
-    if (maxImageHeight > 0 &&
-	maxImageHeight < dataWindow.max.y - dataWindow.min.y + 1)
+    int h = (dataWindow.max.y - dataWindow.min.y + 1);
+    if (maxImageHeight > 0 && maxImageHeight < h)
     {
-	THROW (IEX_NAMESPACE::ArgExc, "The width of the data window exceeds the "
-			    "maximum width of " << maxImageHeight << "pixels.");
+	THROW (IEX_NAMESPACE::ArgExc, "The height of the data window exceeds the "
+			    "maximum height of " << maxImageHeight << "pixels.");
     }
 
-   // chunk table must be smaller than the maximum image area
-   // (only reachable for unknown types or damaged files: will have thrown earlier
-   //  for regular image types)
-   if( maxImageHeight>0 && maxImageWidth>0 && 
-       hasChunkCount() && chunkCount()>Int64(maxImageWidth)*Int64(maxImageHeight))
-   {
-       THROW (IEX_NAMESPACE::ArgExc, "chunkCount exceeds maximum area of "
-       << Int64(maxImageWidth)*Int64(maxImageHeight) << " pixels." );
+    // make sure to avoid simple math overflow for large offsets
+    // we know we're at a positive width because of checks above
+    long long bigW = static_cast<long long>( w );
+    long long absOffY = std::abs ( dataWindow.min.y );
+    long long absOffX = std::abs ( dataWindow.min.x );
+    long long offX = static_cast<long long>( INT_MAX ) - absOffX;
+    long long offsetCount = absOffY * bigW;
+    long long bytesLeftPerLine = static_cast<long long>( INT_MAX ) / bigW;
+    if (bytesLeftPerLine < absOffY || offX < offsetCount)
+    {
+	THROW (IEX_NAMESPACE::ArgExc, "Data window [ (" << dataWindow.min.x
+	       << ", " << dataWindow.min.x << ") - (" << dataWindow.max.x
+	       << ", " << dataWindow.max.x
+	       << ") ] offset / size will overflow pointer calculations");
+    }
+
+    // chunk table must be smaller than the maximum image area
+    // (only reachable for unknown types or damaged files: will have thrown earlier
+    //  for regular image types)
+    if( maxImageHeight>0 && maxImageWidth>0 && 
+	hasChunkCount() && chunkCount()>Int64(maxImageWidth)*Int64(maxImageHeight))
+    {
+	THROW (IEX_NAMESPACE::ArgExc, "chunkCount exceeds maximum area of "
+	       << Int64(maxImageWidth)*Int64(maxImageHeight) << " pixels." );
        
-   }
+    }
 
 
     //
