$NetBSD: patch-vapi_libraw.vapi,v 1.1 2011/07/31 17:37:01 gls Exp $

Fix importing with libraw 0.13.6 & 0.13.7
Taken from upstream: http://redmine.yorba.org/issues/3868

--- vapi/libraw.vapi.orig	2011-05-26 23:43:17.000000000 +0000
+++ vapi/libraw.vapi
@@ -182,9 +182,9 @@ public class Processor {
     public unowned ImageSizes get_sizes() { return sizes; }
     public unowned Thumbnail get_thumbnail() { return thumbnail; }
     [CCode (cname="libraw_dcraw_make_mem_image")]
-    public ProcessedImage make_mem_image(out Result result);
+    public ProcessedImage make_mem_image(ref Result result);
     [CCode (cname="libraw_dcraw_make_mem_thumb")]
-    public ProcessedImage make_mem_thumb(out Result result);
+    public ProcessedImage make_mem_thumb(ref Result result);
     public Result open_buffer(uint8[] buffer);
     public Result open_file(string filename);
     [CCode (cname="libraw_dcraw_process")]
