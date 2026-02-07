--- data/scripts/mobi_lib/mobi_k8proc.py.orig	2021-08-16 04:24:52 UTC
+++ data/scripts/mobi_lib/mobi_k8proc.py
@@ -33,11 +33,11 @@ class K8Processor:
                 sections = header[0x0c:]
                 self.fdsttbl = struct.unpack_from('>%dL' % (num_sections*2), sections, 0)[::2] + (0xfffffff, )
             else:
-                print "Error: K8 Mobi with Missing FDST info"
+                print("Error: K8 Mobi with Missing FDST info")
         if self.DEBUG:
-            print "\nFDST Section Map:  %d entries" % len(self.fdsttbl)
+            print("\nFDST Section Map:  %d entries" % len(self.fdsttbl))
             for j in xrange(len(self.fdsttbl)):
-                print "  %d - %0x" % (j, self.fdsttbl[j])
+                print("  %d - %0x" % (j, self.fdsttbl[j]))
 
         # read/process skeleton index info to create the skeleton table
         skeltbl = []
@@ -50,10 +50,10 @@ class K8Processor:
                 fileptr += 1
         self.skeltbl = skeltbl
         if self.DEBUG:
-            print "\nSkel Table:  %d entries" % len(self.skeltbl)
-            print "table: filenum, skeleton name, div tbl record count, start position, length"
+            print("\nSkel Table:  %d entries" % len(self.skeltbl))
+            print("table: filenum, skeleton name, div tbl record count, start position, length")
             for j in xrange(len(self.skeltbl)):
-                print self.skeltbl[j]
+                print(self.skeltbl[j])
 
         # read/process the div index to create to <div> (and <p>) table
         divtbl = []
@@ -66,10 +66,10 @@ class K8Processor:
                 divtbl.append([int(text), ctocdata, tagMap[3][0], tagMap[4][0], tagMap[6][0], tagMap[6][1]])
         self.divtbl = divtbl
         if self.DEBUG:
-            print "\nDiv (Fragment) Table: %d entries" % len(self.divtbl)
-            print "table: file position, link id text, file num, sequence number, start position, length"
+            print("\nDiv (Fragment) Table: %d entries" % len(self.divtbl))
+            print("table: file position, link id text, file num, sequence number, start position, length")
             for j in xrange(len(self.divtbl)):
-                print self.divtbl[j]
+                print(self.divtbl[j])
 
         # read / process other index <guide> element of opf
         othtbl = []
@@ -88,10 +88,10 @@ class K8Processor:
                 othtbl.append([ref_type, ref_title, fileno])
         self.othtbl = othtbl
         if self.DEBUG:
-            print "\nOther (Guide) Table: %d entries" % len(self.othtbl)
-            print "table: ref_type, ref_title, divtbl entry number"
+            print("\nOther (Guide) Table: %d entries" % len(self.othtbl))
+            print("table: ref_type, ref_title, divtbl entry number")
             for j in xrange(len(self.othtbl)):
-                print self.othtbl[j]
+                print(self.othtbl[j])
 
 
     def buildParts(self, rawML):
@@ -103,7 +103,7 @@ class K8Processor:
             if end == 0xffffffff:
                 end = len(rawML)
                 if self.DEBUG:
-                    print "splitting rawml starting at %d and ending at %d into flow piece %d" % (start, end, j)
+                    print("splitting rawml starting at %d and ending at %d into flow piece %d" % (start, end, j))
             self.flows.append(rawML[start:end])
 
         # the first piece represents the xhtml text
@@ -114,7 +114,7 @@ class K8Processor:
         # *without* destroying any file position information needed for later href processing
         # and create final list of file separation start: stop points and etc in partinfo
         if self.DEBUG:
-            print "\nRebuilding flow piece 0: the main body of the ebook"
+            print("\nRebuilding flow piece 0: the main body of the ebook")
         self.parts = []
         self.partinfo = []
         divptr = 0
@@ -125,8 +125,8 @@ class K8Processor:
             for i in range(divcnt):
                 [insertpos, idtext, filenum, seqnum, startpos, length] = self.divtbl[divptr]
                 if self.DEBUG:
-                    print "    moving div/frag %d starting at %d of length %d" % (divptr, startpos, length)
-                    print "        inside of skeleton number %d at postion %d" %  (skelnum, insertpos)
+                    print("    moving div/frag %d starting at %d of length %d" % (divptr, startpos, length))
+                    print("        inside of skeleton number %d at postion %d" %  (skelnum, insertpos))
                 if i == 0:
                     aidtext = idtext[12:-2]
                     filename = 'part%04d.xhtml' % filenum
@@ -198,14 +198,14 @@ class K8Processor:
             self.flowinfo.append([type, format, dir, fname])
         
         if self.DEBUG:
-            print "\nFlow Map:  %d entries" % len(self.flowinfo)
+            print("\nFlow Map:  %d entries" % len(self.flowinfo))
             for fi in self.flowinfo:
-                print fi
-            print "\n"
+                print(fi)
+            print("\n")
 
-            print "\nXHTML File Part Position Information: %d entries" % len(self.partinfo)
+            print("\nXHTML File Part Position Information: %d entries" % len(self.partinfo))
             for pi in self.partinfo:
-                print pi
+                print(pi)
 
         if False:  # self.DEBUG:
             # dump all of the locations of the aid tags used in TEXT
@@ -214,12 +214,12 @@ class K8Processor:
             #    [^>]* means match any amount of chars except for  '>' char
             #    [^'"] match any amount of chars except for the quote character
             #    \s* means match any amount of whitespace
-            print "\npositions of all aid= pieces"
+            print("\npositions of all aid= pieces")
             id_pattern = re.compile(r'''<[^>]*\said\s*=\s*['"]([^'"]*)['"][^>]*>''',re.IGNORECASE)
             for m in re.finditer(id_pattern, rawML):
-                print "%0x %s %0x" % (m.start(), m.group(1), fromBase32(m.group(1)))
+                print("%0x %s %0x" % (m.start(), m.group(1), fromBase32(m.group(1))))
                 [filename, partnum, start, end] = self.getFileInfo(m.start())
-                print "   in  %d %0x %0x" % (partnum, start, end)
+                print("   in  %d %0x %0x" % (partnum, start, end))
 
         return
 
@@ -300,7 +300,7 @@ class K8Processor:
         n = len(idtbl)
         if n == 0:
             if self.DEBUG:
-                print "Found no id in the textblock, link must be to top of file"
+                print("Found no id in the textblock, link must be to top of file")
             return ''
         # if npos is before first id= inside a tag, return the first
         if npos < idtbl[0][0] :
@@ -315,7 +315,7 @@ class K8Processor:
                 tgt = r-1
                 break
         if self.DEBUG:
-            print pos, npos, idtbl[tgt]
+            print(pos, npos, idtbl[tgt])
         return idtbl[tgt][1]
 
 
