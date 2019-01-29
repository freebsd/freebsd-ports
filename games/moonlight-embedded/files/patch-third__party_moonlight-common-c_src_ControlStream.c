From 8665d806978d2cba9c9040183a3686f4d87d402c Mon Sep 17 00:00:00 2001
From: Cameron Gutman <aicommander@gmail.com>
Date: Thu, 15 Nov 2018 12:55:22 -0800
Subject: [PATCH] Don't expect responses for ENet control messages to fix GFE
 3.16

---
 src/ControlStream.c | 12 +-----------
 1 file changed, 1 insertion(+), 11 deletions(-)

--- third_party/moonlight-common-c/src/ControlStream.c.orig	2018-08-11 15:28:10 UTC
+++ third_party/moonlight-common-c/src/ControlStream.c
@@ -378,10 +378,7 @@ static int sendMessageAndForget(short ptype, short pay
 }
 
 static int sendMessageAndDiscardReply(short ptype, short paylen, const void* payload) {
-    // Discard the response
     if (AppVersionQuad[0] >= 5) {
-        ENetEvent event;
-
         PltLockMutex(&enetMutex);
 
         if (!sendMessageEnet(ptype, paylen, payload)) {
@@ -389,14 +386,6 @@ static int sendMessageAndDiscardReply(short ptype, sho
             return 0;
         }
 
-        if (serviceEnetHost(client, &event, CONTROL_STREAM_TIMEOUT_SEC * 1000) <= 0 ||
-            event.type != ENET_EVENT_TYPE_RECEIVE) {
-            PltUnlockMutex(&enetMutex);
-            return 0;
-        }
-
-        enet_packet_destroy(event.packet);
-
         PltUnlockMutex(&enetMutex);
     }
     else {
@@ -406,6 +395,7 @@ static int sendMessageAndDiscardReply(short ptype, sho
             return 0;
         }
 
+        // Discard the response
         reply = readNvctlPacketTcp();
         if (reply == NULL) {
             return 0;
