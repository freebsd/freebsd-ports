diff -u -r1.2 -r1.3
--- utils/msgfmt.py	2004/12/07 13:42:35	1.2
+++ utils/msgfmt.py	2004/12/15 08:36:32	1.3
@@ -82,8 +82,8 @@
         koffsets += [l1, o1+keystart]
         voffsets += [l2, o2+valuestart]
     offsets = koffsets + voffsets
-    output = struct.pack("iiiiiii",
-                         0x950412de,        # Magic
+    output = struct.pack("Iiiiiii",
+                         0x950412deL,       # Magic
                          0,                 # Version
                          len(keys),         # # of entries
                          7*4,               # start of key index
