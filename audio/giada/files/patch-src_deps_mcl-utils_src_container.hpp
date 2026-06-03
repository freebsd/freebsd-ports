-- Use std::views::zip+iota workaround for FreeBSD (clang 19 libc++ does not
-- implement std::views::enumerate from C++23).
-- https://github.com/llvm/llvm-project/issues/XXX

--- src/deps/mcl-utils/src/container.hpp.orig	2026-05-10 04:33:57 UTC
+++ src/deps/mcl-utils/src/container.hpp
@@ -120,7 +120,7 @@ auto enumerate(R&& r) noexcept
 template <std::ranges::range R>
 auto enumerate(R&& r) noexcept
 {
-#if MCL_OS_MAC
+#if MCL_OS_MAC || MCL_OS_FREEBSD
 	return std::views::zip(std::views::iota(std::size_t{0}), std::forward<R>(r));
 #else
 	return std::views::enumerate(std::forward<R>(r));
