--- data/scripts/mobi_lib/mobi_ncx.py.orig	2021-08-16 04:25:11 UTC
+++ data/scripts/mobi_lib/mobi_ncx.py
@@ -34,8 +34,8 @@ class ncxExtract:
         if self.ncxidx != 0xffffffff:
             outtbl, ctoc_text = self.mi.getIndexData(self.ncxidx)
             if DEBUG_NCX:
-                print ctoc_text
-                print outtbl
+                print(ctoc_text)
+                print(outtbl)
             num = 0
             for [text, tagMap] in outtbl:
                 tmp = {
@@ -68,16 +68,16 @@ class ncxExtract:
                             tmp['kind'] = ctoc_text.get(fieldvalue, 'Unknown Kind')
                 indx_data.append(tmp)
                 if DEBUG_NCX:
-                    print "record number: ", num
-                    print "name: ", tmp['name'],
-                    print "position", tmp['pos']," length: ", tmp['len']
-                    print "text: ", tmp['text']
-                    print "kind: ", tmp['kind']
-                    print "heading level: ", tmp['hlvl']
-                    print "parent:", tmp['parent']
-                    print "first child: ",tmp['child1']," last child: ", tmp['childn']
-                    print "pos_fid is ", tmp['pos_fid']
-                    print "\n\n"
+                    print("record number: ", num)
+                    print("name: ", tmp['name'])
+                    print("position", tmp['pos']," length: ", tmp['len'])
+                    print("text: ", tmp['text'])
+                    print("kind: ", tmp['kind'])
+                    print("heading level: ", tmp['hlvl'])
+                    print("parent:", tmp['parent'])
+                    print("first child: ",tmp['child1']," last child: ", tmp['childn'])
+                    print("pos_fid is ", tmp['pos_fid'])
+                    print("\n\n")
                 num += 1
             num += 1
         self.indx_data = indx_data
@@ -118,10 +118,10 @@ class ncxExtract:
         #recursive part
         def recursINDX(max_lvl=0, num=0, lvl=0, start=-1, end=-1):
             if start>len(indx_data) or end>len(indx_data):
-                print "Warning: missing INDX child entries", start, end, len(indx_data)
+                print("Warning: missing INDX child entries", start, end, len(indx_data))
                 return ''
             if DEBUG_NCX:
-                print "recursINDX lvl %d from %d to %d" % (lvl, start, end)
+                print("recursINDX lvl %d from %d to %d" % (lvl, start, end))
             xml = ''
             if start <= 0:
                 start = 0
@@ -155,13 +155,13 @@ class ncxExtract:
         header = ncx_header % (ident, max_lvl + 1, title)
         ncx =  header + body + ncx_footer
         if not len(indx_data) == num:
-            print "Warning: different number of entries in NCX", len(indx_data), num
+            print("Warning: different number of entries in NCX", len(indx_data), num)
         return ncx
 
     def writeNCX(self, metadata):
         # build the xml
         self.isNCX = True
-        print "Write ncx"
+        print("Write ncx")
         htmlname = os.path.basename(self.files.outbase)
         htmlname += '.html'
         xml = self.buildNCX(htmlname, metadata['Title'][0], metadata['UniqueID'][0])
@@ -202,10 +202,10 @@ class ncxExtract:
         #recursive part
         def recursINDX(max_lvl=0, num=0, lvl=0, start=-1, end=-1):
             if start>len(indx_data) or end>len(indx_data):
-                print "Warning: missing INDX child entries", start, end, len(indx_data)
+                print("Warning: missing INDX child entries", start, end, len(indx_data))
                 return ''
             if DEBUG_NCX:
-                print "recursINDX lvl %d from %d to %d" % (lvl, start, end)
+                print("recursINDX lvl %d from %d to %d" % (lvl, start, end))
             xml = ''
             if start <= 0:
                 start = 0
@@ -244,13 +244,13 @@ class ncxExtract:
         header = ncx_header % (ident, max_lvl + 1, title)
         ncx =  header + body + ncx_footer
         if not len(indx_data) == num:
-            print "Warning: different number of entries in NCX", len(indx_data), num
+            print("Warning: different number of entries in NCX", len(indx_data), num)
         return ncx
 
     def writeK8NCX(self, ncx_data, metadata):
         # build the xml
         self.isNCX = True
-        print "Write K8 ncx"
+        print("Write K8 ncx")
         xml = self.buildK8NCX(ncx_data, metadata['Title'][0], metadata['UniqueID'][0])
         bname = 'toc.ncx'
         ncxname = os.path.join(self.files.k8oebps,bname)
