--- thirdparty/OGDF/src/coin/OsiClp/OsiClpSolverInterface.cpp.orig	2025-03-31 21:30:23 UTC
+++ thirdparty/OGDF/src/coin/OsiClp/OsiClpSolverInterface.cpp
@@ -1422,7 +1422,7 @@ OsiClpSolverInterface::setupForRepeatedUse(int senseOf
   if (stopPrinting) {
     CoinMessages * messagesPointer = modelPtr_->messagesPointer();
     // won't even build messages
-    messagesPointer->setDetailMessages(100,10000,reinterpret_cast<int *> (NULL));
+    messagesPointer->setDetailMessages(100,10000,static_cast<int *> (NULL));
   }
 #endif
 }
