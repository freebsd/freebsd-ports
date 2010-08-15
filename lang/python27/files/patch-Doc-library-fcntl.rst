--- Doc/library/fcntl.rst.orig	2010-08-14 16:19:09.194215129 +0800
+++ Doc/library/fcntl.rst	2010-08-14 16:19:36.999453016 +0800
@@ -50,8 +50,6 @@
    operations are typically defined in the library module :mod:`termios` and the
    argument handling is even more complicated.
 
-   The op parameter is limited to values that can fit in 32-bits.
-
    The parameter *arg* can be one of an integer, absent (treated identically to the
    integer ``0``), an object supporting the read-only buffer interface (most likely
    a plain Python string) or an object supporting the read-write buffer interface.
