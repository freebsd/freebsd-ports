--- src/tools/align_image_stack.cpp~	2015-10-31 11:10:56.000000000 +1100
+++ src/tools/align_image_stack.cpp	2015-10-29 13:09:52.000000000 +1100
@@ -121,7 +121,7 @@
 }
 
 typedef std::multimap<double, vigra::Diff2D> MapPoints;
-static hugin_omp::Lock lock;
+static hugin_omp::Lock slock;
 
 template <class ImageType>
 void FineTuneInterestPoints(Panorama& pano,
@@ -193,7 +193,7 @@
                        res.maxpos.y,
                        stereo ? ControlPoint::Y : ControlPoint::X_Y);
         {
-            hugin_omp::ScopedLock sl(lock);
+            hugin_omp::ScopedLock sl(slock);
             pano.addCtrlPoint(p);
         };
     }
