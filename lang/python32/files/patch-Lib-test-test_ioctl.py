--- Lib/test/test_ioctl.py.orig	2009-08-13 04:51:18.000000000 -0400
+++ Lib/test/test_ioctl.py	2010-06-24 13:35:29.000000000 -0400
@@ -41,18 +41,9 @@ class IoctlTests(unittest.TestCase):
             raise unittest.SkipTest('pty module required')
         mfd, sfd = pty.openpty()
         try:
-            if termios.TIOCSWINSZ < 0:
-                set_winsz_opcode_maybe_neg = termios.TIOCSWINSZ
-                set_winsz_opcode_pos = termios.TIOCSWINSZ & 0xffffffff
-            else:
-                set_winsz_opcode_pos = termios.TIOCSWINSZ
-                set_winsz_opcode_maybe_neg, = struct.unpack("i",
-                        struct.pack("I", termios.TIOCSWINSZ))
-
+            set_winsz_opcode = termios.TIOCSWINSZ
             our_winsz = struct.pack("HHHH",80,25,0,0)
-            # test both with a positive and potentially negative ioctl code
-            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode_pos, our_winsz)
-            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode_maybe_neg, our_winsz)
+            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode, our_winsz)
         finally:
             os.close(mfd)
             os.close(sfd)
