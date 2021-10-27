--- data/scripts/mobi_lib/mobi_html.py.orig	2021-08-16 04:19:38 UTC
+++ data/scripts/mobi_lib/mobi_html.py
@@ -23,7 +23,7 @@ class HTMLProcessor:
     def findAnchors(self, rawtext, indx_data, positionMap):
         # process the raw text
         # find anchors...
-        print "Find link anchors"
+        print("Find link anchors")
         link_pattern = re.compile(r'''<[^<>]+filepos=['"]{0,1}(\d+)[^<>]*>''', re.IGNORECASE)
         # TEST NCX: merge in filepos from indx
         pos_links = [int(m.group(1)) for m in link_pattern.finditer(rawtext)]
@@ -38,7 +38,7 @@ class HTMLProcessor:
                 positionMap[position] = '<a id="filepos%d" />' % position
 
         # apply dictionary metadata and anchors
-        print "Insert data into html"
+        print("Insert data into html")
         pos = 0
         lastPos = len(rawtext)
         dataList = []
@@ -63,7 +63,7 @@ class HTMLProcessor:
         metadata = self.metadata
 
         # put in the hrefs
-        print "Insert hrefs into html"
+        print("Insert hrefs into html")
         # Two different regex search and replace routines.
         # Best results are with the second so far IMO (DiapDealer).
 
@@ -73,11 +73,11 @@ class HTMLProcessor:
         srctext = link_pattern.sub(r'''<a href="#filepos\1"\2>''', srctext)
 
         # remove empty anchors
-        print "Remove empty anchors from html"
+        print("Remove empty anchors from html")
         srctext = re.sub(r"<a/>",r"", srctext)
 
         # convert image references
-        print "Insert image references into html"
+        print("Insert image references into html")
         # split string into image tag pieces and other pieces
         image_pattern = re.compile(r'''(<img.*?>)''', re.IGNORECASE)
         image_index_pattern = re.compile(r'''recindex=['"]{0,1}([0-9]+)['"]{0,1}''', re.IGNORECASE)
@@ -91,7 +91,7 @@ class HTMLProcessor:
                 imageNumber = int(m.group(1))
                 imageName = imgnames[imageNumber-1]
                 if imageName is None:
-                    print "Error: Referenced image %s was not recognized as a valid image" % imageNumber
+                    print("Error: Referenced image %s was not recognized as a valid image" % imageNumber)
                 else:
                     replacement = 'src="images/' + imageName + '"'
                     tag = re.sub(image_index_pattern, replacement, tag, 1)
@@ -128,7 +128,7 @@ class XHTMLK8Processor:
         posfid_index_pattern = re.compile(r'''['"]kindle:pos:fid:([0-9|A-V]+):off:([0-9|A-V]+).*?["']''')
 
         parts = []
-        print "Building proper xhtml for each file"
+        print("Building proper xhtml for each file")
         for i in xrange(self.k8proc.getNumberOfParts()):
             part = self.k8proc.getPart(i)
             [partnum, dir, filename, beg, end, aidtext] = self.k8proc.getPartInfo(i)
@@ -227,7 +227,7 @@ class XHTMLK8Processor:
                             self.used[imageName] = 'used'
                             tag = re.sub(img_index_pattern, replacement, tag, 1)
                         else:
-                            print "Error: Referenced image %s was not recognized as a valid image in %s" % (imageNumber, tag)
+                            print("Error: Referenced image %s was not recognized as a valid image in %s" % (imageNumber, tag))
                     srcpieces[j] = tag
             flowpart = "".join(srcpieces)
 
@@ -246,13 +246,13 @@ class XHTMLK8Processor:
                         self.used[imageName] = 'used'
                         tag = re.sub(url_img_index_pattern, replacement, tag, 1)
                     else:
-                        print "Error: Referenced image %s was not recognized as a valid image in %s" % (imageNumber, tag)
+                        print("Error: Referenced image %s was not recognized as a valid image in %s" % (imageNumber, tag))
                 # process links to fonts
                 for m in re.finditer(font_index_pattern, tag):
                     fontNumber = fromBase32(m.group(1))
                     fontName = self.imgnames[fontNumber-1]
                     if fontName is None:
-                        print "Error: Referenced font %s was not recognized as a valid font in %s" % (fontNumber, tag)
+                        print("Error: Referenced font %s was not recognized as a valid font in %s" % (fontNumber, tag))
                     else:
                         replacement = '"../Fonts/' + fontName + '"'
                         tag = re.sub(font_index_pattern, replacement, tag, 1)
@@ -345,7 +345,7 @@ class XHTMLK8Processor:
                             self.used[imageName] = 'used'
                             tag = re.sub(img_index_pattern, replacement, tag, 1)
                         else:
-                            print "Error: Referenced image %s was not recognized as a valid image in %s" % (imageNumber, tag)
+                            print("Error: Referenced image %s was not recognized as a valid image in %s" % (imageNumber, tag))
                     srcpieces[j] = tag
             part = "".join(srcpieces)
             # store away modified version
