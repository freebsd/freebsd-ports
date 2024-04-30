Suppress spurious zero as null pointer constant warnings which cause errors
in www/dooble due to -Werror being passed. This is the same problem as in
qcompare.h that upstream suppresses for GCC.

/usr/local/include/qt6/QtCore/qfloat16.h:209:5: error: zero as null pointer constant [-Werror,-Wzero-as-null-pointer-constant]
...
/usr/local/include/qt6/QtCore/qcomparehelpers.h:211:43: note: expanded from macro 'QT_DECLARE_ORDERING_HELPER_TEMPLATE'
  211 |     { return compareThreeWay(lhs, rhs) >= 0; }

--- src/corelib/global/qcomparehelpers.h.orig	2024-01-22 10:20:09 UTC
+++ src/corelib/global/qcomparehelpers.h
@@ -197,6 +197,8 @@ template <typename In> constexpr auto to_Qt(In in) noe
     { return !comparesEqual(rhs, lhs); }
 
 #define QT_DECLARE_ORDERING_HELPER_TEMPLATE(OrderingType, LeftType, RightType, Constexpr) \
+    QT_WARNING_PUSH \
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant") \
     friend Constexpr bool operator<(LeftType const &lhs, RightType const &rhs) \
         noexcept(noexcept(compareThreeWay(lhs, rhs))) \
     { return compareThreeWay(lhs, rhs) < 0; } \
@@ -208,7 +210,8 @@ template <typename In> constexpr auto to_Qt(In in) noe
     { return compareThreeWay(lhs, rhs) <= 0; } \
     friend Constexpr bool operator>=(LeftType const &lhs, RightType const &rhs) \
         noexcept(noexcept(compareThreeWay(lhs, rhs))) \
-    { return compareThreeWay(lhs, rhs) >= 0; }
+    { return compareThreeWay(lhs, rhs) >= 0; } \
+    QT_WARNING_POP
 
 #define QT_DECLARE_ORDERING_HELPER_PARTIAL(LeftType, RightType, Constexpr) \
     QT_DECLARE_ORDERING_HELPER_TEMPLATE(Qt::partial_ordering, LeftType, RightType, Constexpr)
@@ -225,6 +228,8 @@ template <typename In> constexpr auto to_Qt(In in) noe
 
 // Helpers for reversed ordering, using the existing compareThreeWay() function.
 #define QT_DECLARE_REVERSED_ORDERING_HELPER_TEMPLATE(OrderingType, LeftType, RightType, Constexpr) \
+    QT_WARNING_PUSH \
+    QT_WARNING_DISABLE_CLANG("-Wzero-as-null-pointer-constant") \
     friend Constexpr bool operator<(RightType const &lhs, LeftType const &rhs) \
         noexcept(noexcept(compareThreeWay(rhs, lhs))) \
     { return compareThreeWay(rhs, lhs) > 0; } \
@@ -236,7 +241,8 @@ template <typename In> constexpr auto to_Qt(In in) noe
     { return compareThreeWay(rhs, lhs) >= 0; } \
     friend Constexpr bool operator>=(RightType const &lhs, LeftType const &rhs) \
         noexcept(noexcept(compareThreeWay(rhs, lhs))) \
-    { return compareThreeWay(rhs, lhs) <= 0; }
+    { return compareThreeWay(rhs, lhs) <= 0; } \
+    QT_WARNING_POP
 
 #define QT_DECLARE_REVERSED_ORDERING_HELPER_PARTIAL(LeftType, RightType, Constexpr) \
     QT_DECLARE_REVERSED_ORDERING_HELPER_TEMPLATE(Qt::partial_ordering, LeftType, RightType, Constexpr)
