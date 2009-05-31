--- ./ocropus/rec-nhocr-0.3.lua.orig	2009-05-15 17:17:07.000000000 +0900
+++ ./ocropus/rec-nhocr-0.3.lua	2009-05-19 19:34:47.000000000 +0900
@@ -41,6 +41,6 @@
    for i = 1,regions:length()-1 do
       regions:extract(line_image,page_image,i,1)
       write_image_gray("line.pgm", line_image)
-      os.execute("/opt/nhocr/bin/nhocr -line -o - line.pgm ; rm line.pgm")
+      os.execute("nhocr -line -o - line.pgm ; rm line.pgm")
    end
 end
