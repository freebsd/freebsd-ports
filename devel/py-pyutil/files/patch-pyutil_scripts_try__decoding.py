Description: Accept the str that argparse passes for --target, check decoded
  results against str instead of the Python 2 unicode builtin, print the
  decoded text instead of its encoded bytes repr, and skip codecs that do
  not decode bytes to text (LookupError) instead of stopping.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/scripts/try_decoding.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/scripts/try_decoding.py
@@ -63,7 +63,9 @@ output_encoding = get_output_encoding()
 argv_encoding = get_argv_encoding()
 
 def type_unicode(argstr):
-    return argstr.decode(argv_encoding)
+    if isinstance(argstr, bytes):
+        return argstr.decode(argv_encoding)
+    return argstr
 
 def main():
     parser = argparse.ArgumentParser(prog="try_decoding", description="Try decoding some bytes with all sorts of different codecs and print out any that decode.")
@@ -79,16 +81,16 @@ def main():
     for codec in listem():
         try:
             u = inb.decode(codec)
-        except (UnicodeDecodeError, IOError, TypeError, IndexError, UnicodeError, ValueError, zlib.error, binascii.Error):
+        except (LookupError, UnicodeDecodeError, IOError, TypeError, IndexError, UnicodeError, ValueError, zlib.error, binascii.Error):
             pass
         else:
-            if isinstance(u, unicode):
+            if isinstance(u, str):
                 if args.target:
                     if args.target != u:
                         continue
                 print("%19s" % codec)
                 print(':')
-                print(u.encode(output_encoding))
+                print(u)
             else:
                 if not args.accept_bytes:
                     continue
