--- data/scripts/mobi_lib/mobi_index.py.orig	2021-08-16 04:22:14 UTC
+++ data/scripts/mobi_lib/mobi_index.py
@@ -32,15 +32,15 @@ class MobiIndex:
             tagSectionStart = idxhdr['len']
             controlByteCount, tagTable = readTagSection(tagSectionStart, data)
             if DEBUG:
-                print "IndexCount is", IndexCount
-                print "TagTable: %s" % tagTable
+                print("IndexCount is", IndexCount)
+                print("TagTable: %s" % tagTable)
             for i in range(idx + 1, idx + 1 + IndexCount):
                 data = sect.loadSection(i)
                 hdrinfo = self.parseINDXHeader(data)
                 idxtPos = hdrinfo['start']
                 entryCount = hdrinfo['count']
                 if DEBUG:
-                    print idxtPos, entryCount
+                    print(idxtPos, entryCount)
                 # loop through to build up the IDXT position starts
                 idxPositions = []
                 for j in range(entryCount):
@@ -57,8 +57,8 @@ class MobiIndex:
                     tagMap = self.getTagMap(controlByteCount, tagTable, data, startPos+1+textLength, endPos)
                     outtbl.append([text, tagMap])
                     if DEBUG:
-                        print tagMap
-                        print text
+                        print(tagMap)
+                        print(text)
         return outtbl, ctoc_text
 
     def getTagMap(self, controlByteCount, tagTable, entryData, startPos, endPos):
@@ -118,19 +118,19 @@ class MobiIndex:
                     totalConsumed += consumed
                     values.append(data)
                 if totalConsumed != valueBytes:
-                    print "Error: Should consume %s bytes, but consumed %s" % (valueBytes, totalConsumed)
+                    print("Error: Should consume %s bytes, but consumed %s" % (valueBytes, totalConsumed))
             tagHashMap[tag] = values
         # Test that all bytes have been processed if endPos is given.
         if endPos is not None and dataStart != endPos:
             # The last entry might have some zero padding bytes, so complain only if non zero bytes are left.
             for char in entryData[dataStart:endPos]:
                 if char != chr(0x00):
-                    print "Warning: There are unprocessed index bytes left: %s" % toHex(entryData[dataStart:endPos])
+                    print("Warning: There are unprocessed index bytes left: %s" % toHex(entryData[dataStart:endPos]))
                     if DEBUG:
-                        print "controlByteCount: %s" % controlByteCount
-                        print "tagTable: %s" % tagTable
-                        print "data: %s" % toHex(entryData[startPos:endPos])
-                        print "tagHashMap: %s" % tagHashMap
+                        print("controlByteCount: %s" % controlByteCount)
+                        print("tagTable: %s" % tagTable)
+                        print("data: %s" % toHex(entryData[startPos:endPos]))
+                        print("tagHashMap: %s" % tagHashMap)
                     break
 
         return tagHashMap
@@ -154,7 +154,7 @@ class MobiIndex:
     def parseINDXHeader(self, data):
         "read INDX header"
         if not data[:4] == 'INDX':
-            print "Warning: index section is not INDX"
+            print("Warning: index section is not INDX")
             return False
         words = (
                 'len', 'nul1', 'type', 'gen', 'start', 'count', 'code',
@@ -166,10 +166,10 @@ class MobiIndex:
         for n in range(num):
             header[words[n]] = values[n]
         if DEBUG:
-            print "parsed INDX header:"
+            print("parsed INDX header:")
             for n in words:
-                print n, "%X" % header[n],
-            print
+                print(n, "%X" % header[n])
+            print("")
         return header
 
     def readCTOC(self, txtdata):
@@ -187,7 +187,7 @@ class MobiIndex:
             name = txtdata[offset:offset+ilen]
             offset += ilen
             if DEBUG:
-                print "name length is ", ilen
-                print idx_offs, name
+                print("name length is ", ilen)
+                print(idx_offs, name)
             ctoc_data[idx_offs] = name
         return ctoc_data
