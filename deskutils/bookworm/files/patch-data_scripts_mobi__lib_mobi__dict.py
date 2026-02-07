--- data/scripts/mobi_lib/mobi_dict.py.orig	2021-08-16 04:04:05 UTC
+++ data/scripts/mobi_lib/mobi_dict.py
@@ -27,37 +27,37 @@ class dictSupport:
 
         decodeInflection = True
         if metaOrthIndex != 0xFFFFFFFF:
-            print "Info: Document contains orthographic index, handle as dictionary"
+            print("Info: Document contains orthographic index, handle as dictionary")
             if metaInflIndex == 0xFFFFFFFF:
                 decodeInflection = False
             else:
                 metaInflIndexData = sect.loadSection(metaInflIndex)
                 metaIndexCount, = struct.unpack_from('>L', metaInflIndexData, 0x18)
                 if metaIndexCount != 1:
-                    print "Error: Dictionary contains multiple inflection index sections, which is not yet supported"
+                    print("Error: Dictionary contains multiple inflection index sections, which is not yet supported")
                     decodeInflection = False
                 inflIndexData = sect.loadSection(metaInflIndex + 1)
                 inflNameData = sect.loadSection(metaInflIndex + 1 + metaIndexCount)
                 tagSectionStart, = struct.unpack_from('>L', metaInflIndexData, 0x04)
                 inflectionControlByteCount, inflectionTagTable = readTagSection(tagSectionStart, metaInflIndexData)
                 if DEBUG_DICT:
-                    print "inflectionTagTable: %s" % inflectionTagTable
+                    print("inflectionTagTable: %s" % inflectionTagTable)
                 if self.hasTag(inflectionTagTable, 0x07):
-                    print "Error: Dictionary uses obsolete inflection rule scheme which is not yet supported"
+                    print("Error: Dictionary uses obsolete inflection rule scheme which is not yet supported")
                     decodeInflection = False
 
             data = sect.loadSection(metaOrthIndex)
             tagSectionStart, = struct.unpack_from('>L', data, 0x04)
             controlByteCount, tagTable = readTagSection(tagSectionStart, data)
             orthIndexCount, = struct.unpack_from('>L', data, 0x18)
-            print "orthIndexCount is", orthIndexCount
+            print("orthIndexCount is", orthIndexCount)
             if DEBUG_DICT:
-                print "orthTagTable: %s" % tagTable
+                print("orthTagTable: %s" % tagTable)
             hasEntryLength = self.hasTag(tagTable, 0x02)
             if not hasEntryLength:
-                print "Info: Index doesn't contain entry length tags"
+                print("Info: Index doesn't contain entry length tags")
 
-            print "Read dictionary index data"
+            print("Read dictionary index data")
             for i in range(metaOrthIndex + 1, metaOrthIndex + 1 + orthIndexCount):
                 data = sect.loadSection(i)
                 idxtPos, = struct.unpack_from('>L', data, 0x14)
@@ -145,10 +145,10 @@ class dictSupport:
 
             # Make sure that the required tags are available.
             if 0x05 not in tagMap:
-                print "Error: Required tag 0x05 not found in tagMap"
+                print("Error: Required tag 0x05 not found in tagMap")
                 return ""
             if 0x1a not in tagMap:
-                print "Error: Required tag 0x1a not found in tagMap"
+                print("Error: Required tag 0x1a not found in tagMap")
                 return ""
 
             result += "<idx:infl>"
@@ -230,7 +230,7 @@ class dictSupport:
                     totalConsumed += consumed
                     values.append(data)
                 if totalConsumed != valueBytes:
-                    print "Error: Should consume %s bytes, but consumed %s" % (valueBytes, totalConsumed)
+                    print("Error: Should consume %s bytes, but consumed %s" % (valueBytes, totalConsumed))
             tagHashMap[tag] = values
 
         # Test that all bytes have been processed if endPos is given.
@@ -238,12 +238,12 @@ class dictSupport:
             # The last entry might have some zero padding bytes, so complain only if non zero bytes are left.
             for char in entryData[dataStart:endPos]:
                 if char != chr(0x00):
-                    print "Warning: There are unprocessed index bytes left: %s" % toHex(entryData[dataStart:endPos])
+                    print("Warning: There are unprocessed index bytes left: %s" % toHex(entryData[dataStart:endPos]))
                     if DEBUG_DICT:
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
@@ -273,10 +273,10 @@ class dictSupport:
                 position -= offset
             elif byte > 0x13:
                 if mode == -1:
-                    print "Error: Unexpected first byte %i of inflection rule" % byte
+                    print("Error: Unexpected first byte %i of inflection rule" % byte)
                     return None
                 elif position == -1:
-                    print "Error: Unexpected first byte %i of inflection rule" % byte
+                    print("Error: Unexpected first byte %i of inflection rule" % byte)
                     return None
                 else:
                     if mode == 0x01:
@@ -292,19 +292,19 @@ class dictSupport:
                         deleted = byteArray.pop(position)
                         if deleted != char:
                             if DEBUG_DICT:
-                                print "0x03: %s %s %s %s" % (mainEntry, toHex(inflectionRuleData[start:end]), char, deleted)
-                            print "Error: Delete operation of inflection rule failed"
+                                print("0x03: %s %s %s %s" % (mainEntry, toHex(inflectionRuleData[start:end]), char, deleted))
+                            print("Error: Delete operation of inflection rule failed")
                             return None
                     elif mode == 0x04:
                         # Delete at word start
                         deleted = byteArray.pop(position)
                         if deleted != char:
                             if DEBUG_DICT:
-                                print "0x03: %s %s %s %s" % (mainEntry, toHex(inflectionRuleData[start:end]), char, deleted)
-                            print "Error: Delete operation of inflection rule failed"
+                                print("0x03: %s %s %s %s" % (mainEntry, toHex(inflectionRuleData[start:end]), char, deleted))
+                            print("Error: Delete operation of inflection rule failed")
                             return None
                     else:
-                        print "Error: Inflection rule mode %x is not implemented" % mode
+                        print("Error: Inflection rule mode %x is not implemented" % mode)
                         return None
             elif byte == 0x01:
                 # Insert at word start
@@ -327,7 +327,7 @@ class dictSupport:
                     position = 0
                 mode = byte
             else:
-                print "Error: Inflection rule mode %x is not implemented" % byte
+                print("Error: Inflection rule mode %x is not implemented" % byte)
                 return None
         return byteArray.tostring()
 
