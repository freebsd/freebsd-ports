--- document-portal/document-portal-fuse.c.orig	2022-12-12 22:43:34 UTC
+++ document-portal/document-portal-fuse.c
@@ -2065,7 +2065,7 @@ xdp_fuse_forget (fuse_req_t req,
 static void
 xdp_fuse_forget (fuse_req_t req,
                  fuse_ino_t ino,
-                 unsigned long nlookup)
+                 uint64_t nlookup)
 {
   forget_one (ino, nlookup);
   fuse_reply_none (req);
