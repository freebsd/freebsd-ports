--- mscore/mscore/rendermidi.cpp.orig
+++ mscore/mscore/rendermidi.cpp
@@ -553,7 +553,7 @@
       int ns = nstaves();
       
 //ugly but clang cannot deal with 2/ while gcc4.6 can cope with 1/
-#ifdef Q_WS_MAC
+#ifdef __clang__
       QList<OttavaShiftSegment>* osl = new QList<OttavaShiftSegment>[ns];
 #else
       QList<OttavaShiftSegment> osl[ns];
@@ -576,7 +576,7 @@
       //    collect Dynamics
       //
 //ugly but clang cannot deal with 2/ while gcc4.6 can cope with 1/
-#ifdef Q_WS_MAC
+#ifdef __clang__
       VeloList *velo = new VeloList[ns];
 #else
       VeloList velo[ns];
@@ -675,7 +675,7 @@
                         }
                   }
             }
-#ifdef Q_WS_MAC      
+#ifdef __clang__
       delete[] velo;
       delete[] osl;
 #endif
