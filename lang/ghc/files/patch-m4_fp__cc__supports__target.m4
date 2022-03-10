--- m4/fp_cc_supports_target.m4.orig	2022-03-05 07:25:06 UTC
+++ m4/fp_cc_supports_target.m4
@@ -12,7 +12,7 @@ AC_DEFUN([FP_CC_SUPPORTS_TARGET],
    AC_REQUIRE([FPTOOLS_SET_PLATFORM_VARS])
    AC_MSG_CHECKING([whether $1 CC supports --target])
    echo 'int main() { return 0; }' > conftest.c
-   if $CC --target=$LlvmTarget -Werror conftest.c >& /dev/null ; then
+   if $CC --target=$LlvmTarget -Werror conftest.c 2>&1 /dev/null ; then
        CONF_CC_SUPPORTS_TARGET=YES
        AC_MSG_RESULT([yes])
    else
