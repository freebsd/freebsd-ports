--- share/sphinx/ExtractRstFromSourceCPP.py.orig	2015-08-23 23:10:32 UTC
+++ share/sphinx/ExtractRstFromSourceCPP.py
@@ -146,7 +146,7 @@ class Comment:
         
         if buffer_lines[0] != '':
             buffer_lines.insert(0, '')
-        for x in xrange(0, len(buffer_lines)):
+        for x in range(0, len(buffer_lines)):
             buffer_lines[x] = "   %s" % buffer_lines[x]
         buffer_lines.append('')
         buffer = '\n'.join(buffer_lines)
@@ -181,7 +181,7 @@ def ExtractRst(string, fileh):
                     indent += 1
             # remove indent
             bufa = [buf_lines[0]]
-            for x in xrange(1, len(buf_lines)):
+            for x in range(1, len(buf_lines)):
                 bufa.append(buf_lines[x][indent:])
             buf = '\n'.join(bufa) + '\n'
             ##
@@ -229,7 +229,7 @@ if __name__ == "__main__":
             sys.exit(1)
         
         src = open(sys.argv[1]).read()
-        output = file(sys.argv[2], 'w')
+        output = open(sys.argv[2], 'w')
         ExtractRst(src, output)
         output.close()
         
