--- Lib/test/test_ioctl.py.orig	2010-08-14 16:20:34.137255285 +0800
+++ Lib/test/test_ioctl.py	2010-08-14 16:36:01.013654144 +0800
@@ -41,18 +41,9 @@
             raise unittest.SkipTest('pty module required')
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
             our_winsz = struct.pack("HHHH",80,25,0,0)
-            # test both with a positive and potentially negative ioctl code
-            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode_pos, our_winsz)
-            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode_maybe_neg, our_winsz)
+            new_winsz = fcntl.ioctl(mfd, set_winsz_opcode, our_winsz)
         finally:
             os.close(mfd)
             os.close(sfd)
