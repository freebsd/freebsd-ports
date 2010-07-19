--- Doc/library/fcntl.rst.orig	2009-06-08 09:41:29.000000000 -0400
+++ Doc/library/fcntl.rst	2010-06-24 22:31:02.000000000 -0400
@@ -48,8 +48,6 @@
    This function is identical to the :func:`fcntl` function, except that the
    argument handling is even more complicated.
 
-   The op parameter is limited to values that can fit in 32-bits.
-
    The parameter *arg* can be one of an integer, absent (treated identically to the
    integer ``0``), an object supporting the read-only buffer interface (most likely
    a plain Python string) or an object supporting the read-write buffer interface.
