--- data/scripts/mobi_lib/mobi_unpack.py.orig	2021-08-16 04:42:50 UTC
+++ data/scripts/mobi_lib/mobi_unpack.py
@@ -256,7 +256,7 @@ class MobiHeader:
         self.header = self.sect.loadSection(self.start)
         self.records, = struct.unpack_from('>H', self.header, 0x8)
         self.length, self.type, self.codepage, self.unique_id, self.version = struct.unpack('>LLLLL', self.header[20:40])
-        print "Mobi Version: ", self.version
+        print("Mobi Version: ", self.version)
 
         # codec
         self.codec = 'windows-1252'
@@ -266,18 +266,18 @@ class MobiHeader:
         }
         if self.codepage in codec_map.keys():
             self.codec = codec_map[self.codepage]
-        print "Codec: ", self.codec
+        print("Codec: ", self.codec)
 
         # title
         toff, tlen = struct.unpack('>II', self.header[0x54:0x5c])
         tend = toff + tlen
         self.title=self.header[toff:tend]
-        print "Title: ", self.title
+        print("Title: ", self.title)
 
         # set up for decompression/unpacking
         compression, = struct.unpack_from('>H', self.header, 0x0)
         if compression == 0x4448:
-            print "Huffdic compression"
+            print("Huffdic compression")
             reader = HuffcdicReader()
             huffoff, huffnum = struct.unpack_from('>LL', self.header, 0x70)
             huffoff = huffoff + self.start
@@ -286,10 +286,10 @@ class MobiHeader:
                 reader.loadCdic(self.sect.loadSection(huffoff+i))
             self.unpack = reader.unpack
         elif compression == 2:
-            print "Palmdoc compression"
+            print("Palmdoc compression")
             self.unpack = PalmdocReader().unpack
         elif compression == 1:
-            print "No compression"
+            print("No compression")
             self.unpack = UncompressedReader().unpack
         else:
             raise unpackException('invalid compression type: 0x%4x' % compression)
@@ -376,14 +376,14 @@ class MobiHeader:
                 self.fdst += self.start
 
         if DEBUG:
-            print "firstaddl %0x" % self.firstaddl
-            print "ncxidx %0x" % self.ncxidx
-            print "exth flags %0x" % exth_flag
+            print("firstaddl %0x" % self.firstaddl)
+            print("ncxidx %0x" % self.ncxidx)
+            print("exth flags %0x" % exth_flag)
             if self.version == 8 or self.start != 0:
-                print "skelidx %0x" % self.skelidx
-                print "dividx %0x" % self.dividx
-                print "othidx %0x" % self.othidx
-                print "fdst %0x" % self.fdst
+                print("skelidx %0x" % self.skelidx)
+                print("dividx %0x" % self.dividx)
+                print("othidx %0x" % self.othidx)
+                print("fdst %0x" % self.fdst)
 
         # NOTE: See DumpMobiHeader.py for a complete set of header fields
 
@@ -464,7 +464,7 @@ class MobiHeader:
                         trailers += 1
                     flags = flags >> 1
         # get raw mobi markup languge
-        print "Unpack raw markup language"
+        print("Unpack raw markup language")
         dataList = []
         # offset = 0
         for i in xrange(1, self.records+1):
@@ -542,7 +542,7 @@ class MobiHeader:
             else:
                 metadata[name].append(value)
                 if DEBUG:
-                    print "multiple values: metadata[%s]=%s" % (name, metadata[name])
+                    print("multiple values: metadata[%s]=%s" % (name, metadata[name]))
         _length, num_items = struct.unpack('>LL', extheader[4:12])
         extheader = extheader[12:]
         pos = 0
@@ -564,12 +564,12 @@ class MobiHeader:
                     value, = struct.unpack('>L',content)
                     addValue(name, str(value))
                 else:
-                    print "Error: Value for %s has unexpected size of %s" % (name, size)
+                    print("Error: Value for %s has unexpected size of %s" % (name, size))
             elif id in id_map_hexstrings.keys():
                 name = id_map_hexstrings[id]
                 addValue(name, content.encode('hex'))
             else:
-                print "Warning: Unknown metadata with id %s found" % id
+                print("Warning: Unknown metadata with id %s found" % id)
                 name = str(id) + ' (hex)'
                 addValue(name, content.encode('hex'))
             pos += size
@@ -600,11 +600,11 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
     for mh in mhlst:
 
         if mh.isK8():
-            print "\n\nProcessing K8 format Ebook ..."
+            print("\n\nProcessing K8 format Ebook ...")
         elif mh.isPrintReplica():
-            print "\nProcessing PrintReplica (.azw4) format Ebook ..."
+            print("\nProcessing PrintReplica (.azw4) format Ebook ...")
         else:
-            print "\nProcessing Mobi format Ebook ..."
+            print("\nProcessing Mobi format Ebook ...")
 
         if DEBUG:
             # write out raw mobi header data
@@ -624,8 +624,8 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
         metadata['Codec'] = [mh.codec]
         metadata['UniqueID'] = [str(mh.unique_id)]
         if DEBUG:
-            print "MetaData from EXTH"
-            print metadata
+            print("MetaData from EXTH")
+            print(metadata)
 
         # save the raw markup language
         rawML = mh.getRawML()
@@ -643,12 +643,12 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
 
         # process additional sections that represent images, resources, fonts, and etc
         # build up a list of image names to use to postprocess the rawml
-        print "Unpacking images, resources, fonts, etc"
+        print("Unpacking images, resources, fonts, etc")
         firstaddl = mh.getfirstAddl()
         if DEBUG:
-            print "firstaddl is ", firstaddl
-            print "num_sections is ", sect.num_sections
-            print "K8Boundary is ", K8Boundary
+            print("firstaddl is ", firstaddl)
+            print("num_sections is ", sect.num_sections)
+            print("K8Boundary is ", K8Boundary)
         beg = firstaddl
         end = sect.num_sections
         if firstaddl < K8Boundary:
@@ -656,12 +656,12 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
         obfuscate_data = []
         for i in xrange(beg, end):
             if DEBUG:
-                print "Section is ", i
+                print("Section is ", i)
             data = sect.loadSection(i)
             type = data[0:4]
             if type in ["FLIS", "FCIS", "FDST", "DATP"]:
                 if DEBUG:
-                    print 'First 4 bytes: %s' % toHex(data[0:4])
+                    print('First 4 bytes: %s' % toHex(data[0:4]))
                     fname = "%05d" % (1+i-beg)
                     fname = type + fname
                     if mh.isK8():
@@ -669,13 +669,13 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
                     fname += '.dat'
                     outname= os.path.join(files.outdir, fname)
                     file(outname, 'wb').write(data)
-                    print "Skipping ", type, " section"
+                    print("Skipping ", type, " section")
                 imgnames.append(None)
                 continue
             elif type == "SRCS":
                 # The mobi file was created by kindlegen and contains a zip archive with all source files.
                 # Extract the archive and save it.
-                print "    Info: File contains kindlegen source archive, extracting as %s" % KINDLEGENSRC_FILENAME
+                print("    Info: File contains kindlegen source archive, extracting as %s" % KINDLEGENSRC_FILENAME)
                 srcname = os.path.join(files.outdir, KINDLEGENSRC_FILENAME)
                 file(srcname, 'wb').write(data[16:])
                 imgnames.append(None)
@@ -709,29 +709,29 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
                         adler32, = struct.unpack_from('>I', font_data, len(font_data) - 4)
                         font_data = zlib.decompress(font_data[2:-4], -wbits, usize)
                         if len(font_data) != usize:
-                            print 'Font Decompression Error: Uncompressed font size mismatch'
+                            print('Font Decompression Error: Uncompressed font size mismatch')
                         if False:
                             # For some reason these almost never match, probably Amazon has a
                             # buggy Adler32 implementation
                             sig = (zlib.adler32(font_data) & 0xffffffff)
                             if sig != adler32:
-                                print 'Font Decompression Error'
-                                print 'Adler checksum did not match. Stored: %d Calculated: %d' % (adler32, sig)
+                                print('Font Decompression Error')
+                                print('Adler checksum did not match. Stored: %d Calculated: %d' % (adler32, sig))
                     else:
-                        print "Error Decoding Font", str(err)
+                        print("Error Decoding Font", str(err))
                 hdr = font_data[0:4]
                 if hdr == '\0\1\0\0' or hdr == 'true' or hdr == 'ttcf':
                     ext = '.ttf'
                 elif hdr == 'OTTO':
                     ext = '.otf'
                 else:
-                    print "Warning: unknown font header %s" % hdr.encode('hex')
+                    print("Warning: unknown font header %s" % hdr.encode('hex'))
                     ext = '.dat'
                 fontname = "font%05d" % (1+i-beg)
                 fontname += ext
                 if (ext == '.ttf' or ext == '.otf') and (fflags & 0x0002):
                     obfuscate_data.append(fontname)
-                print "    extracting font: ", fontname
+                print("    extracting font: ", fontname)
                 outfnt = os.path.join(files.imgdir, fontname)
                 file(outfnt, 'wb').write(font_data)
                 imgnames.append(fontname)
@@ -746,7 +746,7 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
                 if DEBUG:
                     data = data[4:]
                     rescname = "resc%05d.dat" % (1+i-beg)
-                    print "    extracting resource: ", rescname
+                    print("    extracting resource: ", rescname)
                     outrsc = os.path.join(files.imgdir, rescname)
                     file(outrsc, 'wb').write(data)
                 imgnames.append(None)
@@ -754,7 +754,7 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
 
             if data == EOF_RECORD:
                 if DEBUG:
-                    print "Skip section %i as it contains the EOF record." % i
+                    print("Skip section %i as it contains the EOF record." % i)
                 imgnames.append(None)
                 continue
 
@@ -762,16 +762,16 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
             # Get the proper file extension
             imgtype = imghdr.what(None, data)
             if imgtype is None:
-                print "Warning: Section %s contains no image or an unknown image format" % i
+                print("Warning: Section %s contains no image or an unknown image format" % i)
                 imgnames.append(None)
                 if DEBUG:
-                    print 'First 4 bytes: %s' % toHex(data[0:4])
+                    print('First 4 bytes: %s' % toHex(data[0:4]))
                     fname = "unknown%05d.dat" % (1+i-beg)
                     outname= os.path.join(files.outdir, fname)
                     file(outname, 'wb').write(data)
             else:
                 imgname = "image%05d.%s" % (1+i-beg, imgtype)
-                print "    extracting image: ", imgname
+                print("    extracting image: ", imgname)
                 outimg = os.path.join(files.imgdir, imgname)
                 file(outimg, 'wb').write(data)
                 imgnames.append(imgname)
@@ -781,11 +781,11 @@ def process_all_mobi_headers(files, sect, mhlst, K8Bou
         # Process print replica book.
         if mh.isPrintReplica() and not k8only:
             filenames = []
-            print "Print Replica ebook detected"
+            print("Print Replica ebook detected")
             try:
                 mh.processPrintReplica(files)
-            except Exception, e:
-                print 'Error processing Print Replica: ' + str(e)
+            except Exception as e:
+                print('Error processing Print Replica: ' + str(e))
             filenames.append(['', files.getInputFileBasename() + '.pdf'])
             usedmap = {}
             for name in imgnames:
@@ -915,7 +915,7 @@ def unpackBook(infile, outdir):
 
     # process the PalmDoc database header and verify it is a mobi
     sect = Sectionizer(infile)
-    print "Palm DB type: ", sect.ident
+    print("Palm DB type: ", sect.ident)
     if sect.ident != 'BOOKMOBI' and sect.ident != 'TEXtREAd':
         raise unpackException('invalid file format')
 
@@ -945,7 +945,7 @@ def unpackBook(infile, outdir):
             if (after - before) == 8:
                 data = sect.loadSection(i)
                 if data == K8_BOUNDARY:
-                    print "Mobi Ebook uses the new K8 file format"
+                    print("Mobi Ebook uses the new K8 file format")
                     mh = MobiHeader(sect,i+1)
                     hasK8 = hasK8 or mh.isK8()
                     mhlst.append(mh)
@@ -1010,32 +1010,32 @@ class Mobi8Reader:
 
 
 def usage(progname):
-    print ""
-    print "Description:"
-    print "  Unpacks an unencrypted Kindle/MobiPocket ebook to html and images"
-    print "  or an unencrypted Kindle/Print Replica ebook to PDF and images"
-    print "  into the specified output folder."
-    print "Usage:"
-    print "  %s -r -s -d -h infile [outdir]" % progname
-    print "Options:"
-    print "    -r           write raw data to the output folder"
-    print "    -s           split combination mobis into mobi7 and mobi8 ebooks"
-    print "    -d           enable verbose debugging"
-    print "    -h           print this help message"
+    print("")
+    print("Description:")
+    print("  Unpacks an unencrypted Kindle/MobiPocket ebook to html and images")
+    print("  or an unencrypted Kindle/Print Replica ebook to PDF and images")
+    print("  into the specified output folder.")
+    print("Usage:")
+    print("  %s -r -s -d -h infile [outdir]" % progname)
+    print("Options:")
+    print("    -r           write raw data to the output folder")
+    print("    -s           split combination mobis into mobi7 and mobi8 ebooks")
+    print("    -d           enable verbose debugging")
+    print("    -h           print this help message")
 
 
 def main(argv=sys.argv):
     global DEBUG
     global WRITE_RAW_DATA
     global SPLIT_COMBO_MOBIS
-    print "MobiUnpack 0.47"
-    print "  Copyright (c) 2009 Charles M. Hannum <root@ihack.net>"
-    print "  With Additions by P. Durrant, K. Hendricks, S. Siebert, fandrieu, DiapDealer, nickredding."
+    print("MobiUnpack 0.47")
+    print("  Copyright (c) 2009 Charles M. Hannum <root@ihack.net>")
+    print("  With Additions by P. Durrant, K. Hendricks, S. Siebert, fandrieu, DiapDealer, nickredding.")
     progname = os.path.basename(argv[0])
     try:
         opts, args = getopt.getopt(sys.argv[1:], "hdrs")
-    except getopt.GetoptError, err:
-        print str(err)
+    except getopt.GetoptError as err:
+        print(str(err))
         usage(progname)
         sys.exit(2)
 
@@ -1062,16 +1062,16 @@ def main(argv=sys.argv):
 
     infileext = os.path.splitext(infile)[1].upper()
     if infileext not in ['.MOBI', '.PRC', '.AZW', '.AZW4']:
-        print "Error: first parameter must be a Kindle/Mobipocket ebook or a Kindle/Print Replica ebook."
+        print("Error: first parameter must be a Kindle/Mobipocket ebook or a Kindle/Print Replica ebook.")
         return 1
 
     try:
-        print 'Unpacking Book...'
+        print('Unpacking Book...')
         unpackBook(infile, outdir)
-        print 'Completed'
+        print('Completed')
 
-    except ValueError, e:
-        print "Error: %s" % e
+    except ValueError as e:
+        print("Error: %s" % e)
         return 1
 
     return 0
