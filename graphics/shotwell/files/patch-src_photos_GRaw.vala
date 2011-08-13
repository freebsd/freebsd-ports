$NetBSD: patch-src_photos_GRaw.vala,v 1.1 2011/07/31 17:37:01 gls Exp $

Fix importing with libraw 0.13.6 & 0.13.7
Taken from upstream: http://redmine.yorba.org/issues/3868

--- src/photos/GRaw.vala.orig	2011-05-26 23:43:17.000000000 +0000
+++ src/photos/GRaw.vala
@@ -110,8 +110,8 @@ public class ProcessedImage {
     }
     
     public ProcessedImage(LibRaw.Processor proc) throws Exception {
-        LibRaw.Result result;
-        image = proc.make_mem_image(out result);
+        LibRaw.Result result = LibRaw.Result.SUCCESS;
+        image = proc.make_mem_image(ref result);
         throw_exception("ProcessedImage", result);
         assert(image != null);
         
@@ -122,8 +122,8 @@ public class ProcessedImage {
     }
     
     public ProcessedImage.from_thumb(LibRaw.Processor proc) throws Exception {
-        LibRaw.Result result;
-        image = proc.make_mem_thumb(out result);
+        LibRaw.Result result = LibRaw.Result.SUCCESS;
+        image = proc.make_mem_thumb(ref result);
         throw_exception("ProcessedImage.from_thumb", result);
         assert(image != null);
         
@@ -280,7 +280,7 @@ private void throw_exception(string call
     if (result == LibRaw.Result.SUCCESS)
         return;
     else if (result > 0)
-        throw new Exception.SYSTEM_ERROR("System error %d: %s", (int) result, strerror(result));
+        throw new Exception.SYSTEM_ERROR("%s: System error %d: %s", caller, (int) result, strerror(result));
     
     string msg = "%s: %s".printf(caller, result.to_string());
     
