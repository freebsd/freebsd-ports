--- ./Doc/library/fcntl.rst.orig	2014-07-03 21:53:41.473098625 +1000
+++ ./Doc/library/fcntl.rst	2014-07-03 21:54:04.342833056 +1000
@@ -50,7 +50,6 @@ The module defines the following functio
    operations are typically defined in the library module :mod:`termios` and the
    argument handling is even more complicated.
 
-   The op parameter is limited to values that can fit in 32-bits.
    Additional constants of interest for use as the *op* argument can be
    found in the :mod:`termios` module, under the same names as used in
    the relevant C header files.
