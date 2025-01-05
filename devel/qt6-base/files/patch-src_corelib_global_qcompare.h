Also disable spurious zero as null pointer constant warnings for Clang which
are errors in www/dooble due to -Werror being passed.

--- src/corelib/global/qcompare.h.orig	2024-08-08 08:58:52 UTC
+++ src/corelib/global/qcompare.h
@@ -222,6 +222,7 @@ class partial_ordering (private)
 
     QT_WARNING_PUSH
     // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=100903
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant")
     QT_WARNING_DISABLE_GCC("-Wzero-as-null-pointer-constant")
     friend constexpr bool is_eq  (partial_ordering o) noexcept { return o == 0; }
     friend constexpr bool is_neq (partial_ordering o) noexcept { return o != 0; }
@@ -407,6 +408,7 @@ class weak_ordering (private)
 
     QT_WARNING_PUSH
     // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=100903
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant")
     QT_WARNING_DISABLE_GCC("-Wzero-as-null-pointer-constant")
     friend constexpr bool is_eq  (weak_ordering o) noexcept { return o == 0; }
     friend constexpr bool is_neq (weak_ordering o) noexcept { return o != 0; }
@@ -602,6 +604,7 @@ class strong_ordering (public)
 
     QT_WARNING_PUSH
     // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=100903
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant")
     QT_WARNING_DISABLE_GCC("-Wzero-as-null-pointer-constant")
     friend constexpr bool is_eq  (strong_ordering o) noexcept { return o == 0; }
     friend constexpr bool is_neq (strong_ordering o) noexcept { return o != 0; }
@@ -886,6 +889,7 @@ class QPartialOrdering (private)
 
     QT_WARNING_PUSH
     // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=100903
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant")
     QT_WARNING_DISABLE_GCC("-Wzero-as-null-pointer-constant")
     friend constexpr bool is_eq  (QPartialOrdering o) noexcept { return o == 0; }
     friend constexpr bool is_neq (QPartialOrdering o) noexcept { return o != 0; }
