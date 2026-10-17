Description: Use range instead of the Python 2 xrange builtin, and write
  bytes to the binary output file instead of str.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/scripts/randfile.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/scripts/randfile.py
@@ -22,7 +22,7 @@ def main():
     parser.add_argument('-p', '--progress', help='write an "x" for every file completed and a "." for every %d bytes' % CHUNKSIZE, action='store_true')
     args = parser.parse_args()
                      
-    for i in xrange(args.num_files):
+    for i in range(args.num_files):
         bytesleft = args.num_bytes
         outputfname = args.output_file_prefix + "." + str(i)
 
@@ -35,7 +35,7 @@ def main():
         zs = [0]*CHUNKSIZE
         ts = [256]*CHUNKSIZE
         while bytesleft >= CHUNKSIZE:
-            f.write(''.join(map(chr, map(randrange, zs, ts))))
+            f.write(bytes(map(randrange, zs, ts)))
             bytesleft -= CHUNKSIZE
 
             if args.progress:
@@ -43,7 +43,7 @@ def main():
 
         zs = [0]*bytesleft
         ts = [256]*bytesleft
-        f.write(''.join(map(chr, map(randrange, zs, ts))))
+        f.write(bytes(map(randrange, zs, ts)))
 
         if args.progress:
             sys.stdout.write("x") ; sys.stdout.flush()
