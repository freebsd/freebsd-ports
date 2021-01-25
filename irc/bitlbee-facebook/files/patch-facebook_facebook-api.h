From 49ea312d98b0578b9b2c1ff759e2cfa820a41f4d Mon Sep 17 00:00:00 2001
From: Frantisek Sumsal <frantisek@sumsal.cz>
Date: Wed, 20 Jan 2021 13:19:45 +0100
Subject: [PATCH] Bump the FB_ORCA_AGENT version once again (#208)

* Bump the FB_ORCA_AGENT version once again

Recently FB started returning ERROR_QUEUE_UNDERFLOW upon login (again).
Given the similarity to #180, the fix seemed quite straightforward, and
it indeed is - bumping the client version fixes the login issue.

Fixes: #207

diff --git a/facebook/facebook-api.h b/facebook/facebook-api.h
index 988dbf5..cecfa05 100644
--- facebook/facebook-api.h.orig
+++ facebook/facebook-api.h
@@ -117,7 +117,7 @@
  *
  */
 
-#define FB_ORCA_AGENT "[FBAN/Orca-Android;FBAV/192.0.0.31.101;FBBV/14477681]"
+#define FB_ORCA_AGENT "[FBAN/Orca-Android;FBAV/537.0.0.31.101;FBBV/14477681]"
 
 /**
  * FB_API_AGENT:
