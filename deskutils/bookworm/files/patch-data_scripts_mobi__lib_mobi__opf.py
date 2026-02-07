--- data/scripts/mobi_lib/mobi_opf.py.orig	2021-08-16 04:25:19 UTC
+++ data/scripts/mobi_lib/mobi_opf.py
@@ -21,7 +21,7 @@ class OPFProcessor:
 
     def writeOPF(self, has_obfuscated_fonts=False):
         # write out the metadata as an OEB 1.0 OPF file
-        print "Write opf"
+        print("Write opf")
         metadata = self.metadata
 
         META_TAGS = ['Drm Server Id', 'Drm Commerce Id', 'Drm Ebookbase Book Id', 'ASIN', 'ThumbOffset', 'Fake Cover',
@@ -100,7 +100,7 @@ class OPFProcessor:
             imageNumber = int(metadata['CoverOffset'][0])
             self.covername = self.imgnames[imageNumber]
             if self.covername is None:
-                print "Error: Cover image %s was not recognized as a valid image" % imageNumber
+                print("Error: Cover image %s was not recognized as a valid image" % imageNumber)
             else:
                 if self.isK8:
                     data.append('<meta name="cover" content="cover_img" />\n')
@@ -126,7 +126,7 @@ class OPFProcessor:
             priceList = metadata['Price']
             currencyList = metadata['Currency']
             if len(priceList) != len(currencyList):
-                print "Error: found %s price entries, but %s currency entries."
+                print("Error: found %s price entries, but %s currency entries.")
             else:
                 for i in range(len(priceList)):
                     data.append('<SRP Currency="'+currencyList[i]+'">'+priceList[i]+'</SRP>\n')
@@ -137,7 +137,7 @@ class OPFProcessor:
             imageNumber = int(metadata['ThumbOffset'][0])
             imageName = self.imgnames[imageNumber]
             if imageName is None:
-                print "Error: Cover Thumbnail image %s was not recognized as a valid image" % imageNumber
+                print("Error: Cover Thumbnail image %s was not recognized as a valid image" % imageNumber)
             else:
                 if self.isK8:
                     data.append('<meta name="Cover ThumbNail Image" content="'+ 'Images/'+imageName+'" />\n')
