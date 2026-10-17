Add 'noexcept' for std::__libcpp_verbose_abort signature (needed on 14.x and later).

Not needed on 13.x (now EOL) due to installed libc++ difference.
On 13.x, the base /usr/include files have a signature for
std::__libcpp_verbose_abort that does not specify noexcept (nor _NOEXCEPT).

On 14.x+, the base /usr/include signature has _NOEXCEPT (which is not a no-op
by default).

This file is only compiled if the FLANG option is on.

see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=296203

--- flang/runtime/io-api-minimal.cpp.orig	2025-01-14 09:41:02 UTC
+++ flang/runtime/io-api-minimal.cpp
@@ -150,7 +150,7 @@ bool IODEF(OutputLogical)(Cookie cookie, bool truth) {
 // Provide own definition for `std::__libcpp_verbose_abort` to avoid dependency
 // on the version provided by libc++.
 
-void std::__libcpp_verbose_abort(char const *format, ...) {
+void std::__libcpp_verbose_abort(char const *format, ...) _NOEXCEPT {
   va_list list;
   va_start(list, format);
   std::vfprintf(stderr, format, list);
