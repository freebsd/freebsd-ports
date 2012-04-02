--- unix/ibus/mozc_engine.cc.orig	2012-04-02 08:17:52.706728426 +0900
+++ unix/ibus/mozc_engine.cc	2012-04-02 08:24:23.981727483 +0900
@@ -226,14 +226,14 @@
 
   COMPILE_ASSERT(sizeof(int64) > sizeof(guint), int64_guint_check);
   const int64 kInt32AbsMax =
-      abs(static_cast<int64>(numeric_limits<int32>::max()));
+      ::abs(static_cast<int64>(numeric_limits<int32>::max()));
   const int64 kInt32AbsMin =
-      abs(static_cast<int64>(numeric_limits<int32>::min()));
+      ::abs(static_cast<int64>(numeric_limits<int32>::min()));
   const int64 kInt32SafeAbsMax =
       min(kInt32AbsMax, kInt32AbsMin);
 
   const int64 diff = static_cast<int64>(from) - static_cast<int64>(to);
-  if (abs(diff) > kInt32SafeAbsMax) {
+  if (::abs(diff) > kInt32SafeAbsMax) {
     return false;
   }
 
@@ -1598,7 +1598,7 @@
       //     on size_t, not uint32.
       string selection_text;
       const uint32 selection_start = min(cursor_pos, anchor_pos);
-      const uint32 selection_length = abs(relative_selected_length);
+      const uint32 selection_length = ::abs(relative_selected_length);
       Util::SubString(surrounding_text,
                       selection_start,
                       selection_length,
