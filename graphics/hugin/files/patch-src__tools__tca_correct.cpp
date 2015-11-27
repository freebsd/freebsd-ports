--- src/tools/tca_correct.cpp~	2015-10-31 11:10:44.000000000 +1100
+++ src/tools/tca_correct.cpp	2015-10-29 13:14:14.000000000 +1100
@@ -465,7 +465,7 @@
          << "    commandline arguments for fulla" << endl;
 }
 
-static hugin_omp::Lock lock;
+static hugin_omp::Lock slock;
 typedef std::multimap<double, vigra::Diff2D> MapPoints;
 
 template <class ImageType>
@@ -584,7 +584,7 @@
         }
         if (!cps.empty())
         {
-            hugin_omp::ScopedLock sl(lock);
+            hugin_omp::ScopedLock sl(slock);
             for (CPVector::const_iterator it = cps.begin(); it != cps.end(); ++it)
             {
                 pano.addCtrlPoint(*it);
