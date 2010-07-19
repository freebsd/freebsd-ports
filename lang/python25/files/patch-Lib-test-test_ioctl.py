--- Lib/test/test_ioctl.py.orig	2008-08-03 20:45:34.000000000 -0400
+++ Lib/test/test_ioctl.py	2010-06-24 13:26:52.000000000 -0400
@@ -44,21 +44,12 @@ class IoctlTests(unittest.TestCase):
             raise TestSkipped('pty module required')
         mfd, sfd = pty.openpty()
         try:
-            if termios.TIOCSWINSZ < 0:
-                set_winsz_opcode_maybe_neg = termios.TIOCSWINSZ
-                set_winsz_opcode_pos = termios.TIOCSWINSZ & 0xffffffffL
-            else:
-                set_winsz_opcode_pos = termios.TIOCSWINSZ
-                set_winsz_opcode_maybe_neg, = struct.unpack("i",
-                        struct.pack("I", termios.TIOCSWINSZ))
-
+            set_winsz_opcode = termios.TIOCSWINSZ
             # We're just testing that these calls do not raise exceptions.
             saved_winsz = fcntl.ioctl(mfd, termios.TIOCGWINSZ, "\0"*8)
             our_winsz = struct.pack("HHHH",80,25,0,0)
-            # test both with a positive and potentially negative ioctl code
-            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode_pos, our_winsz)
-            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode_maybe_neg, our_winsz)
-            fcntl.ioctl(mfd, set_winsz_opcode_maybe_neg, saved_winsz)
+            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode, our_winsz)
+            fcntl.ioctl(mfd, set_winsz_opcode, saved_winsz)
         finally:
             os.close(mfd)
             os.close(sfd)
