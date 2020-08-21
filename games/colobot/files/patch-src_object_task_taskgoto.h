--- src/object/task/taskgoto.h.orig	2019-10-18 08:14:46 UTC
+++ src/object/task/taskgoto.h
@@ -147,7 +147,7 @@ class CTaskGoto : public CForegroundTask (protected)
     int             m_bmTotal = 0;      // number of points in m_bmPoints
     int             m_bmIndex = 0;      // index in m_bmPoints
     Math::Vector        m_bmPoints[MAXPOINTS+2];
-    char            m_bmIter[MAXPOINTS+2] = {};
+    signed char     m_bmIter[MAXPOINTS+2] = {};
     int             m_bmIterCounter = 0;
     CObject*        m_bmCargoObject = nullptr;
     float           m_bmFinalMove = 0.0f;  // final advance distance
