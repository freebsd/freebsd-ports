Suppress spurious zero as null pointer constant warnings which cause errors
in www/dooble due to -Werror being passed. This is the same problem as in
qcompare.h that upstream suppresses for GCC.

/usr/local/include/qt6/QtCore/qfloat16.h:209:5: error: zero as null pointer constant [-Werror,-Wzero-as-null-pointer-constant]
...
/usr/local/include/qt6/QtCore/qcomparehelpers.h:211:43: note: expanded from macro 'QT_DECLARE_ORDERING_HELPER_TEMPLATE'
  211 |     { return compareThreeWay(lhs, rhs) >= 0; }

--- src/corelib/global/qcomparehelpers.h.orig	2024-09-16 09:24:52 UTC
+++ src/corelib/global/qcomparehelpers.h
@@ -197,6 +197,7 @@ template <typename In> constexpr auto to_Qt(In in) noe
     { return !comparesEqual(rhs, lhs); }
 
 #define QT_DECLARE_ORDERING_HELPER_TEMPLATE(OrderingType, LeftType, RightType, Constexpr) \
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant") \
     friend Constexpr bool operator<(LeftType const &lhs, RightType const &rhs) \
         noexcept(noexcept(compareThreeWay(lhs, rhs))) \
     { return compareThreeWay(lhs, rhs) < 0; } \
@@ -225,6 +226,7 @@ template <typename In> constexpr auto to_Qt(In in) noe
 
 // Helpers for reversed ordering, using the existing compareThreeWay() function.
 #define QT_DECLARE_REVERSED_ORDERING_HELPER_TEMPLATE(OrderingType, LeftType, RightType, Constexpr) \
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant") \
     friend Constexpr bool operator<(RightType const &lhs, LeftType const &rhs) \
         noexcept(noexcept(compareThreeWay(rhs, lhs))) \
     { return compareThreeWay(rhs, lhs) > 0; } \
