--- cpp/test/Glacier2/override/Client.cpp.orig	2015-08-02 15:07:07.945090996 +0200
+++ cpp/test/Glacier2/override/Client.cpp	2015-08-02 15:08:39.753584996 +0200
@@ -102,59 +102,105 @@
 
     {
         cout << "testing server request override... " << flush;
+        cout << __LINE__ << endl;
         Ice::Context ctx;
+        cout << __LINE__ << endl;
         ctx["serverOvrd"] = "test";
+        cout << __LINE__ << endl;
         for(int i = 0; i < 5; i++)
         {
+        cout << __LINE__ << endl;
             oneway->initiateCallback(onewayR, i, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallback(onewayR, i, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallback(onewayR, i, ctx);
+        cout << __LINE__ << endl;
             IceUtil::ThreadControl::sleep(IceUtil::Time::milliSeconds(100));
+        cout << __LINE__ << endl;
             test(callbackReceiverImpl->callbackOK(1, i) < 3);
+        cout << __LINE__ << endl;
         }
+        cout << __LINE__ << endl;
         oneway->initiateCallback(twowayR, 0);
+        cout << __LINE__ << endl;
         test(callbackReceiverImpl->callbackOK(1, 0) == 0);
+        cout << __LINE__ << endl;
 
         int count = 0;
         int nRetry = 0;
         do
         {
+        cout << __LINE__ << endl;
             callbackReceiverImpl->hold();
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallbackWithPayload(onewayR, ctx);
+        cout << __LINE__ << endl;
             oneway->initiateCallback(twowayR, 0);
+        cout << __LINE__ << endl;
             IceUtil::ThreadControl::sleep(IceUtil::Time::milliSeconds(200 + nRetry * 200));
+        cout << __LINE__ << endl;
             callbackReceiverImpl->activate();
+        cout << __LINE__ << endl;
             test(callbackReceiverImpl->callbackOK(1, 0) == 0);
+        cout << __LINE__ << endl;
             count = callbackReceiverImpl->callbackWithPayloadOK(0);
+        cout << __LINE__ << endl;
             callbackReceiverImpl->callbackWithPayloadOK(count);
+        cout << __LINE__ << endl;
         }
         while(count == 10 && nRetry++ < 10);
+        cout << __LINE__ << endl;
         test(count < 10);
+        cout << __LINE__ << endl;
 
         oneway->initiateCallbackWithPayload(twowayR);
+        cout << __LINE__ << endl;
         oneway->initiateCallbackWithPayload(twowayR);
+        cout << __LINE__ << endl;
         callbackReceiverImpl->hold();
+        cout << __LINE__ << endl;
         oneway->initiateCallbackWithPayload(twowayR);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallbackWithPayload(twowayR);
+        cout << __LINE__ << endl;
         IceUtil::ThreadControl::sleep(IceUtil::Time::milliSeconds(1000));
+        cout << __LINE__ << endl;
         callbackReceiverImpl->activate();
+        cout << __LINE__ << endl;
         test(callbackReceiverImpl->callbackWithPayloadOK(4) == 0);
+        cout << __LINE__ << endl;
         
         int remainingCallbacks = callbackReceiverImpl->callbackOK(1, 0);
+        cout << __LINE__ << endl;
         //
         // Occasionally, Glacier2 flushes in the middle of our 5
         // callbacks, so we get more than 1 callback
@@ -164,26 +210,43 @@
         // time to receive this (these) extra callback(s).
         //
         test(remainingCallbacks <= 4);
+        cout << __LINE__ << endl;
         if(remainingCallbacks > 0)
         {
+        cout << __LINE__ << endl;
             test(callbackReceiverImpl->callbackOK(remainingCallbacks, 0) == 0);
         }
+        cout << __LINE__ << endl;
         
         ctx["_fwd"] = "O";
+        cout << __LINE__ << endl;
 
         oneway->initiateCallbackWithPayload(twowayR);
+        cout << __LINE__ << endl;
         callbackReceiverImpl->hold();
+        cout << __LINE__ << endl;
         oneway->initiateCallbackWithPayload(twowayR);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallback(onewayR, 0, ctx);
+        cout << __LINE__ << endl;
         oneway->initiateCallbackWithPayload(twowayR);
+        cout << __LINE__ << endl;
         IceUtil::ThreadControl::sleep(IceUtil::Time::milliSeconds(200));
+        cout << __LINE__ << endl;
         callbackReceiverImpl->activate();
+        cout << __LINE__ << endl;
         test(callbackReceiverImpl->callbackWithPayloadOK(3) == 0);
+        cout << __LINE__ << endl;
         test(callbackReceiverImpl->callbackOK(1, 0) == 0);
+        cout << __LINE__ << endl;
 
         cout << "ok" << endl;
     }
