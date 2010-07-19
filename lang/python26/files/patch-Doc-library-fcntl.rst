--- Doc/library/fcntl.rst.orig	2009-10-27 10:29:22.000000000 -0400
+++ Doc/library/fcntl.rst	2010-06-24 22:28:28.000000000 -0400
@@ -50,8 +50,6 @@
    operations are typically defined in the library module :mod:`termios` and the
    argument handling is even more complicated.
 
-   The op parameter is limited to values that can fit in 32-bits.
-
    The parameter *arg* can be one of an integer, absent (treated identically to the
    integer ``0``), an object supporting the read-only buffer interface (most likely
    a plain Python string) or an object supporting the read-write buffer interface.
