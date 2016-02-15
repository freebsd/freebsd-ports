From ae453aa18b66af54e7ff716f4ccb33adca60afd4 Mon Sep 17 00:00:00 2001
From: wiredfool <eric-github@soroos.net>
Date: Tue, 2 Feb 2016 05:46:26 -0800
Subject: [PATCH] PCD decoder overruns the shuffle buffer, Fixes #568

---
 Tests/images/hopper.pcd | Bin 0 -> 788480 bytes
 Tests/test_file_pcd.py  |  18 ++++++++++++++++++
 libImaging/PcdDecode.c  |   4 ++--
 3 files changed, 20 insertions(+), 2 deletions(-)
 create mode 100644 Tests/images/hopper.pcd
 create mode 100644 Tests/test_file_pcd.py

--- libImaging/PcdDecode.c
+++ libImaging/PcdDecode.c
@@ -47,7 +47,7 @@ ImagingPcdDecode(Imaging im, ImagingCodecState state, UINT8* buf, int bytes)
 	    out[0] = ptr[x];
 	    out[1] = ptr[(x+4*state->xsize)/2];
 	    out[2] = ptr[(x+5*state->xsize)/2];
-	    out += 4;
+	    out += 3;
 	}
 
 	state->shuffle((UINT8*) im->image[state->y],
@@ -62,7 +62,7 @@ ImagingPcdDecode(Imaging im, ImagingCodecState state, UINT8* buf, int bytes)
 	    out[0] = ptr[x+state->xsize];
 	    out[1] = ptr[(x+4*state->xsize)/2];
 	    out[2] = ptr[(x+5*state->xsize)/2];
-	    out += 4;
+	    out += 3;
 	}
 
 	state->shuffle((UINT8*) im->image[state->y],
