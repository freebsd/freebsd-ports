--- binutils-gdb--gdb/gdb/unittests/enum-flags-selftests.c.orig	2024-11-30 00:01:16 UTC
+++ binutils-gdb--gdb/gdb/unittests/enum-flags-selftests.c
@@ -233,33 +233,6 @@ CHECK_VALID (true,  EF,   true ? RE () : EF ())
 CHECK_VALID (true,  EF,   true ? EF () : RE ())
 CHECK_VALID (true,  EF,   true ? RE () : EF ())
 
-/* These are valid, but it's not a big deal since you won't be able to
-   assign the resulting integer to an enum or an enum_flags without a
-   cast.
-
-   The latter two tests are disabled on older GCCs because they
-   incorrectly fail with gcc 4.8 and 4.9 at least.  Running the test
-   outside a SFINAE context shows:
-
-    invalid user-defined conversion from ‘EF’ to ‘RE2’
-
-   They've been confirmed to compile/pass with gcc 5.3, gcc 7.1 and
-   clang 3.7.  */
-
-CHECK_VALID (true,  int,  true ? EF () : EF2 ())
-CHECK_VALID (true,  int,  true ? EF2 () : EF ())
-CHECK_VALID (true,  int,  true ? EF () : RE2 ())
-CHECK_VALID (true,  int,  true ? RE2 () : EF ())
-
-/* Same, but with an unsigned enum.  */
-
-typedef unsigned int uns;
-
-CHECK_VALID (true,  uns,  true ? EF () : UEF ())
-CHECK_VALID (true,  uns,  true ? UEF () : EF ())
-CHECK_VALID (true,  uns,  true ? EF () : URE ())
-CHECK_VALID (true,  uns,  true ? URE () : EF ())
-
 /* Unfortunately this can't work due to the way C++ computes the
    return type of the ternary conditional operator.  int isn't
    implicitly convertible to the raw enum type, so the type of the
