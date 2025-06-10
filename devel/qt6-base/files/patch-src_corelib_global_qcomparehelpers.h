Suppress spurious zero as null pointer constant warnings which cause errors
in www/dooble due to -Werror being passed. This is the same problem as in
qcompare.h that upstream suppresses for GCC.

/usr/local/include/qt6/QtCore/qfloat16.h:209:5: error: zero as null pointer constant [-Werror,-Wzero-as-null-pointer-constant]
...
/usr/local/include/qt6/QtCore/qcomparehelpers.h:211:43: note: expanded from macro 'QT_DECLARE_ORDERING_HELPER_TEMPLATE'
  211 |     { return compareThreeWay(lhs, rhs) >= 0; }

--- src/corelib/global/qcomparehelpers.h.orig	2025-02-19 13:05:34 UTC
+++ src/corelib/global/qcomparehelpers.h
@@ -316,6 +316,7 @@ orderingFlagsFor(T t) noexcept
 
 #define QT_DECLARE_ORDERING_HELPER_TEMPLATE(OrderingType, LeftType, RightType, Constexpr, \
                                             Noexcept, ...) \
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant") \
     __VA_ARGS__ \
     friend Constexpr bool operator<(LeftType const &lhs, RightType const &rhs) Noexcept \
     { \
@@ -357,6 +358,7 @@ orderingFlagsFor(T t) noexcept
 // Helpers for reversed ordering, using the existing compareThreeWay() function.
 #define QT_DECLARE_REVERSED_ORDERING_HELPER_TEMPLATE(OrderingType, LeftType, RightType, Constexpr, \
                                                      Noexcept, ...) \
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant") \
     __VA_ARGS__ \
     friend Constexpr bool operator<(RightType const &lhs, LeftType const &rhs) Noexcept \
     { return is_gt(compareThreeWay(rhs, lhs)); } \
