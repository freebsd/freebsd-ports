--- modules/legacy/src/calibfilter.cpp.orig	2014-04-11 10:15:26 UTC
+++ modules/legacy/src/calibfilter.cpp
@@ -95,11 +95,8 @@ bool CvCalibFilter::SetEtalon( CvCalibEt
 
     Stop();
 
-    if (latestPoints != NULL)
-    {
-        for( i = 0; i < MAX_CAMERAS; i++ )
-            cvFree( latestPoints + i );
-    }
+    for( i = 0; i < MAX_CAMERAS; i++ )
+        cvFree( latestPoints + i );
 
     if( type == CV_CALIB_ETALON_USER || type != etalonType )
     {
@@ -529,64 +526,61 @@ void CvCalibFilter::DrawPoints( CvMat** 
         return;
     }
 
-    if( latestCounts )
+    for( i = 0; i < cameraCount; i++ )
     {
-        for( i = 0; i < cameraCount; i++ )
+        if( dstarr[i] && latestCounts[i] )
         {
-            if( dstarr[i] && latestCounts[i] )
-            {
-                CvMat dst_stub, *dst;
-                int count = 0;
-                bool found = false;
-                CvPoint2D32f* pts = 0;
+            CvMat dst_stub, *dst;
+            int count = 0;
+            bool found = false;
+            CvPoint2D32f* pts = 0;
 
-                GetLatestPoints( i, &pts, &count, &found );
+            GetLatestPoints( i, &pts, &count, &found );
 
-                dst = cvGetMat( dstarr[i], &dst_stub );
+            dst = cvGetMat( dstarr[i], &dst_stub );
 
-                static const CvScalar line_colors[] =
-                {
-                    {{0,0,255}},
-                    {{0,128,255}},
-                    {{0,200,200}},
-                    {{0,255,0}},
-                    {{200,200,0}},
-                    {{255,0,0}},
-                    {{255,0,255}}
-                };
+            static const CvScalar line_colors[] =
+            {
+                {{0,0,255}},
+                {{0,128,255}},
+                {{0,200,200}},
+                {{0,255,0}},
+                {{200,200,0}},
+                {{255,0,0}},
+                {{255,0,255}}
+            };
 
-                const int colorCount = sizeof(line_colors)/sizeof(line_colors[0]);
-                const int r = 4;
-                CvScalar color = line_colors[0];
-                CvPoint prev_pt = { 0, 0};
+            const int colorCount = sizeof(line_colors)/sizeof(line_colors[0]);
+            const int r = 4;
+            CvScalar color = line_colors[0];
+            CvPoint prev_pt = { 0, 0};
 
-                for( j = 0; j < count; j++ )
-                {
-                    CvPoint pt;
-                    pt.x = cvRound(pts[j].x);
-                    pt.y = cvRound(pts[j].y);
+            for( j = 0; j < count; j++ )
+            {
+                CvPoint pt;
+                pt.x = cvRound(pts[j].x);
+                pt.y = cvRound(pts[j].y);
 
-                    if( found )
-                    {
-                        if( etalonType == CV_CALIB_ETALON_CHESSBOARD )
-                            color = line_colors[(j/cvRound(etalonParams[0]))%colorCount];
-                        else
-                            color = CV_RGB(0,255,0);
+                if( found )
+                {
+                    if( etalonType == CV_CALIB_ETALON_CHESSBOARD )
+                        color = line_colors[(j/cvRound(etalonParams[0]))%colorCount];
+                    else
+                        color = CV_RGB(0,255,0);
 
-                        if( j != 0 )
-                            cvLine( dst, prev_pt, pt, color, 1, CV_AA );
-                    }
+                    if( j != 0 )
+                        cvLine( dst, prev_pt, pt, color, 1, CV_AA );
+                }
 
-                    cvLine( dst, cvPoint( pt.x - r, pt.y - r ),
-                            cvPoint( pt.x + r, pt.y + r ), color, 1, CV_AA );
+                cvLine( dst, cvPoint( pt.x - r, pt.y - r ),
+                        cvPoint( pt.x + r, pt.y + r ), color, 1, CV_AA );
 
-                    cvLine( dst, cvPoint( pt.x - r, pt.y + r),
-                            cvPoint( pt.x + r, pt.y - r), color, 1, CV_AA );
+                cvLine( dst, cvPoint( pt.x - r, pt.y + r),
+                        cvPoint( pt.x + r, pt.y - r), color, 1, CV_AA );
 
-                    cvCircle( dst, pt, r+1, color, 1, CV_AA );
+                cvCircle( dst, pt, r+1, color, 1, CV_AA );
 
-                    prev_pt = pt;
-                }
+                prev_pt = pt;
             }
         }
     }
