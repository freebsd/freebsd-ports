--- ./ocroscript/scripts/rec-tess-complete.lua.orig	2008-10-16 05:40:35.000000000 +0900
+++ ./ocroscript/scripts/rec-tess-complete.lua	2009-05-26 21:22:11.000000000 +0900
@@ -20,11 +20,20 @@
 -- Reviewer: 
 -- Primary Repository: 
 -- Web Sites: www.iupr.org, www.dfki.de, www.ocropus.org
+--
+-- Patch applied:
+-- http://code.google.com/p/ocropus/issues/detail?id=137
 
 
 require 'lib.util'
 require 'lib.headings'
 require 'lib.paragraphs'
+require 'lib.path'
+require 'lib.hocr'
+import_all(ocr)
+import_all(graphics)
+import_all(iulib)
+import_all(nustring)
 
 remove_hyphens = true
 
@@ -74,7 +83,7 @@
 -- RecognizedPage is a transport object of tesseract_recognize_blockwise().
 -- This function will convert it to a DOM.
 function convert_RecognizedPage_to_DOM(p, image_path, keep_char_boxes)
-    page_DOM = get_page_DOM(p, image_path)
+    page_DOM = hocr.get_page_DOM(p, image_path)
     for i = 0, p:linesCount() - 1 do
         local bbox = p:bbox(i)
         local text = nustring()
@@ -85,13 +94,12 @@
             bboxes = narray_to_table(r)
         end
         p:text(text, i)
-        line_DOM = get_line_DOM(bbox, text, bboxes, p)
+        line_DOM = hocr.get_line_DOM(bbox, text, bboxes, p)
         table.insert(page_DOM, line_DOM)
     end
     return page_DOM
 end
 
-
 function get_images_DOM(tiseg_image, html_path, images_dir, page_image)
     os.execute('mkdir -p "'..images_dir..'"')
     local rects = rectarray()
@@ -102,12 +110,11 @@
     local dom = {{tag = 'hr', size = '0'}}
     for i = 0, rects:length() - 1 do
         local src = images_dir .. ('/%04d.png'):format(i + 1)
-        local img_path = util.combine_paths(html_path, src)
         img = bytearray()
         r = rects:at(i)
         extract_subimage(img, page_image, r.x0, r.y0, r.x1, r.y1)
-        write_image_gray(img_path, img)
-        local props = {bbox = bbox_to_string(page_image, r)}
+        iulib.write_image_gray(src, img)
+        local props = {bbox = hocr.bbox_to_string(page_image, r)}
         local link = {tag = 'a', href=src}
         local width = r.x1 - r.x0
         local height = r.y1 -r.y0
@@ -119,7 +126,7 @@
            height = "200px"
         end
         local tag = {tag = 'img', src = src, width=width, height=height,
-                     class = 'ocr_image', title = hocr_properties_attribute(props)}
+                     class = 'ocr_image', title = hocr.properties_attribute(props)}
         table.insert(link, tag)
         table.insert(dom, link)
         table.insert(dom, '\n')
@@ -146,8 +153,8 @@
     get_nontext_mask(nontext_mask,tiseg_image)
     remove_masked_region(text_image,nontext_mask,clean_image)
     segmenter:segment(page_segmentation,text_image)
-    local p = RecognizedPage()
-    tesseract_recognize_blockwise(p, page_image, page_segmentation)
+    local p = tesseract.RecognizedPage()
+    tesseract.recognize_blockwise(p, page_image, page_segmentation)
     page_DOM = convert_RecognizedPage_to_DOM(p, pages:getFileName(), 
                                              option("charboxes"))
     page_DOM = detect_headings(page_DOM, page_image)
@@ -157,10 +164,10 @@
     table.insert(body_DOM, page_DOM)
 end
 --end
-doc_DOM = get_html_tag()
-table.insert(doc_DOM, get_head_tag())
+doc_DOM = hocr.get_html_tag()
+table.insert(doc_DOM, hocr.get_head_tag())
 table.insert(doc_DOM, '\n')
 table.insert(doc_DOM, body_DOM)
 file = io.open(output_file, 'w')
-dump_DOM(file, doc_DOM, html_preamble)
+hocr.dump(file, doc_DOM, html_preamble)
 file:close()
